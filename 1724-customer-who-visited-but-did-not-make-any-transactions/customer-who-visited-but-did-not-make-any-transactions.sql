# Write your MySQL query statement below
SELECT customer_id,COUNT(v.visit_id) as count_no_trans
from Visits v
LEFT JOIN TRANSACTIONS t ON v.visit_id = t.visit_id
where transaction_id IS NULL
GROUP BY customer_id;