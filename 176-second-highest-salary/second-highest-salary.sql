# Write your MySQL query statement below

# METHOD-1
-- select max(salary) as SecondHighestSalary from Employee where salary not in (select distinct max(salary) from Employee);

# METHOD-2
select( select distinct salary from Employee order by salary desc limit 1 offset 1) as SecondHighestSalary;