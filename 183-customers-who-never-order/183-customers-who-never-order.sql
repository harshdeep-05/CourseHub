# Write your MySQL query statement below

SELECT customers.name as 'Customers' from customers where customers.id not in (select customerid from orders);