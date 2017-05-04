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
*/

SELECT
  '<DATEID>' AS ds
  COUNT(DISTINCT IF(ds = '<DATEID>', uid, NULL)) AS DAU,
  COUNT(DISTINCT IF(ds BETWEEN '<DATEID-29>' AND '<DATEID>', uid, NULL)) AS MAU
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

-- Keep track of users' date list and last active date at the end of each day
INSERT OVERWRITE TABLE user_date_list
PARTITION(ds='<DATEID>')
SELECT
  COALESCE(u.uid, a.uid) AS uid,
  IF(a.uid IS NULL, u.last_active, '<DATEID>') AS last_active,
  IF(a.uid IS NULL, u.date_list, CONCAT(a.date_list, '<DATE_ID>')) AS date_list
FROM user_date_list u
     FULL OUTER JOIN
     (
       SELECT DISTINCT uid
       FROM actions
       WHERE ds = '<DATEID>'
     ) a ON u.uid = a.uid
WHERE u.ds = '<DATEID-1>'

-- Now we can query for DAU and MAU as follows:
SELECT
  '<DATEID>' AS ds
  SUM(IF(last_active = '<DATEID>', 1, 0)) AS dau,
  SUM(IF(last_active BETWEEN '<DATEID-29>' AND '<DATEID>', 1, 0)) AS mau
FROM user_date_list
WHERE ds = '<DATEID>'

-- With users' date list, easily calculate retention rate and churn rate by UDF or Hive transformer
