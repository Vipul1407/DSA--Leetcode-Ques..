# Write your MySQL query statement below
# METHOD-3
select(
select distinct salary from Employee e1 where 1= (
    select count(distinct salary) from Employee e2 where e1.salary<e2.salary 
)
) as SecondHighestSalary
/*
# METHOD-1
select distinct max(salary) as SecondHighestSalary  from Employee where salary not IN (
    select distinct max(salary) from Employee
)
# METHOD-2
select(
select distinct salary from Employee order by salary desc limit 1 offset 1
) as SecondHighestSalary
*/