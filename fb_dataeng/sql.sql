/*
Tables:
  stores(id, name, state, space)
  customers(id, name, age, gender)
  products(id, name)
  transactions(id, customer_id, product_id, store_id, sale, ts)
*/

-- States with at least 25,000 square feet of store space
SELECT state, SUM(space) AS store_space
FROM stores
GROUP BY state
HAVING SUM(space) >= 25000

-- What percent of our customer base is male
SELECT SUM(CASE WHEN gender = 'male' THEN 1 ELSE 0 END) * 100.0 / SUM(1) AS male_perc
FROM customers

-- In how many different states are our stores located in?
SELECT COUNT(DISTINCT state) AS num_states
FROM stores

-- Find the youngest and oldest customers who have bought at least 1 product, segmented by gender
SELECT gender, MIN(age) AS min_age, MAX(age) AS max_age
FROM customers c INNER JOIN transactions t ON c.id = t.customer_id
GROUP BY gender

-- How many products had more than 5 total units sold?
SELECT COUNT(1) AS num_products
FROM (
  SELECT product_id, COUNT(1) AS num_sold
  FROM transactions
  GROUP BY product_id
  HAVING COUNT(1) > 5
) a

-- Same as 5a above, but now segment this by state.
SELECT
  s.state, COUNT(1) AS num_products
FROM (
    SELECT store_id, product_id, COUNT(1) AS num_sold
    FROM transactions
    GROUP BY store_id, product_id
    HAVING COUNT(1) > 5
  ) a
  INNER JOIN
  stores s ON a.store_id = s.id
GROUP BY s.state

-- percentage of all registered customers that have purchased at least 1 product
SELECT
  SUM(CASE WHEN customer_id IS NOT NULL THEN 1 ELSE 0 END) * 100.0 / COUNT(1) AS perc
FROM
  customers a
  LEFT OUTER JOIN
  (
    SELECT DISTINCT customer_id
    FROM transactions
  ) b ON a.id = b.customer_id

-- List all the customers that live in oregon, ordered by the number of unique products they bought.
SELECT c.id, c.name
FROM customers c
     INNER JOIN (
       SELECT customer_id, COUNT(DISTINCT product_id) AS num_products
       FROM transactions
       GROUP BY customer_id
     ) a ON c.id = a.customer_id
WHERE c.state = 'OREGON'
ORDER BY a.num_products DESC

-- For each store show the % Difference in sales between 2014 and 2015
SELECT store_id, (sales_2015 - sales_2014) * 100.0 / sales_2014 AS diff_perc
FROM (
  SELECT
    store_id,
    SUM(CASE WHEN year(ts) = 2014 THEN sale ELSE 0 END) AS sales_2014,
    SUM(CASE WHEN year(ts) = 2015 THEN sale ELSE 0 END) AS sales_2015
  FROM transactions
  GROUP BY store_id
) a

-- Which is the most profitable store
WITH store_total_sales AS (
  SELECT store_id, SUM(sale) AS total_sales
  FROM transactions
  GROUP BY store_id
)

SELECT store_id
FROM store_total_sales
WHERE total_sales IN (
  SELECT MAX(total_sales) AS max_total_sales
  FROM store_total_sales
)
