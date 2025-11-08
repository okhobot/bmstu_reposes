SELECT books.title, books.publication_year, books.genre  FROM books 
JOIN borrowed_books ON books.id = borrowed_books.book_id
WHERE borrowed_books.return_date IS NULL;

