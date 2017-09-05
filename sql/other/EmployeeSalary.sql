/*
employees
   +--------+----+---------+---------+
   |  name  | id |  dept   | salary  |
   +--------+----+---------+---------+
   | John   |  1 | SW      |  70000  |
   | Bob    |  2 | SW      |  90000  |
   | Simon  |  3 | Data    |  95000  |
   | Andy   |  4 | Data    |  50000  |
   | Eric   |  5 | Legal   |  60000  |
   | Matt   |  6 | Legal   | 100000  |
   +--------+----+---------+---------+
*/

/*
Question 0:
For each department, find the highest paid person and their salary.
*/
SELECT
  a.name,
  a.dept,
  a.salary
FROM
  employees a
  INNER JOIN
  (
    SELECT dept, MAX(salary) as max_salary
    FROM employees
    GROUP BY dept
  ) b ON a.dept = b.dept AND a.salary = b.max_salary

/*
Question 1:
Find the 2nd highest salary in the company.
*/
SELECT MAX(salary)
FROM employees
WHERE salary NOT IN (SELECT MAX(salary) FROM employees)

/*
Question 2:
Find the N-th highest salary in the company.
*/
SELECT e1.salary /*This is the outer query part */
FROM employees e1
WHERE (N-1) = ( /* Subquery starts here */
  SELECT COUNT(DISTINCT(e2.salary))
  FROM employees e2
  WHERE e2.salary > e1.salary)

/*
Question 3:
Find the highest employee salary without using the MAX, or TOP or ORDER function
*/
SELECT DISTINCT salary
FROM employees
WHERE salary NOT IN (
  SELECT e1.salary
  FROM employees e1, employees e2
  WHERE e1.salary < e2.salary
)
