#include <iostream>
#include "gra.h"


int main()
{
    szubienica gra;
    //gra.nr_linii=rand()% 11+0;
    gra.ilosc_linii();
    gra.losuj_linie();
    gra.wczytaj_odpowiedzi();
    gra.ilosc_zyc = 10;
    gra.gra = true;
    while(gra.gra)
    {
    std::cout<<gra.wypisz;
    gra.podaj_odpowiedz();
    gra.sprawdz();
    }
    return 0;
}
