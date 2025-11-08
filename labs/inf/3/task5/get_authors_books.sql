SELECT books.title, books.publication_year, books.genre  FROM books
JOIN authors ON books.author_id = authors.id
WHERE authors.name='Лев Толстой';

