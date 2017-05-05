/*
Given a Table with dateid, Pageid, Number of Actions. Write a SQL that calculates
the total number of actions for a pageid and dateid in last 1,7 and 28 days.
One implementation is date or dateint and action each day.
Or just array with actions for each day etc.
*/

SELECT
  '<DATEID>' AS ds
  page_id,
  SUM(IF(ds = '<DATEID>', uid, NULL)) AS users_1d,
  SUM(IF(ds BETWEEN '<DATEID-6>' AND '<DATEID>', num_of_actions, 0)) AS users_7d,
  SUM(IF(ds BETWEEN '<DATEID-27>' AND '<DATEID>', num_of_actions, 0)) AS users_28d
FROM actions
WHERE ds BETWEEN '<DATEID-27>' AND '<DATEID>'
GROUP BY page_id
