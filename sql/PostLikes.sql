/*
Table contains the number of likes a post has received on a given datestamp (ds):

post_likes
+--------------+------------+------------+
| ds           | post_id    | num_likes  |
+--------------+------------+------------+
| 2014-01-01   | 101        | 2          |
| 2014-01-01   | 102        | 7          |
| 2014-01-01   | 103        | 0          |
| 2014-01-01   | 104        | 9          |
| 2014-01-02   | 102        | 11         |
| 2014-01-02   | 103        | 2          |
| 2014-01-02   | 104        | 1          |
| 2014-01-02   | 105        | 7          |
+--------------+------------+-------------
*/

/*
Question 0:
Write a query to return the dates that have > 20 likes.

Example Output:
+------------+
| ds         |
+------------+
| 2014-01-02 |
+------------+
*/

SELECT ds
FROM post_likes
GROUP BY ds
HAVING SUM(num_likes) > 20

/*
Question 1:
Write a single query to get the count of the following for a ds
* total number of posts
* total number of posts with > 0 likes

Example Output:
    +-------------+-----------+-----------------+
    | ds          | cnt_posts | cnt_posts_likes |
    +-------------+-----------+-----------------+
    | 2014-01-01  |     4     |       3         |
    | 2014-01-02  |     4     |       4         |
    +-------------+-----------+-----------------+
*/

SELECT
  ds,
  COUNT(DISTINCT post_id) AS cnt_posts,
  COUNT(DISTINCT CASE WHEN num_likes > 0 post_id ELSE NULL END) AS cnt_posts_likes
  -- or   COUNT(DISTINCT IF(num_likes > 0, post_id, NULL)) AS cnt_posts_likes
  -- or   SUM(CASE WHEN num_likes > 0 THEN 1 ELSE 0 END) AS cnt_posts_likes
  -- or   SUM(IF(num_likes > 0, 1, 0)) AS cnt_posts_likes
FROM post_likes
GROUP BY ds

/*
Question 2:
Write a query to select the post_ids that had 0 likes on 2014-01-01 and > 0
likes on 2014-01-02.
E.g. it would return the post_id of 103.</b>
*/

-- solution 0
SELECT post_id
FROM post_likes
WHERE ds = '2014-01-01' AND num_likes = 0
INTERSECT
SELECT post_id
FROM post_likes
WHERE ds = '2014-01-02' AND num_likes > 0

-- solution 1
SELECT a.post_id
FROM post_likes a, post_likes b
WHERE
  a.post_id = b.post_id AND
  a.ds = '2014-01-01' AND
  a.num_likes = 0 AND
  b.ds = '2014-01-02' AND
  b.num_likes > 0

-- solution 2
SELECT a.post_id
FROM (
  SELECT post_id
  FROM post_likes
  WHERE ds = '2014-01-01' AND num_likes = 0
) a INNER JOIN (
  SELECT post_id
  FROM post_likes
  WHERE ds = '2014-01-02' AND num_likes > 0
) b on a.post_id == b.post_id

/*
Question 2 Followup:
In real life, data may be noisy or missing. Lets say we had some post_ids that
had NULL values in the num_likes column.

    +--------------+------------+------------+
    | ds           | post_id    | num_likes  |
    +--------------+------------+------------+
    | 2014-01-01   | 101        | 2          |
    | 2014-01-01   | 102        | 7          |
    | 2014-01-01   | 103        | 0          |
    | 2014-01-01   | 104        | 9          |
    | 2014-01-01   | 105        | NULL       |    <-- new row
    | 2014-01-02   | 102        | 11         |
    | 2014-01-02   | 103        | 2          |
    | 2014-01-02   | 104        | 1          |
    | 2014-01-02   | 105        | 7          |
    +--------------+------------+-------------


We want to treat these NULL values as zero. Modify the query to take this into
account so that we return the post_ids of 103 & 105:</i>
*/

SELECT a.post_id
FROM post_likes a, post_likes b
WHERE
  a.post_id = b.post_id AND
  a.ds = '2014-01-01' AND
  COALESCE(a.num_likes, 0) = 0 AND
  -- or   a.num_likes = 0 OR a.num_likes IS NULL
  b.ds = '2014-01-02' AND
  b.num_likes, 0 > 0

/*
Question 3:
Write a query to check that there is a unique post_id for each ds
(i.e. no duplicate post_ids on a given date).
Return 1 if the test passes; 0 if the test fails.</b>

Example Output:
    +-------------+-------------+
    | ds          | test_result |
    +-------------+-------------+
    | 2014-01-01  |     1       |
    | 2014-01-02  |     1       |
    +-------------+-------------+
*/

SELECT ds, IF(COUNT(1) = COUNT(DISTINCT post_id), 1, 0) AS test_result
FROM post_likes
GROUP BY ds

/*
Question 3 Followup:
Modify the query to rollup across all dates.
E.g. Return 1 if all tests pass on all dates; 0 if any test fails on any of the dates.</b>

Example Output:
    +---------------------+
    | overall_test_result |
    +---------------------+
    |          1          |
    +---------------------+
*/
SELECT IF(SUM(1) = SUM(test_result), 1, 0) as overall_test_result
FROM (
  SELECT ds, IF(COUNT(1) = COUNT(DISTINCT post_id), 1, 0) AS test_result
  FROM post_likes
  GROUP BY ds
) a
