# Write your MySQL query statement below
-- METHOD-1
-- Using rank window function..
select score, dense_rank() over(order by score desc) as "rank" from Scores