# Write your MySQL query statement below
select a.id from Weather a INNER JOIN Weather b ON (a.temperature>b.temperature AND (a.recordDate - INTERVAL 1 DAY=b.recordDate));