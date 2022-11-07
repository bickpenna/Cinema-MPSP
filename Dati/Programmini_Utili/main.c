#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int f_giorno(int anno, int mese)
{
    int giorno=0;
    if(mese==1 || mese==3 || mese==5 || mese==7 || mese==8 || mese==10 || mese==12)
    {
        giorno=(rand() % (31 - 1 + 1)) + 1;
    }
    if(mese==2)
    {
        if(anno%400==0 || (anno%4==0 && !(anno%100==0)))
        {
            giorno=(rand() % (29 - 1 + 1)) + 1;
        }
        else
        giorno=(rand() % (28 - 1 + 1)) + 1;
    }

    else
    {
        giorno=(rand() % (30 - 1 + 1)) + 1;
    }

    return giorno;

}

char *f_username()
{
    int n=(rand() %26) + 1;
    if(n==26) return "bickpenna";
    if(n==1) return "ssimone-p";
    if(n==2) return "Goku";
    if(n==3) return "vegeta";
    if(n==4) return "lorenzo-tecchia";
    if(n==5) return "homer";
    if(n==6) return "giorgiovanni";
    if(n==7) return "giorgia"; 
    if(n==8) return "stefano"; 
    if(n==9) return "andrew.img"; 
    if(n==10) return "lucadifassa"; 
    if(n==11) return "Zeb89"; 
    if(n==12) return "Stormone"; 
    if(n==13) return "Rambone"; 
    if(n==14) return "Lumix"; 
    if(n==15) return "Giovanna"; 
    if(n==16) return "Sorgesana"; 
    if(n==17) return "Santanna"; 
    if(n==18) return "geriko3"; 
    if(n==19) return "GGPOZ"; 
    if(n==20) return "reabateon"; 
    if(n==21) return "mariagrazia"; 
    if(n==22) return "accistef"; 
    if(n==23) return "nutella"; 
    if(n==24) return "frisk"; 
    if(n==25) return "wikipedia"; 
}

char *f_mod_acquisto(int n)
{
    if(n==1) return "Online";
    if(n==2) return "Prenotato";
    if(n>2) return "Botteghino";
}

void generaBiglietto(FILE *fbiglietti, FILE *fbigl_Utente, int idBiglietto, int anno, int mese, int giorno, float prezzo, int sala, int numero_proiezione){
    char fila;
    int numero_posto;

    int acquisto=0;
    char *username=0;
    char *mod_acquisto=0;

    fila=(rand() % ('A' - 'H' + 1)) + 'A';
    numero_posto=(rand()%9)+1;

    acquisto=(rand() % 50) + 1;
    mod_acquisto=f_mod_acquisto(acquisto);

    if(acquisto<3){
        username=f_username();
        fprintf(fbigl_Utente, "(%d, '%s'),\n", idBiglietto, username);
    }

    fprintf(fbiglietti, "('%d-%d-%d', %.2f, '%s', '%c', %d, %d, %d),\n", anno, mese, giorno, prezzo, mod_acquisto, fila, numero_posto, sala, numero_proiezione);
}

void generaTrailer(FILE *ftrailer, int numero_proiezione){
    int annoTrailer=0, meseTrailer=0, giornoTrailer=0;
    int durataTrailer=0;
    int filmTrailer=0;

    filmTrailer=(rand() % (17 - 1 + 1)) + 1;
    durataTrailer=rand()%120;
    annoTrailer=(rand() % (2022 - 2002 + 1)) + 2002;
    meseTrailer=(rand() % 12) + 1;
    giornoTrailer=f_giorno(annoTrailer, meseTrailer);

    fprintf(ftrailer, "(%d, '%d-%d-%d', %d, %d),\n", durataTrailer, annoTrailer, meseTrailer, giornoTrailer, filmTrailer, numero_proiezione);
}

int main()
{
    srand(time(NULL));
    FILE *fbiglietti=fopen("insert_biglietti.txt", "w");
    FILE *fproiezioni=fopen("insert_proiezioni.txt", "w");
    FILE *fbigl_Utente=fopen("insert_biglietto_utente.txt", "w");
    FILE *ftrailer=fopen("insert_trailer.txt", "w");

    int anno=0, mese=0, giorno=0;
    int orainizio=0, orafine=0;

    int numero_proiezione=0, sala=0;
    float prezzo=0;
    int film;

    int nBiglietti;
    int idBiglietto=0;

    for(int i=1; i<501; i++)
    {
        anno=(rand() % (2022 - 2002 + 1)) + 2002;
        mese=(rand() % 12) + 1;
        giorno=f_giorno(anno, mese);
        orainizio=(rand() % (21 - 16 + 1)) + 16;
        orafine=orainizio+2;
        nBiglietti=(rand() % (90 - 10 + 1)) + 10;
        
        numero_proiezione=i;
        sala=(rand() % (15 - 1 + 1)) + 1;
        prezzo=(rand()%(50 - 30 + 1))+30;
        film=(rand() % (17 - 1 + 1)) + 1;

        fprintf(fproiezioni, "('%d-%d-%d', '%d:00', '%d:30', %d, %d),\n", anno, mese, giorno, orainizio, orafine, sala, film);

        

        for(int y=0; y<8; y++){
            generaTrailer(ftrailer, numero_proiezione);
        }

        for(int j=0; j<nBiglietti; j++){
            idBiglietto++;
            generaBiglietto(fbiglietti, fbigl_Utente, idBiglietto, anno, mese, giorno, prezzo, sala, numero_proiezione);
        }

    }

    fclose(fbiglietti);
    fclose(fbigl_Utente);
    fclose(fproiezioni);
    fclose(ftrailer);
}