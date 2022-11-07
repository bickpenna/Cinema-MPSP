CREATE SCHEMA cin;

/**CREA TABELLA CINEMA**/
CREATE TABLE cin.Cinema
(
    ID_Cinema SERIAL,  --PK
    Nome VARCHAR(32),
    IndirizzoCitta VARCHAR(60),
    NumTelefono INTEGER,

    CONSTRAINT cinema_pk PRIMARY KEY (ID_Cinema)
);
/*-------------------------------*/


/**CREA TABELLA SALA**/
CREATE TABLE cin.Sala(
	ID_Sala SERIAL,     --PK
	Numero INTEGER,
    Schermo VARCHAR(64),
    ImpiantoAudio VARCHAR(32),
    ImpiantoVideo VARCHAR(32),
    Dimensione DOUBLE PRECISION,
    Cinema SERIAL,  --FK

    CONSTRAINT sala_pk PRIMARY KEY(ID_Sala),
    CONSTRAINT cinema_fk FOREIGN KEY (Cinema) REFERENCES cin.Cinema(ID_Cinema)
);
/*-------------------------------*/


/**CREA TABELLA POSTO**/
CREATE TABLE cin.Posto
(
    Fila CHAR,             --PK
    Numero INTEGER,        --PK
    Sala SERIAL,  --FK     --PK

    CONSTRAINT posto_pk PRIMARY KEY(Fila, Numero, Sala),
    CONSTRAINT Sala_fk FOREIGN KEY (Sala) REFERENCES cin.Sala(ID_Sala)
);
/*-------------------------------*/

/**CREA TABELLA CLIENTE**/
CREATE TABLE cin.Cliente
(
    username VARCHAR(16),      --PK
    password VARCHAR(16),
    dataRegistrazione DATE,

    CONSTRAINT cliente_pk PRIMARY KEY (username)
);
/*-------------------------------*/

/**CREA TABELLA BIGLIETTO**/
CREATE TYPE cin.Modalità_Acquisto as enum ('Online', 'Prenotato', 'Botteghino');
CREATE TABLE cin.Biglietto
(
    ID_Biglietto SERIAL,     --PK
    DataEmissione DATE,
    Prezzo DOUBLE PRECISION,
    modalita_acq cin.Modalità_Acquisto,
    Fila CHAR,            --FK
    Numero INTEGER,       --FK
    Sala SERIAL,          --FK
	Proiezione SERIAL,    --FK
	Username VARCHAR(16), --FK

    CONSTRAINT biglietto_pk PRIMARY KEY (ID_Biglietto),
    CONSTRAINT posto_fk FOREIGN KEY (Fila, Numero, Sala) REFERENCES cin.posto(Fila, Numero, Sala),
	CONSTRAINT cliente_fk FOREIGN KEY (Username) REFERENCES cin.cliente(username)
);

/**CREA TABELLA FILM**/
CREATE TABLE cin.Film(
    ID_Film SERIAL,
    Titolo VARCHAR(60),
    Anno int,
    Regista VARCHAR(16),

    CONSTRAINT film_pk PRIMARY KEY (ID_Film)
);
/*-------------------------------*/

/**CREA TABELLA RECENSIONE**/
CREATE TABLE cin.Recensione
(
    ID_Recensione SERIAL,     --PK
    Data DATE,
    Testo VARCHAR(250),
    Username VARCHAR(16),
    Film SERIAL,            --FK

    CONSTRAINT feedback_pk PRIMARY KEY (ID_Recensione),
    CONSTRAINT cliente_fk FOREIGN KEY (username) REFERENCES cin.cliente(username),
    CONSTRAINT film_fk FOREIGN KEY (Film) REFERENCES cin.film(ID_Film)
);
/*-------------------------------*/

/**CREA TABELLA ATTORI**/
CREATE TABLE cin.Attore
(
    ID_Attore SERIAL,        --PK
    Nome VARCHAR(16),
    Cognome VARCHAR(16),
    DataNascita DATE,

    CONSTRAINT Attore_PK PRIMARY KEY(ID_Attore)
);
/*-------------------------------*/

CREATE TABLE cin.Recita
(
    Attore SERIAL,     --FK
    Film   SERIAL,     --FK

    CONSTRAINT recita_att_fk  FOREIGN KEY (Attore) REFERENCES cin.Attore(ID_Attore),
    CONSTRAINT recita_film_fk FOREIGN KEY (Film)   REFERENCES cin.Film(ID_Film)
);

/**CREA TABELLA PROIEZIONE**/
CREATE TABLE cin.Proiezione(
    ID_Proiezione SERIAL,
    Data date,
    oraInizio time,
    oraFine time,
    Sala SERIAL,     --FK
    Film SERIAL,     --FK

    CONSTRAINT IDproiezione_pk PRIMARY KEY (ID_proiezione),
    CONSTRAINT sala_fk FOREIGN KEY (sala) REFERENCES cin.sala(ID_Sala),
    CONSTRAINT film_fk FOREIGN KEY (film) REFERENCES cin.film(ID_Film)
);
/*-------------------------------*/

--Aggiungo chiave esterna Proiezione da cin.proiezione
ALTER TABLE cin.biglietto
ADD CONSTRAINT proiezione_fk FOREIGN KEY (Proiezione) REFERENCES cin.proiezione(ID_proiezione);

/**CREA TABELLA ANTEPRIMA**/
CREATE TABLE cin.Trailer(
    ID_Trailer SERIAL,
    Durata INTEGER,
    DataUscita DATE,
    Proiezione SERIAL,    --FK
    Film SERIAL,          --FK

    CONSTRAINT trailer_pk PRIMARY KEY (ID_Trailer),
    CONSTRAINT film_fk FOREIGN KEY (film) REFERENCES cin.film(ID_Film),
    CONSTRAINT proiezione_fk FOREIGN KEY (proiezione) REFERENCES cin.proiezione(ID_proiezione)
);
/*-------------------------------*/

/**CREA TABELLA SPOT**/
CREATE TABLE cin.Spot(
    ID_Spot SERIAL,
    Azienda VARCHAR(16),
    Durata INTEGER,
    Proiezione SERIAL,      --FK

    CONSTRAINT spot_pk PRIMARY KEY (ID_spot),
    CONSTRAINT proiezione_fk FOREIGN KEY (proiezione) REFERENCES cin.proiezione(ID_proiezione)
);
/*-------------------------------*/

/**CREA TABELLA Biglietto-Utente**/
CREATE TABLE cin.BigliettoUtente(
    Biglietto SERIAL,
    Username VARCHAR(16), --FK

    CONSTRAINT biglietto_fk FOREIGN KEY (Biglietto) REFERENCES cin.biglietto(id_biglietto),
    CONSTRAINT cliente_fk FOREIGN KEY  (Username) REFERENCES cin.cliente(username)
);
/*-------------------------------*/
