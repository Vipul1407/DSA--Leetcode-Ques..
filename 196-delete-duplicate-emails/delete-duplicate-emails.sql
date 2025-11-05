# Write your MySQL query statement below
-- METHOD-1 Using inner Join..
-- delete p from Person p inner join Person q on p.email=q.email and p.id>q.id

# METHOD-2 Using subquery..
-- delete from Person where id not in (select id from (select min(id) as id from Person group by email) as id)

#METHOD-3 Using row_number() Window function..
with cte as (select id, row_number() over(partition by email order by id) as rn from Person) 
delete from Person where id in (select id from cte where rn>1);