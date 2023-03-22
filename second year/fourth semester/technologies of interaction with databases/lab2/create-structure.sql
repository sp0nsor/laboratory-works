CREATE TABLE specialties (
  id SERIAL PRIMARY KEY,
  name VARCHAR(255) NOT NULL,
  duration INTERVAL NOT NULL
);

CREATE TABLE doctors (
  id SERIAL PRIMARY KEY,
  first_name VARCHAR(255) NOT NULL,
  last_name VARCHAR(255) NOT NULL,
  middle_name VARCHAR(255),
  specialty_id INTEGER NOT NULL REFERENCES specialties(id),
  district_number INTEGER NOT NULL,
  phone_numbers TEXT[] NOT NULL
);

CREATE TABLE tickets (
  id SERIAL PRIMARY KEY,
  doctor_id INTEGER NOT NULL REFERENCES doctors(id),
  date DATE NOT NULL,
  start_time TIME NOT NULL,
  duration INTERVAL NOT NULL,
  patient_name VARCHAR(255),
  UNIQUE (doctor_id, date, start_time)
);