/* Write your PL/SQL query statement below */

DELETE FROM Person
WHERE id NOT IN(
    SELECT MIN(id)      -- keep the 1st occurence
    FROM Person
    GROUP BY email
);
