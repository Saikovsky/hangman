#ifndef gra_h
#define gra_h
#include <iostream>

class szubienica
{
public:
    std::string tajny_kod;
    std::string wypisz;
    std::string wpisz;
    int nr_linii;
    int ilosc_zyc;
    bool gra;

    void losuj_linie();
    void ilosc_linii();
    void wczytaj_odpowiedzi();
    void podaj_odpowiedz();
    void sprawdz();

};
#endif
