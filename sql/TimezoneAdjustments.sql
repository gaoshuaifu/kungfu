/*
Consider a table that logs the revenue made by ad in each hour. Here measure all our ad data in Pacific Standard Time (PST) and we had the following simple table:

ads
+---------------+-------+----------+---------+------------+
|    date_pst   | ad_id | hour_pst | revenue | acct_city  |
+---------------+-------+----------+---------+------------+
| 2015-01-02    |  1    |   1      |  10     | 'LA'       |
| 2015-01-02    |  1    |  13      |  20     | 'LA'       |
| 2015-01-02    |  2    |  12      |  30     | 'Paris'    |
| 2015-01-02    |  2    |  20      |  10     | 'Paris'    |
| 2015-01-02    |  3    |   6      |   0     | 'Honolulu' |
| 2015-01-02    |  3    |   1      |  10     | 'Honolulu' |
+---------------+-------+----------+---------+------------+
timezone
+------------+------------+
| acct_city  | pst_offset |
+------------+------------+
| 'LA'       |    0       |
| 'Paris'    |    9       |
| 'Honolulu' |   -2       |
+------------+------------+
*/

/*
Write a query to get the revenue made for each ad_id and for each date -- in the account's timezone
*/
SELECT
  CASE
    WHEN date_pst + pst_offset > 23 THEN '<DATEID+1>'
    WHEN date_pst + pst_offset < 0 THEN '<DATEID-1>'
    ELSE '<DATEID-1>'
  END AS date_local,
  ad_id,
  SUM(revenue) AS revenue
FROM
  ads a
  INNER JOIN
  timezone t on a.acct_city = t.acct_city
WHERE a.date_pst = '<DATEID>'
GROUP BY 1, 2
