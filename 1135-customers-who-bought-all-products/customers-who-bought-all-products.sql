-- # Write your MySQL query statement below
-- SELECT customer_id
-- from Customer
-- group by customer_id
-- having count(distinct product_key) = (Select 
-- Count(product_key) 
-- from Product 
-- );

# Write your MySQL query statement below
SELECT 
customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product)