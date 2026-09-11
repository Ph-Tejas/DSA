# Write your MySQL query statement below
select a.name
from
Employee a INNER JOIN Employee b ON a.id=b.managerId GROUP BY b.managerId HAVING COUNT(*)>=5;