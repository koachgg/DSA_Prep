# Write your MySQL query statement below
SELECT product_id , year as first_year , quantity , price 
FROM sales
where (product_id,year) in (select product_id, min(year) as year 
from sales
group by product_id);