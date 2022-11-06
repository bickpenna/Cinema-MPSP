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
    char *nome;
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

char *f_testo()
{
    int n=(rand() %5) + 1;
    if(n==1) return "bellissimo film, mi sono emozionato";
    if(n==1) return "capolavoro assoluto, il nuovo 'quarto potere'";
    if(n==2) return "orribile, mi sanguinano gli occhi";
    if(n==3) return "film noiso, piace solo ai radical chic";
    if(n==4) return "harambe vive nelle recensioni dei film";
    if(n==5) return "film carino, ho passato un paio di ore divertendomi";
}

int main(){
    srand(time(NULL));
    FILE *fp=fopen("insert_recensioni.txt", "w");
    int anno=0, mese=0, giorno=0;
    char *testo;
    char *username;
    int film;

    for(int i=0; i<50; i++){
        anno=(rand() % (2022 - 2002 + 1)) + 2002;
        mese=(rand() % 12) + 1;
        giorno=f_giorno(anno, mese);
        testo=f_testo();
        username=f_username();
        film=(rand() % (17 - 1 + 1)) + 1;

        fprintf(fp, "('%d-%d-%d','%s', '%s', %d),\n", anno, mese, giorno, testo, username, film);


    }
}