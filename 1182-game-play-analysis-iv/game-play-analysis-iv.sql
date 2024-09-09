# Write your MySQL query statement below
SELECT ROUND (COUNT(DISTINCT player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2) as fraction
from
Activity
where
(player_id , DATE_SUB(event_date,INTERVAL 1 DAY))
IN (
    SELECT player_id, MIN(event_date) as first_login from Activity GROUP BY player_id
)