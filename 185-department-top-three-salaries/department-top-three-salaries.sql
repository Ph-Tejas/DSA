# Write your MySQL query statement below
 select d1.name as department,e1.name as employee,e1.salary from employee e1 left join department d1 on e1.departmentId=d1.id
  where (d1.name,e1.salary) in (select department,salary from(select t.department,t.salary,ROW_NUMBER() OVER (
            PARTITION BY t.department
            ORDER BY t.salary desc
        ) AS rn from (select d.name as Department,e.salary as Salary
        from employee e right join department d on e.departmentId=d.id group by salary,department order by e.departmentId,salary desc )as t )as f where rn<=3);


