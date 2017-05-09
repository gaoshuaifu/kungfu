/*
actions
+--------------+-----+----------+
|     date     | uid |  action  |
+--------------+-----+----------+
|  2015-01-01  |  1  |  'post'  |
|  2015-01-01  |  2  |  'like'  |
|  2015-01-01  |  2  |  'share' |
|  2015-01-02  |  1  |  'share' |
|  2015-01-02  |  3  |  'like'  |
+--------------+-----+----------+
*/

/*
Question 0:
Write a query to calculate the daily active users and the monthly active users
for a given date (e.g. 2015-01-01)

Example Output:

   +------+------+------+
   | date | dau  | mau  |
   +------+------+------|
   |  1/1 |   2  |  23  |
   +------+------+------+
*/

SELECT
  '<DATEID>' AS ds
  COUNT(DISTINCT IF(ds = '<DATEID>', uid, NULL)) AS dau,
  COUNT(DISTINCT IF(ds BETWEEN '<DATEID-29>' AND '<DATEID>', uid, NULL)) AS mau
FROM actions
WHERE ds BETWEEN '<DATEID-29>' AND '<DATEID>'

/*
Question 1:
These tables are huge (FB scale), perhaps trillions of rows per day.
What sort of indexing could you use to make the table more accessible?
*/
Partition on date
B-Tree index on date
Hash index on date

/*
Question 2:
This query examines 30 days of data and performs expensive DISTINCT operations.
As a result, this query may take many hours to complete.
How could you restructure the algorithm/query to avoid such an expensive lookup?
*/

-- Keep track of users', first action date, last action date and date list at the end of each day
INSERT OVERWRITE TABLE user_action_date_list
PARTITION(ds='<DATEID>')
SELECT
  COALESCE(a.uid, b.uid) AS uid,
  IF(a.uid IS NOT NULL, a.first_action_date, '<DATEID>') AS first_action_date,
  IF(b.uid IS NOT NULL, '<DATEID>', a.last_action_date) AS last_action_date,
  IF(b.uid IS NOT NULL, CONCAT(a.action_date_list, '<DATE_ID>'), u.action_date_list) AS action_date_list
FROM user_action_date_list a
     FULL OUTER JOIN
     (
       SELECT DISTINCT uid
       FROM actions
       WHERE ds = '<DATEID>'
     ) b ON a.uid = b.uid
WHERE a.ds = '<DATEID-1>'

-- Now we can query for DAU and MAU as follows:
SELECT
  '<DATEID>' AS ds
  SUM(IF(last_action_date = '<DATEID>', 1, 0)) AS dau,
  SUM(IF(last_action_date BETWEEN '<DATEID-29>' AND '<DATEID>', 1, 0)) AS mau
FROM user_action_date_list
WHERE ds = '<DATEID>'

-- With users' date list, easily calculate retention rate and churn rate by UDF or Hive transformer
