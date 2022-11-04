CREATE SCHEMA cin;

/**CREA TABELLA CINEMA**/
CREATE TABLE cin.Cinema(
    ID_Cinema SERIAL,
    Nome VARCHAR(32),
    IndirizzoCitta VARCHAR(60),
    NumTelefono VARCHAR(12),

    CONSTRAINT cinema_pk PRIMARY KEY (ID_Cinema)
);
/*-------------------------------*/


/**CREA TABELLA SALA**/
CREATE TABLE cin.Sala(
    ID_Sala SERIAL,
    Numero INTEGER,
    Schermo VARCHAR(16),
    ImpiantoAudio VARCHAR(16),
    ImpiantoVideo VARCHAR(16),
    Dimensione DOUBLE PRECISION,
    Cinema VARCHAR(16),

    CONSTRAINT sala_pk PRIMARY KEY(ID_Sala),
    CONSTRAINT cinema_fk FOREIGN KEY (Cinema) REFERENCES cin.Cinema(ID_Cinema)
);
/*-------------------------------*/


/**CREA TABELLA POSTO**/
CREATE TABLE cin.Posto(
    Fila CHAR,
    Numero INTEGER,
    Sala SERIAL,
    Cinema VARCHAR(16),

    CONSTRAINT posto_pk PRIMARY KEY(Fila, Numero, Sala),
    CONSTRAINT Sala_fk FOREIGN KEY (Sala) REFERENCES cin.Sala(ID_Sala)
);
/*-------------------------------*/


/**CREA TABELLA BIGLIETTO**/
CREATE TYPE cin.Modalità_Acquisto as enum ('Online', 'Prenotato', 'Botteghino');

CREATE TABLE cin.Biglietto(
    ID_Biglietto SERIAL,
    DataEmissione DATE,
    Prezzo DOUBLE PRECISION,
    Proiezione SERIAL,
    modalità cin.Modalità_Acquisto,
    Fila CHAR,
    Numero INTEGER,
    Sala SERIAL,

    CONSTRAINT biglietto_pk PRIMARY KEY (ID_Biglietto),
    CONSTRAINT posto_fk FOREIGN KEY (Fila, Numero, Sala) REFERENCES cin.posto(Fila, Numero, Sala)
);


/*Creo colonna Username in biglietto*/
ALTER TABLE cin.biglietto
ADD COLUMN Username VARCHAR(16);
/*-------------------------------*/


/**CREA TABELLA CLIENTE**/
CREATE TABLE cin.Cliente(
    username VARCHAR(16),
    password VARCHAR(16),
    dataRegistrazione DATE,

    CONSTRAINT cliente_pk PRIMARY KEY (username)
);
/*-------------------------------*/

--Aggiungo chiave esterna da cliente
ALTER TABLE cin.biglietto
ADD CONSTRAINT cliente_fk FOREIGN KEY (Username) REFERENCES cin.cliente(username);

/**CREA TABELLA FILM**/
CREATE TABLE cin.Film(
    ID_Film VARCHAR(16),
    Titolo VARCHAR(16),
    Anno int,
    Regista VARCHAR(16),

    CONSTRAINT film_pk PRIMARY KEY (ID_Film)
);
/*-------------------------------*/

/**CREA TABELLA RECENSIONE**/
CREATE TABLE cin.Recensione(
    ID_Recensione VARCHAR(16),
    Data DATE,
    Testo VARCHAR(250),
    Username VARCHAR(16),
    Film VARCHAR(16),

    CONSTRAINT feedback_pk PRIMARY KEY (ID_Recensione),
    CONSTRAINT cliente_fk FOREIGN KEY (username) REFERENCES cin.cliente(username),
    CONSTRAINT film_fk FOREIGN KEY (Film) REFERENCES cin.film(ID_Film)
);
/*-------------------------------*/

/**CREA TABELLA ATTORI**/
CREATE TABLE cin.Attore(
    Nome VARCHAR(16),
    cognome VARCHAR(16),
    DataNascita DATE,
    Film VARCHAR(16),

    CONSTRAINT attori_pk PRIMARY KEY (nome, cognome, dataNascita),
    CONSTRAINT film_fk FOREIGN KEY (film) REFERENCES cin.film(ID_film)
);
/*-------------------------------*/

/**CREA TABELLA PROIEZIONE**/
CREATE TABLE cin.Proiezione(
    ID_proiezione VARCHAR(16),
    Data date,
    oraInizio time,
    oraFine time,
    Sala INTEGER,
    Cinema VARCHAR(16),
    Film VARCHAR(16),
    

    CONSTRAINT IDproiezione_pk PRIMARY KEY (ID_proiezione),
    CONSTRAINT sala_fk FOREIGN KEY (sala, cinema) REFERENCES cin.sala(numero, cinema),
    CONSTRAINT film_fk FOREIGN KEY (film) REFERENCES cin.film(ID_Film)
);
/*-------------------------------*/

--Aggiungo chiave esterna Proiezione da cin.proiezione
ALTER TABLE cin.biglietto
ADD CONSTRAINT proiezione_fk FOREIGN KEY (Proiezione) REFERENCES cin.proiezione(ID_proiezione);

/**CREA TABELLA ANTEPRIMA**/
CREATE TABLE cin.Trailer(
    ID_Trailer VARCHAR(16),
    Durata INTEGER,
    DataUscita DATE,
    Proiezione VARCHAR(16),
    Film VARCHAR(16),

    CONSTRAINT trailer_pk PRIMARY KEY (ID_Trailer),
    CONSTRAINT film_fk FOREIGN KEY (film) REFERENCES cin.film(ID_Film),
    CONSTRAINT proiezione_fk FOREIGN KEY (proiezione) REFERENCES cin.proiezione(ID_proiezione)
);
/*-------------------------------*/

/**CREA TABELLA SPOT**/
CREATE TABLE cin.Spot(
    ID_Spot VARCHAR(16),
    Azienda VARCHAR(16),
    Durata INTEGER,
    Proiezione VARCHAR(16),

    CONSTRAINT spot_pk PRIMARY KEY (ID_spot),
    CONSTRAINT proiezione_fk FOREIGN KEY (proiezione) REFERENCES cin.proiezione(ID_proiezione)
)
/*-------------------------------*/