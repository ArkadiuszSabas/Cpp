#include <iostream>
#include "Sales.h"

int main()
{
    using namespace SALES;
    double ar[SALES::QUARTERS] = { 2, 4, 7 ,9};

    Sales jeden(ar, SALES::QUARTERS);

    cout << "Pokazuje jeden " << endl;
    jeden.showSales();

    cout << "Pokazuje dwa. Utworzony za pomoca domyslnego konstruktora " << endl;
    Sales dwa;   // domyslny konstruktor
    dwa.showSales();

    cout << "Jak widac jest pusty. Trzeba go wypelnic za pomoca metody setSales() " << endl;
    dwa.setSales();
    cout << "Oto jeszcze raz 'dwa'. Ma teraz dane" << endl;
    dwa.showSales();






    return 0;
}
