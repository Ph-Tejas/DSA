# Write your MySQL query statement below
select 
Students.student_id,Students.student_name,Subjects.subject_name,
COUNT(Examinations.subject_name) as attended_exams 
from
 (Students cross join Subjects )
left join Examinations 
ON 
(Examinations.student_id=Students.student_id 
AND
Examinations.subject_name=Subjects.subject_name)
group by
student_id,student_name,subject_name order by student_id, subject_name;