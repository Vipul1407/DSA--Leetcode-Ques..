# Write your MySQL query statement below
-- METHOD-1 Using delete keyword..
delete p from Person p inner join Person q on p.email=q.email and p.id>q.id