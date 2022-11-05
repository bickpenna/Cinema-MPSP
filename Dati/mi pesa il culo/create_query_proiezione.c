#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void main()
{
    srand(time(NULL));
    FILE *fp=fopen("query.txt", "w");
    int anno=0, mese=0, giorno=0;
    int orainizio=0, orafine=0;
    int sala=0, film=0;
    int i=0;
    for(i=0; i<500; i++)
    {
        anno=(rand() % (2022 - 2002 + 1)) + 2002;
        mese=(rand() % 12) + 1;
        giorno=f_giorno(anno, mese);
        orainizio=(rand() % (21 - 16 + 1)) + 16;
        orafine=orainizio+2;
        sala=(rand() % (25 - 1 + 1)) + 1;
        film=(rand() % (17 - 1 + 1)) + 1;

        if(giorno==0) exit(-1);
        fprintf(fp, "('%d-%d-%d', '%d:00', '%d:30', %d, %d),\n", anno, mese, giorno, orainizio, orafine, sala, film);
    }

    fclose(fp);
}