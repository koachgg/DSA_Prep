# Write your MySQL query statement below
SELECT E.name , B.bonus 
from Employee as E LEFT OUTER JOIN Bonus as B
ON E.empId = B.empId
where B.bonus < 1000 or B.bonus IS NULL;