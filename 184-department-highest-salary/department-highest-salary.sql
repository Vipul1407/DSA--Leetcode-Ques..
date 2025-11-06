# Write your MySQL query statement below
-- METHOD-1
-- Using left join + subquery..
-- select b.name as Department, a.name as Employee, a.salary from Employee a left join Department b on a.departmentId = b.id where a.salary= (select max(salary) from Employee where departmentId = a.departmentId)

-- METHOD-2
-- Using inner join + Window fun..
-- select Department, Employee, Salary 
-- from(
-- select b.name as Department, a.name as Employee, a.salary, rank() over(partition by a.departmentId order by a.Salary desc) as rnk from Employee a inner join Department b on a.departmentId = b.id)
-- t where rnk=1;

# METHOD-3
-- Using inner join + Window fun.. storing in temptable..
# can use rank or dense rank anything since we have to find the highest one only..
with cte as (select d.name as Department, e.name as Employee, e.salary as Salary, rank() over (partition by e.departmentId order by e.salary desc) as rnk from Employee e inner join Department d on e.departmentId = d.id
)
select Department, Employee, Salary from cte where rnk=1;