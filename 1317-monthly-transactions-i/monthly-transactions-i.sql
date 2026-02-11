# Write your MySQL query statement below
with cte as (
    select date_format(trans_date, "%Y-%m") as month,
    country, amount,
    if(state="approved",1,0) as approved_cnt,
    if(state="approved",amount,0) as approved_amount
    from Transactions
)
select month,country,count(*) as trans_count, sum(approved_cnt) as approved_count, sum(amount) as trans_total_amount, sum(approved_amount) as approved_total_amount from cte group by month,country;