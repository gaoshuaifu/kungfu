I. Question:
logging system:
  playback_events:
  (user_id, movie_id, PLAYBACK_STARTED, movie_pos, utc_timestamp)
  (user_id, movie_id, PLAYBACK_STOPPED, movie_pos, utc_timestamp)

transformed to:
  playback_segements:
  (user_id, movie_id, start_pos, end_pos, start_timestamp, end_timestamp)

By date - By movie category - Show the Top 10 most viewed movies (with rank numbers 1-10)?

II. Discussion:
1. Discuss the definition of "viewed" and "most viewed".
"Most Viewed" is determined by ranking movies based on the number of unique users
who viewed at least a threshold percentage - 50% or 90% of the total movie duration
on the target date.

2. Discuss movie categories.
movies(movie_id, movie_name, movie_length)
movie_category(movie_id, category_id)  -> many-to-many relationship
categories(category_id, category_name)

3. Discuss how are movie views attributed to a date. What if a playback_segment spans two dates?
Solution1: Partition segments based on start_timestamp.
Solution2: Chop the playback_segment at the midnight.

III. ETL Pipeline
1. playback_segements
   (user_id, movie_id, start_pos, end_pos, start_timestamp, end_timestamp)

   transformed to

   user_movie_view_length
   (user_id, movie_id, viewe_length)

Step 1: Collect a list of segments
INSERT INTO TABLE user_movie_intervals
SELECT user_id, movie_id, FB_COLLECT(ARRAY(start_pos, end_pos)) as intervals
FROM playback_segements
GROUP BY user_id, movie_id

Step 2: UDF or Hive Transformer to merge intervals and compute view_length
INSERT INTO TABLE user_movie_view_length
SELECT user_id, movie_id, COMPUTER_VIEW_LENGTH(intervals) as view_length
FROM user_movie_intervals

def COMPUTER_VIEW_LENGTH(intervals):
  intervals = sorted(intervals, key = lambda interval: interval[0])
  interval = intervals[0]
  view_length = 0
  for i in range (1, len(intervals)):
    if interval[1] < interval[i][0]:
      view_length += interval[1] - interval[0]
      interval = interval[i]
    else:
      interval[1] = max(interval[1], interval[i][1])
  view_length += interval[1] - interval[0]
  return view_length

2. user_movie_view_length
   (user_id, movie_id, view_length)

   transformed to

   category_movie_rank
   (category_name, movie_name, rank_number)

Step 1:
INSERT INTO TABLE move_viewers
SELECT
  movie_id, movie_name, COUNT(DISTINCT user_id) number_viewers
FROM
  user_movie_view_length a
  LEFT OUTER JOIN
  movies b ON a.movie_id = b.movie_id AND a.view_length > 0.5 * b.movie_length
GROUP BY movie_id, movie_name

Step 2:
INSERT INTO TABLE category_movie_rank
SELECT
  c.category_name,
  a.movie_name,
  ROW_NUMBER() OVER(PARTITION BY c.category_id ORDER BY a.number_viewers DESC) AS rank_number
FROM
  movie_viewers a
  LEFT OUTER JOIN
  movie_category b ON a.movie_id = b.movie_id
  LEFT OUTER JOIN
  categories c ON b.category_id = c.category_id
