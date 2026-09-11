# Write your MySQL query statement below
select p.product_id, IFNULL(round(sum(price*units)/sum(units),2),0) as average_price
from
prices p left join UnitsSold u on p.product_id=u.product_id AND  purchase_date >= start_date AND purchase_date<=end_date group by p.product_id ;