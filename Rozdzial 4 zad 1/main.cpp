#include <iostream>

using namespace std;

int main()
{

    cout << "Jak masz wszystkie imiona? " << endl;
    string imie;
    // cin >> imie;   wczyta dane do peirwszego bialego znaku np spacji, ale chcemy by pobral wszystkie imiona (2-3) na raz
    getline(cin, imie);
    cout << "Jak masz na nazwisko? " << endl;
    string nazwisko;
    getline(cin, nazwisko);
    cout << "Na jaka ocene zaslugujesz? " << endl;
    int ocena;
    cin >> ocena;
    cout << "ile masz lat? " << endl;
    int wiek;
    cin >> wiek;
    cout << endl << "Nazwisko: " << nazwisko << ", " << imie << endl;
    cout << "Ocena: " << ocena-1 << endl;
    cout << "wiek: " << wiek << endl;

    return 0;
}


