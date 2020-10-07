#include <iostream>
#include "kontobankowe.h"

using namespace std;

int main()
{
    KontoBankowe Sonia = {"Sonia", "512778373"};     // konstruktor z domyslnym saldem
    KontoBankowe Arek = {"Arek", "516994501", 100};  // pelna inicjalizacja obiektu

    cout << "Pokazuje Sonia " << endl;
    Sonia.pokaz();

    cout << "Pokazuje Arek " << endl;
    Arek.pokaz();

    cout << "Dodaje do Sonia 200 zl " << endl;
    Sonia.deponuj(200);

    cout << "Pokazuje Sonia " << endl;
    Sonia.pokaz();

    cout << "Zabieram od Arek 50 zl " << endl;
    Arek.podejmij(150);
    cout << "Pokazuje Arek " << endl;
    Arek.pokaz();


    return 0;
}
