
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
