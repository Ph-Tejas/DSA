# Write your MySQL query statement below
select x,y,z,if(x+y>z AND x+z>y AND y+z>x,'Yes','No')as triangle from triangle;