# Write your MySQL query statement below
select e1.unique_id, e.name from Employees AS e LEFT JOIN EmployeeUNI AS e1 ON e.id=e1.id;