-- The number of users:
-- Result: 21,910,791
SELECT COUNT(DISTINCT user_id) AS num_of_users
FROM users

-- The number of users of each server.
SELECT server_id, COUNT(1) as num_of_users
FROM users
GROUP BY server_id
ORDER BY server_id

-- The number of users with appsflyer device.
-- Result: 7,322,958
SELECT COUNT(DISTINCT user_id) AS num_of_users
FROM user_to_appsflyer
WHERE user_id != -1

-- The number of users with multiple appsflyer devices
-- Result: 0
SELECT COUNT(1)
FROM (
  SELECT user_id, COUNT(DISTINCT appsflyer_device_id) AS num_appsflyer_devices
  FROM user_to_appsflyer
  WHERE user_id != -1
  GROUP BY user_id
  HAVING num_appsflyer_devices > 1
) a

-- The number of appsflyer devices.
-- Result: 6,215,927
SELECT COUNT(DISTINCT appsflyer_device_id) AS num_of_appsflyer_device
FROM user_to_appsflyer
WHERE user_id != -1

-- The number of appsflyer devices with multiple users.
-- Result: 265,647
SELECT COUNT(1) AS num_of_appsflyer_device_with_multiple_users
FROM (
  SELECT appsflyer_device_id, COUNT(DISTINCT user_id) AS num_users
  FROM user_to_appsflyer
  WHERE user_id != -1
  GROUP BY appsflyer_device_id
  HAVING num_users > 1
) a
