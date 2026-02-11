# Write your MySQL query statement below
-- METHOD-1
-- Using SubQuery..
select name from Employee where id IN(
    select managerId from Employee group by managerId having count(managerId)>=5
);

