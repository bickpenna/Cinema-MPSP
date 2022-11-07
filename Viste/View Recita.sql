/**CREA VIEW CAST e FILM**/
CREATE VIEW cin.RecitaLabeledv
AS SELECT  cin.film.titolo, cin.film.id_film, cin.attore.id_attore, cin.attore.nome, cin.attore.cognome
FROM (cin.film JOIN cin.recita ON film.id_film = recita.film) JOIN cin.attore ON attore.id_attore=recita.attore;
/*-------------------------------*/