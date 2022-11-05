CREATE VIEW cin.RecitaLabeled
AS SELECT cin.film.id_film, cin.film.titolo, cin.attore.id_attore, cin.attore.nome, cin.attore.cognome
FROM (cin.film JOIN cin.recita ON film.id_film = recita.film) JOIN cin.attore ON attore.id_attore=recita.attore;

CREATE VIEW cin.RecitaLabeledv2
AS SELECT  cin.film.titolo, cin.film.id_film, cin.attore.id_attore, cin.attore.nome, cin.attore.cognome
FROM (cin.film JOIN cin.recita ON film.id_film = recita.film) JOIN cin.attore ON attore.id_attore=recita.attore;
