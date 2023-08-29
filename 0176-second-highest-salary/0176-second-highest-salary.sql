# Write your MySQL query statement below
# select max(salary) as SecondHighestSalary from Employee where salary NOT IN (select max(salary) from Employee);

# Select salary as SecondHighestSalary from Employee e1 where 2 = (select count(distinct(e2.salary)) from Employee e2 where e2.salary > e1.salary);

select (select distinct salary from Employee order by salary desc limit 1,1) as 'SecondHighestSalary';

