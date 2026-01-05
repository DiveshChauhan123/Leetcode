# Write your MySQL query statement below
select Distinct num as ConsecutiveNums
from (
    select num,
    LAG(num,1) over (order by id) as p1,
    LAG(num,2) over (order by id) as p2
    from Logs
)t
where num=p1 AND num=p2