-- Create and load users table.
CREATE TABLE users (
  user_id INT NOT NULL,
  server_id INT NOT NULL,
  register_time BIGINT NOT NULL,
  last_login_time BIGINT NOT NULL,
  PRIMARY KEY (user_id),
  KEY (server_id)
);

LOAD DATA LOCAL INFILE '/Users/yangw/game_server_data/account' INTO TABLE users
FIELDS TERMINATED BY '\t' LINES TERMINATED BY '\n' IGNORE 1 LINES;


-- Create and load user_to_appsflyer table.
-- Before loading, run the cmd below to replace "NULL" with "\N" in file
-- $sed -i -- 's/NULL/\\N/g' out
CREATE TABLE user_to_appsflyer (
  id INT NOT NULL,
  user_id INT NOT NULL,
  appsflyer_device_id VARCHAR(64) NOT NULL,
  install_time TIMESTAMP NOT NULL,
  media_source VARCHAR(32) NOT NULL,
  platform VARCHAR(32) NOT NULL,
  af_channel VARCHAR(32),
  agency VARCHAR(32),
  timestamp BIGINT NOT NULL,
  server_id INT NOT NULL,
  advertising_id VARCHAR(64),
  country_code VARCHAR(8),
  fb_campaign_name VARCHAR(256),
  fb_adgroup_name VARCHAR(256),
  campaign VARCHAR(256),
  af_siteid VARCHAR(256),
  fb_adset_name VARCHAR(256),
  campaign_id BIGINT,
  adset_id BIGINT,
  adset VARCHAR(256),
  KEY(user_id),
  KEY(appsflyer_device_id)
);

LOAD DATA LOCAL INFILE '/Users/yangw/game_server_data/out' INTO TABLE user_to_appsflyer
FIELDS TERMINATED BY '\t' LINES TERMINATED BY '\n' IGNORE 1 LINES;


-- Create and load payments table.
CREATE TABLE appsflyer_payments (
  appsflyer_device_id VARCHAR(64) NOT NULL,
  platform VARCHAR(32) NOT NULL,
  payment_time TIMESTAMP NOT NULL,
  amount FLOAT NOT NULL,
  country_code VARCHAR(8),
  media_source VARCHAR(32) NOT NULL,
  KEY(appsflyer_device_id)
);

LOAD DATA LOCAL INFILE '/Users/yangw/game_server_data/pay_events' INTO TABLE appsflyer_payments
FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n' IGNORE 31 LINES;


-- Create and load appsflyer_user_profiles table.
CREATE TABLE appsflyer_user_profiles (
  appsflyer_device_id VARCHAR(64) NOT NULL,
  platform VARCHAR(32) NOT NULL,
  advertising_id VARCHAR(64),
  idfa VARCHAR(64),
  install_time TIMESTAMP NOT NULL,
  first_event_time TIMESTAMP NOT NULL,
  last_event_time TIMESTAMP NOT NULL,
  is_one_day_retention SMALLINT NOT NULL,
  country_code VARCHAR(8) NOT NULL,
  media_source VARCHAR(32) NOT NULL,
  PRIMARY KEY (appsflyer_device_id)
);

LOAD DATA LOCAL INFILE '/Users/yangw/game_server_data/processed_user_profiles' INTO TABLE appsflyer_user_profiles
FIELDS TERMINATED BY ',' LINES TERMINATED BY '\n';
