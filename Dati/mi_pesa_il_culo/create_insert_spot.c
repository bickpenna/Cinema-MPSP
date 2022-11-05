#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *f_azienda()
{
    char *azienda;
    int n=rand()%10;
    if(n==0) azienda="Adidas";
    if(n==1) azienda="Nike";
    if(n==2) azienda="Sony";
    if(n==3) azienda="Toshiba";
    if(n==4) azienda="Acer";
    if(n==5) azienda="RedBull";
    if(n==6) azienda="LG";
    if(n==7) azienda="Xiaomi";
    if(n==8) azienda="Huawei";
    if(n==9) azienda="Apple";
    if(n==10) azienda="Microsoft";

    return azienda;
}

int main()
{
    FILE *fp=fopen("insert_spot.txt", "w");
    srand(time(NULL));
    char *azienda;
    int durata=0, proiezione=0;

    for(int i=0; i<100; i++)
    {
        azienda=f_azienda();
        durata=rand()%120;
        proiezione=(rand()%500) + 1;

        fprintf(fp, "('%s', %d, %d),\n", azienda, durata, proiezione);
    }
    fclose(fp);
}