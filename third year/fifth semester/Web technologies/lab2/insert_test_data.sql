INSERT INTO User (ID, Name, Email, Password)
VALUES
  (1, 'John Doe', 'johndoe@example.com', 'password123'),
  (2, 'Alice Smith', 'alicesmith@example.com', 'securepassword'),
  (3, 'Bob Johnson', 'bjohnson@example.com', 'test123');

INSERT INTO Book (ISBN, Title, Author, PublicationYear, OwnerID)
VALUES
  (1, 'Sample Book 1', 'Sample Author 1', 2020, 1),
  (2, 'Sample Book 2', 'Sample Author 2', 2019, 2),
  ('9785678901234', 'Sample Book 3', 'Sample Author 1', 2021, 3);

INSERT INTO Review (ID, Text, Rating, BookISBN)
VALUES
  (1, 'Great book! Highly recommended.', 5, 1),
  (2, 'Enjoyed reading it.', 4, 1),
  (3, 'Not my cup of tea.', 2, 2);

INSERT INTO Quote (ID, Text, BookISBN)
VALUES
  (1, 'This is a sample quote.', 1),
  (2, 'Another sample quote.', 1);
