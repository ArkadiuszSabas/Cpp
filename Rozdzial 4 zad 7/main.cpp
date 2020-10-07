#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
    string nazwaFirmy;
    double srednica;
    double waga;
};

// STRUCTUERS
Pizza stworzPizze();
void wyswietlPizze(Pizza);

// MAIN
int main()
{
    Pizza pizza;
    pizza = stworzPizze();
    wyswietlPizze(pizza);

    return 0;
}

// FUNCTIONS
Pizza stworzPizze()
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

    Pizza pizza = {nazwaFirmy, srednica, waga};

    return pizza;
}

void wyswietlPizze(Pizza pizza)
{
    cout << "Twoja pizza to: " << endl;
    cout << pizza.nazwaFirmy << endl;
    cout << pizza.srednica << endl;
    cout << pizza.waga << endl << endl;
}



