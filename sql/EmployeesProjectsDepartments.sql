/*
Consider the following data schema:

    employees                             projects
    +---------------+---------+           +---------------+---------+
    | id            | int     |<----+  +->| id            | int     |
    | first_name    | varchar |     |  |  | title         | varchar |
    | last_name     | varchar |     |  |  | start_date    | date    |
    | salary        | int     |     |  |  | end_date      | date    |
    | department_id | int     |--+  |  |  | budget        | int     |
    +---------------+---------+  |  |  |  +---------------+---------+
                                 |  |  |
    departments                  |  |  |  employees_projects
    +---------------+---------+  |  |  |  +---------------+---------+
    | id            | int     |<-+  |  +--| project_id    | int     |
    | name          | varchar |     +-----| employee_id   | int     |
    +---------------+---------+           +---------------+---------+
*/

/*
Question 0:
Write a query to show all names and department of all workers.

Example Output:
    +------------+-----------+-----------------+
    | first_name | last_name | department_name |
    +------------+-----------+-----------------+
    | John       | Smith     | Reporting       |
    | Cailin     | Ninson    | Engineering     |
    | Mike       | Peterson  | Engineering     |
    | Ian        | Peterson  | Engineering     |
    | John       | Mills     | Marketing       |
    | Ava        | Muffinson | Silly Walks     |
    +------------+-----------+-----------------+
*/

SELECT
  e.first_name,
  e.last_name,
  d.name AS department_name
FROM employees e
     LEFT OUTER JOIN
     departments d ON e.department_id = d.id

/*
Question 1:
Write a query to list the departments with a net employee salary of more than $40,000.

Example Output:
   +-------------+-----------------+
   | name        | combined_salary |
   +-------------+-----------------+
   | Engineering |        130000   |
   | Marketing   |         50000   |
   +-------------+-----------------+
*/

SELECT
  d.id,
  d.name,
  SUM(salary) AS combined_salary
FROM departments d
     INNER JOIN
     employees e ON d.id = e.department_id
GROUP BY d.id, d.name
HAVING SUM(salary) > 40000

/*
Question 2:
List the current projects and employees assigned to them.

Example Output:
+------------+-----------+--------------------------+
| first_name | last_name | title                    |
+------------+-----------+--------------------------+
| John       | Smith     | Update TPS Reports       |
| Ava        | Muffinson | Design 3 New Silly Walks |
| Cailin     | Ninson    | Build a cool site        |
| Mike       | Peterson  | Build a cool site        |
| Ian        | Peterson  | Build a cool site        |
+------------+-----------+--------------------------+
*/

SELECT
  e.first_name,
  e.last_name,
  p.title
FROM projects p
     LEFT OUTER JOIN
     employees_projects ep ON p.id = ep.project_id
     LEFT OUTER JOIN
     employees e ON ep.employee_id = e.id

/*
Question 2 Followup:
Modify the query to capture projects with no employees assigned and employees
with no projects assigned
(i.e the employees_projects table does not contain those mappings).
Assume that the employees without a project are in the employees table.
Assume that the projects without a employee are in the projects table.

Example Output:
   +------------+-----------+--------------------------+
   | first_name | last_name | title                    |
   +------------+-----------+--------------------------+
   | John       | Smith     | Update TPS Reports       |
   | Ava        | Muffinson | Design 3 New Silly Walks |
   | Cailin     | Ninson    | Build a cool site        |
   | Mike       | Peterson  | Build a cool site        |
   | Ian        | Peterson  | Build a cool site        |
   | John       | Mills     | NULL                     |
   +------------+-----------+--------------------------+
*/

SELECT
  e.first_name,
  e.last_name,
  p.title
FROM projects p
     LEFT OUTER JOIN
     employees_projects ep ON p.id = ep.project_id
     RIGHT OUTER JOIN
     employees e ON ep.employee_id = e.id;

/*
Question 3:
For each department, find the highest paid person and their salary.

Example Output:
   +------------+-----------+-------------+--------+
   | first_name | last_name | dept_name   | salary |
   +------------+-----------+-------------+--------+
   | John       | Smith     | Reporting   |  20000 |
   | Ian        | Peterson  | Engineering |  80000 |
   | John       | Mills     | Marketing   |  50000 |
   | Ava        | Muffinson | Silly Walks |  10000 |
   +------------+-----------+-------------+--------+
*/

SELECT
  e.first_name,
  e.last_name,
  d.name AS dept_name,
  a.salary
FROM
  (
    SELECT department_id, MAX(salary) AS salary
    FROM employees
    GROUP BY department_id
  ) a
  INNER JOIN
  employees e ON a.department_id = e.department_id AND a.salary = e.salary
  INNER JOIN
  departments d ON e.department_id = d.department_id

/*
Question 4:
Which employees are not currently assigned to any projects?

Example Output:
    +------------+-----------+
    | first_name | last_name |
    +------------+-----------+
    | John       | Mills     |
    +------------+-----------+
*/

SELECT
  e.first_name, e.last_name
FROM employees e
     LEFT OUTER JOIN
     employees_projects ep ON e.id = ep.employee_id
WHERE ep.project_id IS NULL
