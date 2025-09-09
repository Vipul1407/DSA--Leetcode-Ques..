# Write your MySQL query statement below
-- METHOD-1
-- Using left join + subquery..
-- select b.name as Department, a.name as Employee, a.salary from Employee a left join Department b on a.departmentId = b.id where a.salary= (select max(salary) from Employee where departmentId = a.departmentId)

-- METHOD-2
-- Using left join + Window fun..
select Department, Employee, Salary 
from(
select b.name as Department, a.name as Employee, a.salary, rank() over(partition by a.departmentId order by a.Salary desc) as rnk from Employee a left join Department b on a.departmentId = b.id)
t where rnk=1;