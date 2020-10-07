#include <iostream>

using namespace std;

// STRUCTURES
struct Batonik
{
    string marka;
    double waga;
    int liczbaKalorii;
};

// PROTOTYPES
void wyswietlBatonik(Batonik);

// MAIN
int main()
{
    Batonik snack = {"Mocha Munch", 2.3, 350};
    wyswietlBatonik(snack);

    return 0;
}

// FUNCTIONS
void wyswietlBatonik(Batonik snack)
{
    cout << snack.marka << endl;
    cout << snack.waga << endl;
    cout << snack.liczbaKalorii << endl;
}
