# Write your MySQL query statement below
select customer_id , count(*) as count_no_trans
from Visits as v
left join Transactions as t
on v.visit_id=t.visit_id
WHERE t.transaction_id IS NULL
group by v.customer_id;