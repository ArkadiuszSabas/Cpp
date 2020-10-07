#include <iostream>

using namespace std;

// 4
struct pudelko
{
    char producent[40];
    float wysokosc;
    float szerokosc;
    float dlugosc;
    float pojemnosc;
};

void show_pudelko(pudelko & box);
void oblicz_objetosc(pudelko & box);

//// 7
template <typename T>
T zwrocWieksze(T a, T b);

template <> pudelko zwrocWieksze<pudelko>(pudelko a, pudelko b); // jawna specjalizacja (takie pseudo przeciazanie szablonu). NIE TWORZY ONO DEFINICJI FUNKCJI. JEST TO DALEJ TYLKO SZABLON
                                                                // ZA UTWORZENIE DEFINICJI FUNKCJI ODPOWIADA KONKRETYZACJA
// template pudelko zwrocWieksze<pudelko>(pudelko a, pudelko b); // to jest konkretyzacja i ona tworzy definicje funkcji. BRAK TUTAJ NAWIASOW TROJAKTNYCH PRZY PEIRWSZYM TEMPLATE
//NIE MOZNA W JEDNYM PLIKU UZYC JAWNYJ SPECJALIZACJI I JAWNEJ KONKRETYZACJI !!!! TO BLAD
// NIE TRZEBA TWORZYC SYGNATURY JAWNEJ KONKRETYZACJI. MOZNA UZYC JAWNEJ KONKRETYZACJI JUZ W SAMYM MAIN. PATRZ LINIA 52

int main()
{
    //4
    pudelko karton = {"Hortex", 1, 2, 5, 0};
//    pudelko & aliasKartonu = karton; //   tak sie tworzy referencje w main

//    pudelko & aliasKartonu = karton;        // TE DWA ZAPISY MOZNA W ZASADZIE TRAKTOWAC ZAMIENNIE !!!
//    pudelko * const aliasKartonu = &karton;

    show_pudelko(karton);
    oblicz_objetosc(karton);
    show_pudelko(karton);

    // 7
    double a = 5;
    double b = 8;
    double wieksze;
    wieksze = zwrocWieksze(a , b);
    cout << "Wieksa liczba to: " << wieksze << endl;

    pudelko box1 = {"Hortex", 1, 2, 5, 10};
    pudelko box2 = {"Hortex", 1, 2, 5, 20};
    pudelko wiekszePudelko;
    wiekszePudelko = zwrocWieksze(box1, box2);
    // wiekszePudelko = zwrocWieksze<pudelko>(box1, box2); // akurat tutaj to ma malo sensu. Bardziej przydaje sie to do typow prostych w ktorych zachodza niejawne konwersje, np przy mieszaniu typu int z double.
    cout << "Wieksze pudelko ma tyle pojemnosci: " << wiekszePudelko.pojemnosc << endl;



    cout << "Koniec programu" << endl;
    return 0;
}

// 4
void show_pudelko(pudelko & box)  // doslownie przekazujemy zmienne do funkcji (przez wartosc to przekazanie wartosci do kopii zmiennej, a przez referencje to przekazanie adresu zmiennych)
{
    cout << "Producent: " << box.producent << endl
        << "wysokosc: " << box.wysokosc << endl
        << "szerokosc: " << box.szerokosc << endl
        << "dlugosc: " << box.dlugosc << endl
        << "objetosc: " << box.pojemnosc << endl << endl;
}


void oblicz_objetosc(pudelko & box)  // doslownie przekazujemy zmienne do funkcji (przez wartosc to przekazanie wartosci do kopii zmiennej, a przez referencje to przekazanie adresu zmiennych)
{
         box.pojemnosc = box.wysokosc * box.szerokosc * box.dlugosc;
}


// 7
template <typename T>
T zwrocWieksze(T a, T b)
{
    if (a > b) return a;
    else return b;
}

template <> pudelko zwrocWieksze<pudelko>(pudelko a, pudelko b)
{
    if (a.pojemnosc > b.pojemnosc) return a;
    else return b;
}
