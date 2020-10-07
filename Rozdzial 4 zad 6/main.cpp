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
   const int tabSize = 3;
   Batonik batoniki[tabSize];

   batoniki[0] = {"aaa", 1.1, 5};
   batoniki[1] = {"bbb", 1.2, 6};
   batoniki[2] = {"ccc", 1.3, 7};

   for (int i=0; i<tabSize; i++)
        wyswietlBatonik(batoniki[i]);

    return 0;
}

// FUNCTIONS
void wyswietlBatonik(Batonik snack)
{
    cout << snack.marka << endl;
    cout << snack.waga << endl;
    cout << snack.liczbaKalorii << endl << endl;
}
