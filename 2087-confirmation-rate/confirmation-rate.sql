# Write your MySQL query statement below
select s.user_id,if(action IS NULL,0,ROUND(SUM(action='confirmed')/COUNT(*),2)) as confirmation_rate
from signups s 
left join
confirmations c 
on 
s.user_id=c.user_id
group by
s.user_id;
