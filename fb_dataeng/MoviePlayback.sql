I. Question:
logging system:
  playback_events:
  (user_id, movie_id, PLAYBACK_STARTED, movie_pos_in_secs, utc_timestamp)
  (user_id, movie_id, PLAYBACK_STOPPED, movie_pos_in_secs, utc_timestamp)

transformed to:
  playback_segements:
  (user_id, movie_id, pb_start_pos, pb_end_pos, pb_start_timestamp, pb_end_timestamp)

By date - By movie category - Show the Top 10 most viewed movies (with rank numbers 1-10)?

II. Discussion:
1. Discuss the definition of "viewed" and "most viewed".
"Most Viewed" is determined by ranking movies based on the number of unique users
who viewed at least a threshold percentage - 50% or 90% of the total movie duration
on the target date.

2. Discuss movie categories.
movies(movie_id, movie_name, movie_length_secs)
movie_category(movie_id, category_id)  -> many-to-many relationship
categories(category_id, category_name)

3. Discuss how are movie views attributed to a date. What if a playback_segment spans two dates?
Solution1: Aggregate the playback_segment to the first date DATE(pb_start_timestamp).
Solution2: Chop the playback_segment at the midnight.

III. ETL Pipeline
1. playback_segements
   (user_id, movie_id, pb_start_pos, pb_end_pos, pb_start_timestamp, pb_end_timestamp)

   transformed to

   user_movie_views
   (user_id, movie_id, total_viewed_secs)

Step 1: Collect a list of segments
SELECT user_id, movie_id, FB_COLLECT(ARRAY(pb_start_pos, pb_end_pos)) as intervals
FROM playback_segements
WHERE DATE(pb_start_timestamp) = '<DATEID>'
GROUP BY user_id, movie_id

Step 2: UDF or Hive Transformer to merge interval and compute total_viewed_secs
def total_viewed_secs(intervals):
  sort(intervals, key = lambda interval: interval[0])
  interval = intervals[0]
  total_viewed_secs = 0
  for i in range (1, len(intervals)):
    if interval[1] < interval[i][0]:
      total_viewed_secs += interval[1] - interval[0]
      interval = interval[i]
    else:
      interval[1] = max(interval[1], interval[i][1])
  total_viewed_secs += interval[1] - interval[0]
  return total_viewed_secs

2. user_movie_views
   (user_id, movie_id, total_viewed_secs)

   transformed to

   category_movie_rank
   (category_name, movie_name, rank_number)

movie_viewers:
SELECT
  movie_id, movie_name, COUNT(DISTINCT user_id) number_viewers
FROM
  user_movie_views v
  INNER JOIN
  movies m ON v.movie_id = m.movie_id AND v.total_viewed_secs > 0.5 * m.movie_length_secs
GROUP BY movie_id, movie_name

category_movie_rank:
SELECT
  c.category_name,
  mv.movie_name,
  ROW_NUMBER() OVER(PARTITION BY c.category_id ORDER BY mv.number_viewers DESC) AS rank_number
FROM
  movie_viewers mv
  INNER JOIN
  movie_category mc ON m.movie_id = mc.movie_id
  INNER JOIN
  categories c ON mc.category_id = c.category_id