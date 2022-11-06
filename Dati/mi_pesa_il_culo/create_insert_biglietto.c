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
    int n=(rand() %7) + 1;
    if(n==1) return "bickpenna";
    if(n==1) return "ssimone-p";
    if(n==2) return "Goku";
    if(n==3) return "vegeta";
    if(n==4) return "lorenzo-tecchia";
    if(n==5) return "homer";
    if(n==6) return "giorgiovanni";
    if(n==7) return "giorgia"; 
}

char *f_mod_acquisto()
{
    int n=(rand() % 3) + 1;
    if(n==1) return "Online";
    if(n==2) return "Prenotato";
    if(n==3) return "Botteghino";
}

int main()
{
    srand(time(NULL));
    FILE *fp=fopen("insert_biglietti.txt", "w");
    int anno=0, mese=0, giorno=0;
    float prezzo=0;
    int numero_posto=0, numero_proiezione=0, sala=0;
    char fila, *username=0, *mod_acquisto=0;
    for(int i=0; i<100; i++)
    {
        anno=(rand() % (2022 - 2002 + 1)) + 2002;
        mese=(rand() % 12) + 1;
        giorno=f_giorno(anno, mese);
        fila=(rand() % ('A' - 'H' + 1)) + 'A';
        numero_posto=(rand()%9)+1;
        numero_proiezione=(rand()%500) +1;
        prezzo=(rand()%(50 - 30 + 1))+30;
        sala=(rand() % (15 - 1 + 1)) + 1;
        username=f_username();
        mod_acquisto=f_mod_acquisto();
        fprintf(fp, "('%d-%d-%d', %.2f, '%s', '%c', %d, %d, %d, '%s'),\n", anno, mese, giorno, prezzo, mod_acquisto, fila, numero_posto, sala, numero_proiezione, username);
    }

    fclose(fp);
}