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
SELECT state, COUNT(1) AS num_products
FROM (
  SELECT s.state, t.product_id, COUNT(1) AS num_sold
  FROM
    transactions t
    INNER JOIN
    stores s ON t.store_id = s.id
  GROUP BY s.state, t.product_id
  HAVING COUNT(1) > 5
) a

-- percentage of all registered customers that have purchased at least 1 product
SELECT
  SUM(CASE WHEN b.customer_id IS NOT NULL THEN 1 ELSE 0 END) * 100.0 / COUNT(1) AS perc
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


/*
CoderPad provides a basic SQL sandbox with the following schema.
You can also use commands like `show tables` and `desc sales`

products                              sales
+------------------+---------+        +------------------+---------+
| product_id       | int     |------->| product_id       | int     |
| product_class_id | int     |  +---->| store_id         | int     |
| brand_name       | varchar |  |  +->| customer_id      | int     |
| product_name     | int     |  |  |  | promotion_id     | int     |
| price            | int     |  |  |  | store_sales      | decimal |
+------------------+---------+  |  |  | store_cost       | decimal |
                                |  |  | units_sold       | decimal |
                                |  |  | transaction_date | date    |
                                |  |  +------------------+---------+
                                |  |
stores                          |  |  customers
+-------------------+---------+ |  |  +---------------------+---------+
| store_id          | int     |-+  +--| customer_id         | int     |
| type              | varchar |       | first_name          | varchar |
| name              | varchar |       | last_name           | varchar |
| state             | varchar |       | state               | varchar |
| first_opened_date | datetime|       | birthdate           | date    |
| last_remodel_date | datetime|       | education           | varchar |
| area_sqft         | int     |       | gender              | varchar |
+-------------------+---------+       | date_account_opened | date    |
                                      +---------------------+---------+
/*

/*
1) States with at least 25,000 Square Feet of Store Space

+-------+-----------------+
| state | total_area_sqft |
+-------+-----------------+
| CA    |           46076 |
| OR    |           27694 |
+-------+-----------------+
*/

select state, sum(area_sqft) as total_area_sqft
from stores
group by state
having sum(area_sqft) >= 25000

/*
2) What percent of our customer base is male?

+----------+
| pct_male |
+----------+
|  48.6667 |
+----------+
*/

select sum(case when gender = 'M' then 1 else 0 end) * 100.0 / sum(1) as pct_male
from customers

/*
3) In how many different states are our stores located in?

+---------------------+
| count_unique_states |
+---------------------+
|                   3 |
+---------------------+
*/

select count(distinct state) as count_unique_states
from stores

/*
4) Find the youngest and oldest customers who have bought at least 1 product, segmented by gender.

+--------+------------------------+--------------------+
| gender | earliest_born_customer | last_born_customer |
+--------+------------------------+--------------------+
|      F |             1928-09-02 |         1994-06-13 |
|      M |             1927-03-02 |         1995-06-20 |
+--------+------------------------+--------------------+
*/

select gender, min(birthdate) as earliest_born_customer, max(birthdate) as last_born_customer
from customers c inner join sales s on c.customer_id = s.customer_id
group by gender

/*
5A) how many products had more than 5 total units sold?

+-------------------+
| count_products    |
+-------------------+
| 127               |
+-------------------+
*/

select count(1) as count_products
from (
  select product_id, sum(units_sold) as total_units
  from sales
  group by product_id
  having sum(units_sold) > 5
) a

/*
5b) Same as 5A above, but now segment this by state.  By state, how many products had more than 5 units sold?

+-------+----------------+
| state | count_products |
+-------+----------------+
| CA    |             15 |
| OR    |             26 |
| WA    |             21 |
+-------+----------------+
*/

select state, count(distinct product_id) as count_products
from (
  select b.state, a.product_id, sum(a.units_sold) as total_units
  from sales a inner join stores b on a.store_id = b.store_id
  group by b.state, product_id
  having sum(a.units_sold) > 5
) a
group by state

/*
6)  % of all registered customers THAT have purchased at least 1 product?

+---------------------------------------+
| pct_customers_ever_purchased_anything |
+---------------------------------------+
|                               50.0000 |
+---------------------------------------+
*/

select sum(case when b.customer_id is not null then 1 else 0 end) / sum(1) as pct_customers_ever_purchased_anything
from customers a left outer join (
    select distinct customer_id
    from sales
  ) b on a.customer_id = b.customer_id

-- Another solution
select count(distinct b.customer_id) / count(distinct a.customer_id) as pct_customers_ever_purchased_anything
from customers a left outer join sales b on a.customer_id = b.customer_id

/*
7) List all of the customers in Oregon ordered by the number of unique products they bought.

+------------+-----------+------------------------------+
| first_name | last_name | count_unique_items_purchased |
+------------+-----------+------------------------------+
| Arturo     | Poisson   | 40                           |
| Kendra     | Thompson  | 30                           |
| Beverly    | Young     | 29                           |
| J.         | Boyle     | 27                           |
| David      | Moss      | 26                           |
| Martha     | Parker    | 24                           |
| Stacy      | McGuire   | 0                            |
| Mary Ruth  | Pina      | 0                            |
| Franklin   | Castillo  | 0                            |
| Robert     | Vessa     | 0                            |
| Lisa       | Anderson  | 0                            |
| Darwin     | Slominski | 0                            |
| Pearl      | Stephens  | 0                            |
| Harriet    | Brooks    | 0                            |
| Ruben      | Espinosa  | 0                            |
| Louis      | McGrath   | 0                            |
| Regina     | Sorensen  | 0                            |
| Ruth       | Burger    | 0                            |
| Duane      | Howard    | 0                            |
| Robert     | Borges    | 0                            |
+------------+-----------+------------------------------+
*/

select a.first_name, a.last_name,
       coalesce(b.num_products, 0)
from customers a left outer join (
  select customer_id, count(distinct product_id) as num_products
  from sales
  group by 1
) b on a.customer_id = b.customer_id
where a.state = 'OR'
order by b.num_products desc

/*
8) For each store show the % Difference in sales between 2014 and 2015

Formula for clarification = 100 * ((2015_Sales/2014_Sales) - 1)

+----------+------------------+
| name     | pct_2015_vs_2014 |
+----------+------------------+
| Store 13 |       2.29844204 |
| Store 14 |     -52.73828944 |
| Store 15 |      12.53368604 |
| Store 7  |      31.21018089 |
+----------+------------------+
*/

select b.name, 100 * ((sales_2015/sales_2014) - 1)
from (
  select
    store_id,
    sum(case when year(transaction_date) = 2014 then store_sales else 0 end) as sales_2014,
    sum(case when year(transaction_date) = 2015 then store_sales else 0 end) as sales_2015
  from sales
  group by store_id
) a inner join stores b on a.store_id = b.store_id

/*
9) Which is the most profitable store?

+------------+-------------+-----------------+
| store_name | store_state | lifetime_profit |
+------------+-------------+-----------------+
| Store 7    |          CA |        871.0043 |
+------------+-------------+-----------------+
*/

select b.name as store_name, b.state as store_state, a.profit as lifetime_profit
from (
  select store_id, sum(store_sales - store_cost) as profit
  from sales
  group by store_id
) a inner join stores b on a.store_id = b.store_id
order by a.profit desc
limit 1

/*
10) Top Selling and Bottom Selling Product by SALES

+-------------------------+------------------+
| product_name            | Sum(store_sales) |
+-------------------------+------------------+
| Horatio No Salt Popcorn |          42.0200 |
| Atomic Tasty Candy Bar  |           0.6600 |
+-------------------------+------------------+
*/
