# Write your MySQL query statement below
select
r.contest_id, ROUND((COUNT(r.user_id)/(SELECT COUNT(*) FROM Users))*100,2) as percentage
from
Register r left join Users u
on r.user_id=u.user_id group by r.contest_id order by percentage desc ,r.contest_id asc;
