# Write your MySQL query statement below
SELECT product_name,year,price
from Sales s left join Product p on s.product_id = p.product_id;