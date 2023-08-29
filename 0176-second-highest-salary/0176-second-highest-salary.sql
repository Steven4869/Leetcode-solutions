# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from Employee where salary NOT IN (select max(salary) from Employee);