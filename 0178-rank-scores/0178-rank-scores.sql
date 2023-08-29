# Write your MySQL query statement below
select s1.score, (select count(distinct score) from scores s2 where s2.score >= s1.score) as "rank" from scores s1 order by score desc;