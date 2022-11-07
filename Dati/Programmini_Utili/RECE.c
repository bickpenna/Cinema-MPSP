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

char *f_testo()
{
    char *nome;
    int n=(rand() %13) + 1;
    if(n==1) return "bellissimo film, mi sono emozionato";
    if(n==1) return "capolavoro assoluto, il nuovo 'quarto potere'";
    if(n==2) return "orribile, mi sanguinano gli occhi";
    if(n==3) return "film noiso, piace solo ai radical chic";
    if(n==4) return "harambe vive nelle recensioni dei film";
    if(n==5) return "film carino, ho passato un paio di ore divertendomi";
    if(n==6) return "Lezzoh proprio";
    if(n==7) return "mi fa cacare";
    if(n==8) return "bellissimo film, apprezzato";
    if(n==9) return "bella trama, peccato per la regia";
    if(n==10) return "bellissimo, affiderei al regista i miei figli";
    if(n==11) return "film piacevole";
    if(n==12) return "film non piacevole";
    if(n==13) return "forza salernitana";
}

int main(){
    srand(time(NULL));
    FILE *fp=fopen("insert_recensioni.txt", "w");
    int anno=0, mese=0, giorno=0;
    char *testo;
    char *username;
    int film;
    int i=0;

    for(i=0; i<50; i++){
        anno=(rand() % (2022 - 2002 + 1)) + 2002;
        mese=(rand() % 12) + 1;
        giorno=f_giorno(anno, mese);
        testo=f_testo();
        username=f_username();
        film=(rand() % (17 - 1 + 1)) + 1;

        fprintf(fp, "('%d-%d-%d','%s', '%s', %d),\n", anno, mese, giorno, testo, username, film);

    }
}
