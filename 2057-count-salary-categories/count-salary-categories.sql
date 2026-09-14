# Write your MySQL query statement below
select * from (
select "Low Salary" as category, count(*) as accounts_count from accounts where income<20000
group by category
union
select "Average Salary" as category, count(*) as accounts_count from accounts where income>=20000 and income<=50000
group by category
union
select "High Salary" as category, count(*) as accounts_count from accounts where income>50000
group by category
union
select "Low Salary" as category, 0 as accounts_count from accounts
union
select "Average Salary" as category, 0 as accounts_count from accounts 
group by category
union
select "High Salary" as category, 0 as accounts_count from accounts ) as q group by q.category;


