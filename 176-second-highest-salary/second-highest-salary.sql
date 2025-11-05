# Write your MySQL query statement below

# METHOD-1
select max(salary) as SecondHighestSalary from Employee where salary not in (select distinct max(salary) from Employee);