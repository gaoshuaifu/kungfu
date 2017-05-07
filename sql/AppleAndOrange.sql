/*
fct_sales

+------------+--------+------+
| dateid     | fruit  | sold |
+------------+--------+------+
| 2015-01-01 | Apple  |   31 |
| 2015-01-01 | Orange |   19 |
| 2015-01-02 | Apple  |   37 |
| 2015-01-02 | Orange |   26 |
| 2015-01-03 | Apple  |   21 |
| 2015-01-03 | Orange |   21 |
| 2015-01-04 | Apple  |   35 |
| 2015-01-04 | Orange |   27 |
+------------+--------+------+

*/

/*
Q1: What is the difference between Apples and Oranges sold each day?

Output:
+------------+------+
| dateid     | sold |
+------------+------+
| 2015-01-01 |   12 |
| 2015-01-02 |   11 |
| 2015-01-03 |    0 |
| 2015-01-04 |    8 |
+------------+------+
*/

SELECT
  dateid,
  SUM(
      CASE
        WHEN fruit = 'Apple' THEN sold
        WHEN fruit = 'Orange' THEN -sold
        ELSE 0
      END
  ) AS diff
FROM fct_sales
GROUP BY dateid
