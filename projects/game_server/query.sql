/*
The number of users:
Result: 21,910,791
*/
SELECT COUNT(DISTINCT user_id) AS num_of_users
FROM users

/*
The number of users of each server.
*/
SELECT server_id, COUNT(1) as num_of_users
FROM users
GROUP BY server_id
ORDER BY server_id

/*
The number of users with appsflyer device.
Result: 7,322,958
*/
SELECT COUNT(DISTINCT user_id) AS num_of_users
FROM user_to_appsflyer
WHERE user_id != -1

/*
The number of users with multiple appsflyer devices
Result: 0
*/
SELECT COUNT(1)
FROM (
  SELECT user_id, COUNT(DISTINCT appsflyer_device_id) AS num_appsflyer_devices
  FROM user_to_appsflyer
  WHERE user_id != -1
  GROUP BY user_id
  HAVING num_appsflyer_devices > 1
) a

/*
The number of appsflyer devices.
Result: 6,215,927
*/
SELECT COUNT(DISTINCT appsflyer_device_id) AS num_of_appsflyer_device
FROM user_to_appsflyer
WHERE user_id != -1

/*
The number of appsflyer devices with multiple users.
Result: 265,647
*/
SELECT COUNT(1) AS num_of_appsflyer_device_with_multiple_users
FROM (
  SELECT appsflyer_device_id, COUNT(DISTINCT user_id) AS num_users
  FROM user_to_appsflyer
  WHERE user_id != -1
  GROUP BY appsflyer_device_id
  HAVING num_users > 1
) a

/*
Check if server id from users table and user_to_appsflyer table match each other.
+---------+------------------+----------------------+
| total   | server_id_match  | server_id_not_match  |
+---------+------------------+----------------------+
| 7323195 |          7073250 |               249945 |
+---------+------------------+----------------------+
*/
SELECT
  COUNT(1) AS total,
  SUM(CASE WHEN u.server_id = u2a.server_id THEN 1 ELSE 0 END) AS server_id_matche,
  SUM(CASE WHEN u.server_id != u2a.server_id THEN 1 ELSE 0 END) AS server_id_not_matche
FROM users u INNER JOIN user_to_appsflyer u2a on u.user_id = u2a.user_id
WHERE u2a.user_id != -1;

/*
Check if country_code from user_to_appsflyer table and appsflyer_payments table match each other.
+----------+---------------------+-------------------------+
| total    | country_code_matche | country_code_not_matche |
+----------+---------------------+-------------------------+
| 44541352 |            20783148 |                  670041 |
+----------+---------------------+-------------------------+
*/
SELECT
  COUNT(1) AS total,
  SUM(CASE WHEN u2a.country_code = p.country_code THEN 1 ELSE 0 END) AS country_code_matche,
  SUM(CASE WHEN u2a.country_code != p.country_code THEN 1 ELSE 0 END) AS country_code_not_matche
FROM user_to_appsflyer u2a INNER JOIN appsflyer_payments p on u2a.appsflyer_device_id = p.appsflyer_device_id
WHERE u2a.user_id != -1;

/*
Join four tables to get a denormalized table.
*/
CREATE TABLE game_server_denorm
SELECT
  u.user_id,
  COALESCE(u.server_id, u2a.server_id) AS server_id,
  u2a.appsflyer_device_id,
  COALESCE(u2a.country_code, p.country_code, up.country_code) AS country_code,
  COALESCE(u2a.media_source, p.media_source, up.media_source) AS media_source,
  COALESCE(u2a.platform, p.platform, up.platform) AS platform,
  u2a.af_channel,
  u2a.agency,
  p.amount,
  COALESCE(up.advertising_id, up.idfa) AS real_device_id,
  up.is_one_day_retention
FROM
  users u
  LEFT OUTER JOIN
  user_to_appsflyer u2a ON u.user_id = u2a.user_id AND u2a.user_id != -1
  LEFT OUTER JOIN
  appsflyer_payments p ON u2a.appsflyer_device_id = p.appsflyer_device_id
  LEFT OUTER JOIN
  appsflyer_user_profiles up ON u2a.appsflyer_device_id = up.appsflyer_device_id;
