#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int main(){
    srand(time(NULL));
    FILE *fspot=fopen("insert_spot.txt", "w");

    char *aziendaSpot;
    int durataSpot=0;

    for(int i=1; i<501; i++){
        for(int j=0; j<5; j++){
            aziendaSpot=f_azienda();
            durataSpot=rand()%120;
            fprintf(fspot, "('%s', %d, %d),\n", aziendaSpot, durataSpot, i);
        }
    }
    fclose(fspot);
}