/* Write your PL/SQL query statement below */
-- highest other than the highest

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary<(SELECT MAX(salary) FROM Employee);
