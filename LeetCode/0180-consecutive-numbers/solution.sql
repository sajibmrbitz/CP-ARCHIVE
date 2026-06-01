/* Write your PL/SQL query statement below */

SELECT DISTINCT A.num AS ConsecutiveNums
FROM Logs A, Logs B, Logs C
WHERE A.id=B.id-1 
  AND B.id=C.id-1 
  AND A.num=B.num 
  AND A.num=C.num;
