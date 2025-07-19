/* Write your T-SQL query statement below */
update Salary
set sex = Case when sex = 'f' then 'm' else 'f' end;
