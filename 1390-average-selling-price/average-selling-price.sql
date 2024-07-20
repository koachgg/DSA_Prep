-- # Write your MySQL query statement below
-- SELECT Prices.product_id , round(sum(price*units)/SUM(units),2) as average_price
-- from Prices join UnitsSold
-- on Prices.product_id = unitsSold.product_id
-- and purchase_date between start_date and end_date
-- group by product_id;

-- select prices.product_id, ROUND(SUM(price * units) / SUM(units), 2) as average_price
-- from Prices join UnitsSold 
-- on prices.product_id = unitssold.product_id
-- and purchase_date between start_date and end_date
-- group by product_id


# Write your MySQL query statement below
SELECT p.product_id, IFNULL(ROUND(SUM(units*price)/SUM(units),2),0) AS average_price
FROM Prices p LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND
u.purchase_date BETWEEN start_date AND end_date
group by product_id