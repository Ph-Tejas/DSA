# Write your MySQL query statement below
select c.visited_on ,(sum(amount)+
(select sum(c1.amount) from customer c1 where c.visited_on=c1.visited_on+interval 1 day)+
(select sum(c2.amount) from customer c2 where c.visited_on=c2.visited_on+interval 2 day)+
(select sum(c3.amount) from customer c3 where c.visited_on=c3.visited_on+interval 3 day)+
(select sum(c4.amount) from customer c4 where c.visited_on=c4.visited_on+interval 4 day)+
(select sum(c5.amount) from customer c5 where c.visited_on=c5.visited_on+interval 5 day)+
(select sum(c6.amount) from customer c6 where c.visited_on=c6.visited_on+interval 6 day))
as amount, round((sum(amount)+
(select sum(c1.amount) from customer c1 where c.visited_on=c1.visited_on+interval 1 day)+
(select sum(c2.amount) from customer c2 where c.visited_on=c2.visited_on+interval 2 day)+
(select sum(c3.amount) from customer c3 where c.visited_on=c3.visited_on+interval 3 day)+
(select sum(c4.amount) from customer c4 where c.visited_on=c4.visited_on+interval 4 day)+
(select sum(c5.amount) from customer c5 where c.visited_on=c5.visited_on+interval 5 day)+
(select sum(c6.amount) from customer c6 where c.visited_on=c6.visited_on+interval 6 day))/7,2)
as average_amount

from customer c where (c.visited_on - interval 6 day) in (select visited_on from customer) group by c.visited_on order by c.visited_on;