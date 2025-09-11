-- METHOD-2
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      select distinct(salary) from Employee e1 where N-1= (select count(distinct salary) from Employee e2 where e2.salary>e1.salary)
  );
END
/*
    METHOD-1..
    CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
    BEGIN
        set N=N-1;
    RETURN (
            select distinct(salary) from Employee order by salary desc limit 1 offset N
    );
    END
*/