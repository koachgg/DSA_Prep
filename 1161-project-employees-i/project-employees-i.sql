# Write your MySQL query statement below
SELECT P.project_id, ROUND(AVG(e.experience_years),2) AS average_years
FROM Project P LEFT JOIN Employee e
ON P.employee_id = e.employee_id
GROUP BY p.project_id;