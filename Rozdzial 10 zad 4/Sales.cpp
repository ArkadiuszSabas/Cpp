#include <iostream>
#include "Sales.h"

namespace SALES
{
    Sales::Sales()
    {
        for(int i = 0; i < QUARTERS; i++)
        {
            sales[i] = 0;
        }
        min = max = average = 0;
    }

    Sales::Sales(double ar[], int n)
    {
        min = ar[0];
        max = ar[0];
        double sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sales[i] = ar [i];
            if (ar[i] < min) min = ar[i];
            if (ar[i] > max) max = ar[i];
            sum += ar[i];
        }
        average = sum/4;
    }

    void Sales::showSales() const
    {
        cout << "Dane kazdego kwartalu: ";
        for (int i = 0; i < QUARTERS; ++i)
        {
            cout << sales[i] << ", ";
        }
        cout << "Srednia: " << average << " , max: " << max << " , min: " << min << endl;
    }

    void Sales::setSales()
    {
        double ar[QUARTERS];
        cout << "Podaj sprzedaz za kwartal nr " << 1 << endl;
        cin >> ar[0];
        for(int i = 1; i < QUARTERS; i++)
        {
            cout << "Podaj sprzedaz za kwartal nr " << i+1 << endl;
            cin >> ar[i];
        }

        Sales temp(ar, QUARTERS); // stworzenie tymczasowego obiektu za pomoca konstruktora i przypisanie go do oiektu na ktorym wywolano metode setSales()
        *this = temp;
    }



}
