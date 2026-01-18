# Write your MySQL query statement below
-- METHOD-1
-- with cte as (select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() over (partition by e.departmentId order by e.salary desc) as drnk from Employee e inner join Department d on e.departmentId=d.id)

-- select Department,Employee,Salary from cte where drnk<=3;

-- METHOD-2
select Department,Employee,Salary from (select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() over (partition by e.departmentId order by e.salary desc)as drnk from Employee e inner join Department d on e.departmentId=d.id)t where t.drnk<=3;