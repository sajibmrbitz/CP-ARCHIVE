/* Write your PL/SQL query statement below */
--self join to compare

SELECT today.id
FROM Weather today
JOIN Weather yesterday ON (today.recordDate-yesterday.recordDate)=1
WHERE today.temperature>yesterday.temperature;

