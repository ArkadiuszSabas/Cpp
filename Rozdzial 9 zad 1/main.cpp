#include <iostream>
#include "golf.hpp"

using namespace std;

int main()
{
    golf golfik = {"Zielony zuczek", 33}; // inne zainicjalizowanie struktury. W klasach pola powinnny byc provate wiec takie cos bez domyslnego konstruktora jest niemozliwe

    golf golferro;
    setgolf(golferro, "Czerwona strzala", 10);
    cout << "Wyswietlam informacje o moim golfie: " << endl;
    showgolf(golferro);

    cout << endl << "Zmieniam handicap " << endl;
    handicap(golferro, 66);
    showgolf(golferro);

    cout << endl <<"Teraz Ty sam wprowadz informacje o swoim golfie: " << endl;
    setgolf(golferro);
    cout << endl << "Wyswietlam informacje o twoim golfie: " << endl;
    showgolf(golferro);


    return 0;
}
