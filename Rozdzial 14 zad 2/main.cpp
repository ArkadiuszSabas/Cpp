#include <iostream>
#include <string>
#include <string.h>
#include <utility>  // dla klasy pair
#include <valarray> // dla klasy valarray

using namespace std;

class Wine : private pair<valarray<int>, valarray<int>> // w pair bedzia przechowywane dane o roczniku i ilosci butelek tego rocznika. Trzeba od razu podac dokladny szablon
{
    private:
        typedef valarray<int> ArrayInt;  // typedef ummieszczamy w private dzieki temu mozna jej uzywac wewnatrz klasy Wine, ale juz po za klasa nie
        typedef pair<ArrayInt, ArrayInt> PairArray;

        string label;              // nazwa wina
        int years;                 // ilosc roznych rocznikow tego wina

    public:
        Wine() { }
        // ZAWSZE W KOSNTRUKTORACH TRZEBA INICJALIZOWAC WSZYSTKIE SKALDOWE KLASY !!! NAWET W KONSTRUKTORZE 3 GDZIE NIE MA WSZYSTKICH DANYCH
        Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), years(y), pair(ArrayInt(yr, y), ArrayInt(bot, y)) {}  // uzywamy konstruktorow klas valarray i pair.
        Wine (const char * l, int y) : label(l), years(y), pair(ArrayInt(y), ArrayInt(y)) {} // stworzy dwie puste tablice


        void GetBottles()  // prosi uzytkownika o konkretne rocznik i ilosci butelek (uzupelnienie trzeciego konstruktora)
        {
            cout << "Podaj dane o winie " << label << " dla " << years << " rocznikow:" << endl;
            for(int i = 0; i < years; i++)
            {
               cout << "Podaj rocznik: ";
               cin >> pair::first[i];
               cout << "Podaj liczbe butelek: ";
               cin >> pair::second[i];
            }
        }

        string & Label() { return label; }  // zwraca nazwe wina
        int sum() {  return this->pair::second.sum(); }  // zwraca laczna ilosc butelek z drugiego obiektu pair. Ogolnie laczna ilosc butelek tego wina
        void Show()
        {
            cout << "Wino: " << label << endl;
            cout << "\tRocznik\tButelki\n";
            for(int i = 0; i < years; i++)
            {
               cout << "\t" << pair::first[i];
               cout << "\t" << pair::second[i] << endl;
            }
        }
};

int main()
{
    cout << "Podaj nazwe wina: " ;
    char lab[50];
    cin.getline(lab, 50);
    cout << "Podaj liczbe rocznikow: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);   // zapisuje nazwe, liczbe rocznikow i przekazuje informacje o tej liczbie do tablicy

    holding.GetBottles();   // pobiera dane o roczniku i liczbie butelek
    holding.Show();  // wyswietla zawartosc obiektu

    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };

    // tworzy nowy obiekt, inicjalizuje za pomoca danych w tablicach y oraz b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout <<"Laczna liczba butelek wina " << more.Label() // uzywa metody Label()
        << ": " << more.sum() << endl; // uzywa metody sum()
    cout << "Koniec \n";

    return 0;
}
