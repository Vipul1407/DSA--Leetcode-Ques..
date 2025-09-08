# Write your MySQL query statement below
-- METHOD-1.. SIMPLE WAY..
-- select c.name as Customers from Customers c where c.id not in (select o.customerId from Orders o)
-- METHOD-2.. LEFT JOIN..
select c.name as Customers from Customers c left join Orders o on c.id= o.customerId where o.customerId is NULL