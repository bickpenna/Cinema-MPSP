#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


char *f_username(char *mod_acquisto)
{
    int n=0;
    if(strcmp(mod_acquisto, "Botteghino")==0) return "NULL";
    else
    n=(rand() %7) + 1;
    if(n==1) return "bickpenna";
    if(n==1) return "ssimone-p";
    if(n==2) return "Goku";
    if(n==3) return "vegeta";
    if(n==4) return "lorenzo-tecchia";
    if(n==5) return "homer";
    if(n==6) return "giorgiovanni";
    if(n==7) return "giorgia"; 
}

//char *f_mod_acquisto()
//{
//    int n=(rand() % 3) + 1;
//    if(n==1) return "Online";
//    if(n==2) return "Prenotato";
//    if(n==3) return "Botteghino";
//}

char *f_mod_acquisto(int giornoprenotazione, int giornoproiezione, int meseprenotazione, int meseproiezione)
{
    int n=0;
    if(giornoprenotazione==giornoproiezione 
      && meseprenotazione==meseproiezione) return "Botteghino";
    else
    n=(rand() % 2) + 1;
    if(n==1) return "Online";
    if(n==2) return "Prenotato";
}

void main()
{
    srand(time(NULL));
    FILE *fp=fopen("Proiezioni.txt", "r");
    FILE *fpout=fopen("biglietti.txt", "w");
    char inutile;
    int annoproiezione=0, meseproiezione=0, giornoproiezione=0;
    int orainizio=0, orafine=0;
    int sala=0, film=0;


    int meseprenotazione=0, giornoprenotazione=0;
    float prezzo=0;
    int numero_posto=0, numero_proiezione=0;
    char fila, *username=0, *mod_acquisto=0;

    for(int numero_proiezione=1; numero_proiezione<101; numero_proiezione++)
    {
        fscanf(fp, "('%d-%d-%d', '%d:00', '%d:30', %d, %d),\n", &annoproiezione, &meseproiezione, &giornoproiezione, &orainizio, &orafine, &sala, &film);
        if(giornoproiezione>=2) 
        {
            giornoprenotazione=giornoproiezione-(rand()%2);
            meseprenotazione=meseproiezione;
        }
        
        if(giornoproiezione==1 && meseproiezione>1) 
        {
            meseprenotazione=meseproiezione-1;
            giornoprenotazione=(rand()%15)+1;
        }
        
        fila=(rand() % ('A' - 'H' + 1)) + 'A';
        numero_posto=(rand()%9)+1;
        prezzo=(rand()%(50 - 30 + 1))+30;
        sala=(rand() % (15 - 1 + 1)) + 1;
        mod_acquisto=f_mod_acquisto(giornoprenotazione, giornoproiezione, meseprenotazione, meseproiezione);
        username=f_username(mod_acquisto);

        fprintf(fpout, "('%d-%d-%d', %.2f, '%s', '%c', %d, %d, %d, '%s'), \n", annoproiezione, meseprenotazione, giornoprenotazione, prezzo, mod_acquisto, fila, numero_posto, sala, numero_proiezione, username);
    }

    fclose(fp);
    fclose(fpout);
}