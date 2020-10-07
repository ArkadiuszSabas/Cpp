#include <iostream>
#include "sales.hpp"

using namespace std;
using namespace SALES;

int main()
{
    // cout << SALES::QUARTERS; // wyswietli QUARTETS z sales.hpp  .const int QUARTERS = 3 umieszcone w namespace sprawia ze ma zasieg tylko do przestrzeni nazw SALES:: (dziala poprawnie bez operatoraz zasiegu w pliku sales.cpp i sales.hpp. NIE JEST TO DANA GLOBALNA

    double tab[SALES::QUARTERS] = {2, 4, 8, 6};

    Sales jeden;
    Sales dwa;
    Sales trzy;

    // wywolanie tej funkcje: void setSales(Sales & s, const double ar[], int n);
    setSales(jeden, tab, SALES::QUARTERS);
    cout << "Pokazuje jeden" << endl;
    showSales(jeden);

    // wywolanie tej funkcje: void setSales(Sales & s)
    setSales(dwa);
    cout << "Pokazuje dwa" << endl;
    showSales(dwa);


    // reczne przypisanie
    trzy.average = 3;
    trzy.min =1;
    trzy.max = 5;
    cout << "Pokazuje trzy" << endl;
    showSales(trzy);


    return 0;
}
