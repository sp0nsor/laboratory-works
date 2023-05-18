INSERT INTO specialties (name, duration) VALUES
('Cardiology', '6 months'),
('Dermatology', '3 months'),
('Endocrinology', '6 months'),
('Gastroenterology', '3 months');

INSERT INTO doctors (first_name, last_name, middle_name, specialty_id, district_number, phone_numbers) VALUES
('John', 'Doe', 'Robert', 1, 1, '{"123-456-7890", "111-222-3333"}'),
('Jane', 'Doe', NULL, 2, 2, '{"444-555-6666", "777-888-9999"}'),
('Mark', 'Smith', 'David', 3, 3, '{"222-333-4444", "555-666-7777"}'),
('Lisa', 'Johnson', NULL, 4, 4, '{"888-999-0000", "111-222-3333"}');

INSERT INTO tickets (doctor_id, date, start_time, duration, patient_name) VALUES
(1, '2023-04-12', '09:00:00', '1 hour', 'Mary Smith'),
(2, '2023-04-13', '10:30:00', '30 minutes', 'Tom Jones'),
(3, '2023-04-14', '14:00:00', '45 minutes', 'Lisa Wilson'),
(4, '2023-04-15', '11:15:00', '30 minutes', NULL),
(1, '2023-04-16', '08:00:00', '1 hour', 'Peter Brown');
