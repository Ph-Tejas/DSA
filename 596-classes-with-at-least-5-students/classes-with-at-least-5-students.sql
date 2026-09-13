# Write your MySQL query statement below
select class from (select class,count(*)as cnt from courses group by class)as l where cnt >=5;