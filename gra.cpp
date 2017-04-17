#include <iostream>
#include <fstream>
#include "gra.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

void szubienica::wczytaj_odpowiedzi()
{
    std::fstream haslo;
    haslo.open("hasla.txt",std::ios::in);
    std::string linia;
    int numer=1;
    while(getline(haslo,linia))
    {
        if(nr_linii==numer) tajny_kod=linia;
        numer++;
    }
    std::string jakiesGowno(tajny_kod.length(),'_');
    wypisz = jakiesGowno;
}

void szubienica::podaj_odpowiedz()
{
    std::cout<<std::endl;
    std::cin>>wpisz;
    for(int i=0;i<wpisz.length();i++)
    {
        if(wpisz[i]<90 && wpisz[i]>65)
        {
            wpisz[i]=wpisz[i]+32;
            //std::cout<<wpisz[i];
        }
    }
}

void szubienica::sprawdz()
{

    for(int i = 0;i<wpisz.length();i++)
        {
            std::size_t znalezione = tajny_kod.find(wpisz[i]);
            if(znalezione==std::string::npos)
            {
                std::cout<<"Nie znaleziono znaku!"<<std::endl;
                ilosc_zyc--;
            }
            if(znalezione!=std::string::npos)
            {
                do
                {
                    wypisz[znalezione]=tajny_kod[znalezione];
                    znalezione=tajny_kod.find(wpisz[i],znalezione+1);
                }while(znalezione!=std::string::npos);
            }
            if(ilosc_zyc<=0)
            {
                std::cout<<"Przegrales!"<<" "<<tajny_kod<<std::endl;
                gra = false;
                exit(0);
            }
        }
    if(wypisz.compare(tajny_kod)==0)
    {
        std::cout<<"Wygrales!"<<" "<<tajny_kod<<std::endl;
        gra=false;
    }
}

void szubienica::ilosc_linii()
{
    std::fstream hasla;
    hasla.open("hasla.txt",std::ios::in);
    std::string linie;
    int i = 0;
    while(getline(hasla,linie))
    {
        ++i;
    }
    hasla.close();
    nr_linii = i;
}

void szubienica::losuj_linie()
{
    srand(time(NULL));
    int los = nr_linii;
    nr_linii = rand()% los + 0;
}
