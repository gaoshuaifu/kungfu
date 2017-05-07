/*
fct_request

+------------+------------+---------------+
| dateid     | sender_uid | recipient_uid |
+------------+------------+---------------+
| 2015-01-01 |          1 |             2 |
| 2015-01-01 |          1 |             4 |
| 2015-01-02 |          3 |             1 |
| 2015-01-03 |          4 |             5 |
+------------+------------+---------------+

fct_accept

+------------+--------------+------------+
| dateid     | accepter_uid | sender_uid |
+------------+--------------+------------+
| 2015-01-01 |            2 |          1 |
| 2015-01-02 |            4 |          1 |
| 2015-01-02 |            1 |          3 |
+------------+--------------+------------+

Rules:
1. You can only send a friend request to a person one time.
2. You cannot send a friend request to someone who has already sent you a friend request.
*/



/*
Q1: What percent of friend requests are accepted?
*/

SELECT SUM(CASE WHEN a.sender_uid IS NOT NULL THEN 1 ELSE 0 END) * 100.0 / SUM(1) AS perc
FROM
  fct_request r
  LEFT OUTER JOIN
  fct_accept a ON r.sender_uid = a.sender_uid AND r.recipient_uid = a.accepter_uid

/*
Q2: Who has the most friends?
*/
WITH user_num_friends AS (
  SELECT user_id, COUNT(1) AS num_friends
  FROM (
    SELECT accepter_uid AS user_id, sender_uid AS friend_user_id
    FROM fct_accept
    UNION ALL
    SELECT sender_uid AS user_id, accepter_uid AS friend_user_id
    FROM fct_accept
  ) a
)

SELECT user_id
FROM user_num_friends
WHERE num_friends IN (
  SELECT MAX(num_friends) AS max_num_friends
  FROM user_num_friends
)
