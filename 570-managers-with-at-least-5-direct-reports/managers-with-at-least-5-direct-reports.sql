# Write your MySQL query statement below
-- METHOD-1
-- Using SubQuery..
-- select name from Employee where id IN(
--     select managerId from Employee group by managerId having count(managerId)>=5
-- );

-- METHOD-2
-- Using inner join
select e2.name from Employee e1 inner join Employee e2 on e1.managerId= e2.id group by e1.managerId having count(e1.managerId)>=5;