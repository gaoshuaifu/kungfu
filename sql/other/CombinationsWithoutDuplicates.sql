/*
There is a plan for departments to further collaborate together on projects. The current departments are given by SELECT name FROM departments;
Write a query to get the list of all combinations of department pairs. Note that a department cannot collaborate with itself.

Part a) How many combinations of unique department pairs exist?
Part b) Write a query to list all the possible collaborations (i.e. department combination pairs)

E.g.
   +-------------+-------------+
   | dept_1      | dept_2      |
   +-------------+-------------+
   | Engineering | Reporting   |
   | Marketing   | Reporting   |
   | Biz Dev     | Reporting   |
        ....          ....
*/

SELECT d1.name, d2.name
FROM departments d1
     INNER JOIN
     departments d2 ON d1.name < d2.name
