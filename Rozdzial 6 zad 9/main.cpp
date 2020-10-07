#include <iostream>
#include <fstream>
#include <limits>
#include <array>
#include <string>
#include <vector>
#include <cstdlib> // do exitu ?

using namespace std;

struct wplacajacy
{
    string nazwisko;
    double kwota;
};

int main()
{

    ifstream inFile; // stworzenie obiektu ifstream
    inFile.open("plik.txt");

    if (!inFile.is_open())
    {
        cout << "Otwarcie pliku nie powiodlo sie!!!";
        exit(EXIT_FAILURE);
    }

    string linia;
    getline(inFile, linia);   // inFile >> liczbaWplacajacych chyba zostawia enter w buforze
    int liczbaWplacajacych;
    liczbaWplacajacych = atoi(linia.c_str()); // odczytanie liczby wplacajacych z pliku

    vector <wplacajacy> ludzie(liczbaWplacajacych);
    //wplacajacy * ludzie = new wplacajacy[liczbaWplacajacych];

    int index=0;
    while(getline(inFile, linia))      // getline(objekt fstream, jakis bufor)
    {
        ludzie[index].nazwisko = linia;
        getline(inFile, linia);
        ludzie[index].kwota = atoi(linia.c_str());   // atoi zamienia string na liczbe
        index++;
    }


//    for (int i=0; i<liczbaWplacajacych; i++)   // mozna tez uzyc petli for
//    {
//        getline(inFile, linia);
//        ludzie[i].nazwisko = linia;
//        getline(inFile, linia);
//        ludzie[i].kwota = atoi(linia.c_str());   // atoi zamienia string na liczbe
//    }

    cout << "Nasi Wspaniali Sponsorzy: \n";
    for(int i=0; i<liczbaWplacajacych; i++)
    {
        if (10000 <= ludzie[i].kwota) cout << ludzie[i].nazwisko << endl;
    }

    cout << "\nNasi Sponsorzy: \n";
    for(int i=0; i<liczbaWplacajacych; i++)
    {
        if (10000 > ludzie[i].kwota) cout << ludzie[i].nazwisko << endl;
    }


//    for(int i=0; i<liczbaWplacajacych; i++)   // wyswietla cale struktury
//    {
//        cout << ludzie[i].nazwisko << endl;
//        cout << ludzie[i].kwota << endl;
//    }


    inFile.close();
    return 0;
}
