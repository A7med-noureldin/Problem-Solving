/* Write your T-SQL query statement below */
select e.name as Employee
from Employee e left join Employee mn
on  e.managerId = mn.id 
where e.salary > mn.salary; 