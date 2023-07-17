# Write your MySQL query statement below
select name as Customers from Customers as Customers Left join Orders On Customers.id=Orders.customerId  where Orders.customerId is NULL
