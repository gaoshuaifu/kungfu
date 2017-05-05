/*
Rolling Visits - determine the number of people who have visited in the
last 7 days, every day. (What does every day mean??)
*/

SELECT
  '<DATEID>' AS ds
  COUNT(DISTINCT IF(ds = '<DATEID>', uid, NULL)) AS users_1d,
  COUNT(DISTINCT IF(ds BETWEEN '<DATEID-6>' AND '<DATEID>', uid, NULL)) AS users_7d
FROM actions
WHERE ds BETWEEN '<DATEID-6>' AND '<DATEID>'
