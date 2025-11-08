INSERT INTO authors (id, name, birth_year) VALUES
(1, 'Лев Толстой', 1828),
(2, 'Фёдор Достоевский', 1821),
(3, 'Антон Чехов', 1860);


INSERT INTO books (id, title, author_id, publication_year, genre) VALUES
(1, 'Война и мир', 1, 1869, 'Роман'),
(2, 'Преступление и наказание', 2, 1866, 'Психологический роман'),
(3, 'Вишневый сад', 3, 1904, 'Пьеса');


INSERT INTO users (id, name, registration_date) VALUES
(1, 'Иван Петров', '2025-01-15'),
(2, 'Мария Сидорова', '2025-02-20'),
(3, 'Алексей Козлов', '2025-03-10');


INSERT INTO borrowed_books (user_id, book_id, borrow_date, return_date) VALUES
(1, 1, '2025-01-10', '2025-01-25'),
(2, 2, '2025-01-15', NULL),
(3, 3, '2025-01-20', '2025-02-05');