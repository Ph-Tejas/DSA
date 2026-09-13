# Write your MySQL query statement below
select round(sum(case when first_day+INTERVAL 1 DAY=second_day then 1 else 0 end)/count(*),2) as fraction
from
(select min(event_date)as first_day,(select event_date from activity a2 where a1.player_id=a2.player_id ORDER by event_date limit 1 offset 1)as second_day from activity a1 group by player_id


)x;


