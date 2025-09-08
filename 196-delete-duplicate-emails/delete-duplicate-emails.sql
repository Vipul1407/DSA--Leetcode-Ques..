# Write your MySQL query statement below
-- METHOD-1 Using inner keyword..
-- delete p from Person p inner join Person q on p.email=q.email and p.id>q.id
-- METHOD-2 Without using delete..
delete from Person where id not in (select id from (select min(id) as id from Person group by email) as id)
