-- # Write your MySQL query statement below
-- SELECT query_name, ROUND(avg(rating/position),2) AS quality, ROUND(AVG(IF(RATING<3,1,0))*100,2) AS poor_query_percentage
-- from queries
-- group by query_name;
SELECT QUERY_NAME, ROUND(AVG(RATING/POSITION), 2) AS QUALITY, ROUND(AVG(IF(RATING<3,1,0))*100, 2) AS POOR_QUERY_PERCENTAGE
FROM QUERIES
WHERE query_name is NOT NULL
GROUP BY QUERY_NAME;