# Write your MySQL query statement below



select 
if(MOD(id,2)=1 ,id+1,id-1)
 as id,student from seat where ((mod((select MAX(id) from seat),2)=1 and id<(select MAX(id) from seat)) or (mod((select MAX(id) from seat),2)=0) ) 
 union
(select id, student from seat where (id) in(select max(id) from seat )AND MOD(id, 2) = 1) order by id;


