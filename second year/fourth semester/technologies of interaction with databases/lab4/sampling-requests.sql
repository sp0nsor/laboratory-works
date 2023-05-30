/* список всех талонов на прием вместе с информацией о враче и его специальности */
SELECT t.id, t.patient_name, t.date, t.start_time, t.duration, d.first_name, d.last_name, s.name AS specialty_name
FROM tickets t
INNER JOIN doctors d ON d.id = t.doctor_id
INNER JOIN specialties s ON s.id = d.specialty_id;

/*список всех специальностей вместе с количеством врачей, работающих в каждой специальности*/
SELECT s.name AS specialty_name, COUNT(d.id) AS num_doctors
FROM specialties s
LEFT JOIN doctors d ON d.specialty_id = s.id
GROUP BY s.name;

/* список всех специальностей вместе с общей длительностью работы всех врачей в каждой специальности */
SELECT s.name AS specialty_name, SUM(s.duration) AS total_duration
FROM specialties s
LEFT JOIN doctors d ON d.specialty_id = s.id
GROUP BY s.name;

/* список всех врачей вместе с общим количеством записей на прием у каждого врача */
SELECT d.first_name, d.last_name, COUNT(t.id) AS num_tickets
FROM doctors d
LEFT JOIN tickets t ON t.doctor_id = d.id
GROUP BY d.id;