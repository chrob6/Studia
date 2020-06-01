-- zad1
SELECT first_name, last_name FROM employees WHERE employee_id IN (SELECT manager_id FROM employees );
Select * from employees;

-- zad2
SELECT job_id, salary FROM employees
UNION
SELECT job_id, max_salary FROM jobs;
-- 100
-- bierze tylko te reokordy, gdzie wynik pierwszego oraz drugiego polecenia jest unikalny

SELECT job_id, salary FROM employees
UNION ALL
SELECT job_id, max_salary FROM jobs;
-- 126
-- bierze wszystkie rekordy


-- zad3
SELECT manager_id FROM employees
INTERSECT
SELECT  manager_id FROM  departments;
-- wyswietla wartosc kiedy wystepuje w obu zestawach danych


SELECT manager_id FROM employees
EXCEPT
SELECT  manager_id FROM  departments;
-- wyswietla wartosci jak wystepuje tylko w jednym z zestawow danych

-- zad 4
SELECT department_id FROM departments
INTERSECT
SELECT department_id FROM employees
where salary > 3000;

-- zad 5
Select * from employees WHERE ((SELECT min_salary FROM jobs WHERE (job_id = 'IT_PROG')) > salary);

-- zad 6
SELECT job_history.*, locations.city FROM job_history
INNER JOIN departments d on job_history.department_id = d.department_id
INNER JOIN locations on d.location_id = locations.location_id
WHERE city = ANY (SELECT city FROM locations WHERE city Like 'S%');
