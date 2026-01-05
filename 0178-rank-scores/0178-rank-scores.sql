# Write your MySQL query statement below
select s2.score ,(
    select count(Distinct s.score)
    from Scores s
    where s2.score<s.score
)+1 as 'rank'
from Scores s2
order by score DESC;