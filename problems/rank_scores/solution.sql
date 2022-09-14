# Write your MySQL query statement below
select b.score,(select count(distinct a.score) from Scores a where a.score>=b.score ) as 'rank' From Scores b order by score desc; 
