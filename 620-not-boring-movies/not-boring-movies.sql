# Write your MySQL query statement below
select * from cinema where MOD(id,2)=1 AND description not in( "boring") order by rating desc;