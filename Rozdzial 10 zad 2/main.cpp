#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person one;
    Person two("Staszek");
    Person three("Jacek", "Placek");
    Person vour("Test ogracznienia lancucha znakowego", "Tutaj rozpoczyna sie imie i ten napis bedzie mial ponad 256 znakow ale i tak napis zostanie poprawnie utworzony bo przed tym zabezpiecza wyrazenie fname[limit-1] = 0 a przynajmnije mam taka nadzieje. Randomowy tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst");

    cout << "Osoba pierwsza konstruktor domyslny (nic nie wyswietli bo ustawione wszsytko na puste stringi" << endl;
    one.Show();
    one.FormalShow();

    cout << endl << "Osoba druga tylko z nazwiskiem" << endl;
    two.Show();
    two.FormalShow();

    cout << endl << "Osoba trzecia z nawiskiem i imieniem " << endl;
    three.Show();
    three.FormalShow();

    cout << endl << "Osoba czwarta testowa ze zbyt dlugim imieniem" << endl;
    vour.Show();

    return 0;
}
