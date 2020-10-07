#include <iostream>
#include <fstream>
#include <cstdlib> // do exitu ?

using namespace std;

int main()
{

    ifstream inFile; // stworzenie obiektu ifstream
    inFile.open("testowyplik.txt");

    if (!inFile.is_open())
    {
        cout << "Otwarcie pliku nie powiodlo sie!!!";
        exit(EXIT_FAILURE);
    }

    // ODCZYT ZNAK PO ZNAKU. LICZY TAKZE ENTER! Obiektu ifstream uzywa sie tak samo jak obiektu cin.
    // by pominac biale znaki mozna uzyzc inFile >> znak
    int iloscZnakowWPliku=0;
    char znak;
    while(inFile.get(znak))
    {
        cout<<znak;          //wypisz to co wczyta³es z pliku
        ++iloscZnakowWPliku;
    }


    cout << "\nPlik zawieral " << iloscZnakowWPliku << " znakow.\n";
    inFile.close();

    return 0;
}
