# Write your MySQL query statement below
select E.name as 'Employee' from Employee E JOIN Employee M Where E.managerId = M.id AND E.salary>M.salary;