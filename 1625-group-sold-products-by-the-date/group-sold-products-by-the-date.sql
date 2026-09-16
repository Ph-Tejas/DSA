# Write your MySQL query statement below
select sell_date, count(*) as num_sold, GROUP_CONCAT(product order by product SEPARATOR ',') AS products from (select * from activities group by sell_date,product )as a group by sell_date;
