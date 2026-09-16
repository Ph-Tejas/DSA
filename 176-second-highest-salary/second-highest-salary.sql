# Write your MySQL query statement below

select SecondHighestSalary from((select salary as SecondHighestSalary from employee group by salary order by SecondHighestSalary desc limit 1 offset 1)
union 
(select null as SecondHighestSalary ))as a limit 1;
