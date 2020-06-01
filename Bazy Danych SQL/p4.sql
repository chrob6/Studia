SELECT * FROM employees;

SELECT * FROM locations;
SELECT  job_title FROM jobs;

SELECT employees.first_name, employees.last_name, employees.email, job_history.start_date, job_history.end_date
FROM employees
INNER JOIN  job_history
ON employees.employee_id = job_history.employee_id;
-- wyświetla elementy z tabel employees oraz job_history kiedy klucz gł zgadza się z kluczem obcym

SELECT employees.first_name, employees.last_name, employees.email, job_history.start_date, job_history.end_date
FROM employees
RIGHT JOIN  job_history
ON employees.employee_id = job_history.employee_id;
-- wyświetla wszystkie elementy z tabeli job_history oraz
-- przyporzadkowywuje kluczowi z job_history wartości z klucza z tabeli employees

SELECT employees.first_name, employees.last_name, employees.email, job_history.start_date, job_history.end_date
FROM employees
LEFT JOIN  job_history
ON employees.employee_id = job_history.employee_id;
-- wyświetla wszystkie elementy z tabeli employees oraz
-- przyporzadkowywuje kluczowi z employees wartości z klucza z tabeli job_history

/*
SELECT employees.first_name, employees.last_name, employees.salary
FROM employees INNER JOIN jobs
ON employees.job_id = jobs.job_id
WHERE jobs.job_title
LIKE '%Manager%'
AND employees.salary < 10000;
*/

SELECT employees.first_name, employees.last_name, employees.salary
FROM employees
GROUP BY manager_id
HAVING salary < 10000;

SELECT employees.first_name, employees.last_name, countries.country_name
FROM employees
LEFT JOIN departments ON employees.department_id = departments.department_id
INNER JOIN locations ON departments.location_id = locations.location_id
INNER JOIN countries ON locations.country_id = countries.country_id
WHERE country_name = 'Germany' OR country_name = 'United Kingdom';

SELECT  job_history.*, employees.salary, employees.manager_id
FROM job_history
LEFT JOIN departments ON job_history.department_id = departments.department_id
LEFT JOIN employees ON departments.department_id = employees.department_id
WHERE employees.employee_id = departments.manager_id
ORDER BY  employees.salary DESC;

SELECT  * from job_history;
SELECT  * from departments;

