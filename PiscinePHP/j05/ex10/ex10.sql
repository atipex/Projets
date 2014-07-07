SELECT titre AS `Titre`, resum AS `Resume`, annee_prod from film, genre WHERE genre.id_genre = film.id_genre and genre.nom LIKE 'erotic' ORDER BY annee_prod DESC;
