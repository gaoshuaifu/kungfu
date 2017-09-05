/*
Data Model for Facebook Ads is below. An ad is 'globally active' only when all levels are active.
  Account(account_id, account_status)
  Campaign(compaign_id, compaign_status)
  Ad(ad_id, ad_status)
*/

/*
Question:
What is the time distribution that ads spend in a 'globally active' state?
*/

/*
Visualization:
  Daily Snapshot: A histogram with 24 bars. Each bar is the number of active ads for N hours.
  Historical Trend:  A line chart along dates. Each date has a fraction bar with 24 fractions.

Possibly have a dropdown box to break down by some dimensions, e.g. country, ad_budget_buckets (to separate the small and big spenders).
*/

/*
Data Modeling - Tables Provided.
-------------------------------------------------
 | state_change_log                              |   THIS IS A PROVIDED TABLE
 -------------------------------------------------
 | ds STRING                                     |   Datestamp (e.g. '2015-01-01')
 | ad_id BIGINT                                  |   Ad ID (primary key)
 | changes_today ARRAY<MAP<STRING,STRING,INT>>   |   Array of change-tuples (level, action, timestamp) associated with the ad_id that day.
 -------------------------------------------------

level describes the change level ('AD', 'CAMPAIGN', 'ACCOUNT')
action describes the state change ('PAUSED', 'UNPAUSED')
ts is the timestamp (sec) during the day that the state change was made (0 for 00:00:00, 86399 for 23:59:59)

---------------------------
| ad_details              |   THIS IS A PROVIDED TABLE
---------------------------
| ad_id BIGINT            |   Ad ID (primary key)
| adv_country STRING      |   The country of the advertiser for this ad_id
---------------------------
*/


/*
Data Modeling - Tables Generated.
---------------------------------------   -- STEP 1: compute active time spent for each ad_id
| ad_active_duration                  |
---------------------------------------
| ds STRING                           |
| ad_id BIGINT                        |
| country STRING                      |
| globally_active_time_spent_sec INT  |
| state_at_end_of_day ARRAY<INT>      |
---------------------------------------
*/

-- A UDF to calculate active time of an ad based on state_at_end_of_day of previous day and changes_today of current day.
def get_active_time(state_at_start_of_day, changes_today):
  state = state_at_start_of_day
  last_event_time = 0

  active_time = 0
  for change in changes_today:
    level = change[0]
    action = change[1]
    action_time = change[2]

    -- The ad is active because all levels are active
    if sum(state) == 3:
      active_time += action_time - last_event_time

    -- Set new states and last_event_time
    if level == 'AD' and action == 'PAUSE':
        state[0] = 0
    elif level == 'AD' and action == 'UNPAUSE':
        state[0] = 1
    elif level == 'CAMPAIGN' and action == 'PAUSE':
        state[1] = 0
    elif level == 'CAMPAIGN' and action == 'UNPAUSE':
        state[1] = 1
    elif level == 'ACCOUNT' and action == 'PAUSE':
        state[2] = 0
    elif level == 'ACCOUNT' and action == 'UNPAUSE':
        state[2] = 1

    last_event_time = action_time

  if sum(state) == 3:
    active_time += 86400 - last_event_time

  return active_time, state


-- USE the UDF above to calculate active time of an ad based on state_at_end_of_day of previous day and changes_today of current day.
INSERT OVERWRITE TABLE ad_active_duration
PARTITION(ds='<DATEID>')
SELECT
  a.ad_id,
  b.adv_country,
  get_active_time(c.state_at_end_of_day, a.changes_today)[0] AS globally_active_time_spent_sec,
  get_active_time(c.state_at_end_of_day, a.changes_today)[1] AS state_at_end_of_day
FROM
  state_change_log a
  LEFT OUTER JOIN
  ad_details b ON a.ad_id = b.ad_id
  LEFT OUTER JOIN
  ad_active_duration c on a.ad_id = c.ad_id
WHERE
  a.ds = '<DATEID>' AND
  c.ds = '<DATEID-1>'

/*
-----------------------------------    -- STEP 2: roll up results for dashboard
 | ad_active_duration_dashboard    |   -- may also choose to collapse this into just active_hours_bucket STRING and num_ads INT
 -----------------------------------
 | ds STRING                       |
 | country STRING                  |
 | num_ads_active_0_1_hours INT    |
 | num_ads_active_1_2_hours INT    |
 | num_ads_active_2_3_hours INT    |
 | num_ads_active_3_4_hours INT    |
 | ...                             |
 | num_ads_active_23_24_hours INT  |
 -----------------------------------
*/

INSERT OVERWRITE TABLE ad_active_duration_dashboard
PARTITION(ds='<DATEID>')
SELECT
  adv_country,
  SUM(IF(active_time_spent_sec > 0*60*60 AND active_time_spent_sec <= 1*60*60), 1, 0) AS num_ads_active_0_1_hours,
  SUM(IF(active_time_spent_sec > 1*60*60 AND active_time_spent_sec <= 2*60*60), 1, 0) AS num_ads_active_1_2_hours,
  SUM(IF(active_time_spent_sec > 2*60*60 AND active_time_spent_sec <= 3*60*60), 1, 0) AS num_ads_active_2_3_hours,
  ...
  SUM(IF(active_time_spent_sec > 23*60*60 0 AND active_time_spent_sec <= 24*60*60), 1, 0) AS num_ads_active_23_24_hours
FROM ad_active_duration
WHERE ds = '<DATEID>'
GROUP BY adv_country
