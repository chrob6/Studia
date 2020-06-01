select * from employees;

-- zad1
SELECT min(salary), avg(salary), max(salary) FROM employees WHERE hire_date > '1997-12-12';
-- powinno być 2005-12-12 ale nie ma takich pracownikow wiec uzylem innego roku

-- zad2
SELECT avg(salary) AS AVARAGE, department_id, job_id FROM employees
GROUP BY department_id, job_id
ORDER BY AVARAGE;

-- zad3
SELECT COUNT(d.department_id) AS amount, l.street_address, l.city FROM locations l
LEFT JOIN departments d ON l.location_id = d.location_id
GROUP BY  l.street_address, l.city
ORDER BY  amount DESC;

-- zad4
SELECT AVG(salary), d.department_name FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id
GROUP BY  department_name
HAVING COUNT(e.department_id) > 4;

-- zamiast ON moze wstawić WHERE ale chyba nie o to chodzilo, nie da sie wykluczyc having

-- zad5
SELECT d.department_id, d.department_name, c.country_name, l.city, l.street_address, max(e.salary) as max FROM employees e
LEFT JOIN departments d on e.department_id = d.department_id
LEFT JOIN locations l on d.location_id = l.location_id
LEFT JOIN countries c on l.country_id = c.country_id
WHERE d.manager_id IS NOT null
group by d.department_name, c.country_name, l.city, l.street_address
HAVING max > 7000
ORDER BY  d.department_name;

-- zad6
-- mozna to wykonoc poprzez agregacje lub podzapytania