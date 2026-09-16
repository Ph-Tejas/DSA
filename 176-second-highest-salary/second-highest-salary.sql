# Write your MySQL query statement below

select (select distinct salary as SecondHighestSalary from employee order by SecondHighestSalary desc limit 1 offset 1)as SecondHighestSalary;
