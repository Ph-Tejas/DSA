# Write your MySQL query statement below
select a.machine_id,ROUND(AVG(b.timestamp-a.timestamp),3) as processing_time
from
Activity a INNER JOIN Activity b ON (a.process_id=b.process_id AND a.machine_id=b.machine_id AND b.activity_type='end' AND a.activity_type='start') 

 GROUP BY machine_id;