# Write your MySQL query statement below
# METHOD-2
select(
select distinct salary from Employee order by salary desc limit 1 offset 1
) as SecondHighestSalary
/*
# METHOD-1
select distinct max(salary) as SecondHighestSalary  from Employee where salary not IN (
    select distinct max(salary) from Employee
)
*/