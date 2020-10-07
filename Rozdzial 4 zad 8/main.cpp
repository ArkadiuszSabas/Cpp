#include <iostream>

using namespace std;

struct Pizza
{
    string nazwaFirmy;
    double srednica;
    double waga;
};

// STRUCTUERS
void stworzPizze(Pizza *);
void wyswietlPizze(Pizza *);

// MAIN
int main()
{
    Pizza * pizza = new Pizza;
    stworzPizze(pizza);   // przekazujemy adres obiektu pizza, a funckja uzupelnia pola oryginalu
    wyswietlPizze(pizza); // przekazanie adresu pizzy z uzupelnionymi polami
    delete pizza;

    return 0;
}

// FUNCTIONS
void stworzPizze(Pizza * pizza)
{
    cout << "Podaj nazwe firmy: ";
    string nazwaFirmy;
    getline(cin, nazwaFirmy);
    cout << "Podaj srednice pizzy: ";
    double srednica;
    cin >> srednica;
    cout << "Podaj wage pizzy: ";
    double waga;
    cin >> waga;

    pizza->nazwaFirmy = nazwaFirmy;
    pizza->srednica = srednica;
    pizza->waga = waga;
}

void wyswietlPizze(Pizza * pizza)
{
    cout << "Twoja pizza to: " << endl;
    cout << pizza->nazwaFirmy << endl;
    cout << pizza->srednica << endl;
    cout << pizza->waga << endl << endl;
}
