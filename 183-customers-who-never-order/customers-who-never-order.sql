# Write your MySQL query statement below
# METHOD-1
# Sub-Query Approach..
select c.name as Customers from Customers c where c.id not in (select o.customerId from Orders o);