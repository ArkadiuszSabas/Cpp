#include <iostream>
#include "sales.hpp"

namespace SALES   // jesli deklaracje w pliku naglowkowym sa w przestrzeni nazw "SALES" to i w pliku zrodlowym definicje tych dekalracji TAKZE musza byc w tej przestrzeni nazw
{                 // nastepuje tutaj uzupelnienie dekalracji z pliku naglowkowego juz konkretnymi definicjami tych funkcji
    void setSales(Sales & s, const double ar[], int n)
    {
        s.min = ar[0];
        s.max = ar[0];
        double sum = 0;

        for(int i = 0; i < n; i++)
        {
           s.sales[i] = ar[i];
           if (ar[i] < s.min) s.min = ar[i];
           if (ar[i] > s.max) s.max = ar[i];
           sum += ar[i];
        }
        s.average = sum/4;
    }

    void setSales(Sales & s)
    {
        using std::cin;
        using std::cout;
        using std::endl;

        double sum = 0;
        cout << "Podaj sprzedaz za kwartal nr " << 1 << endl;
        cin >> s.sales[0];

        s.min = s.sales[0];
        s.max = s.sales[0];

        for(int i = 1; i < QUARTERS; i++)
        {
           cout << "Podaj sprzedaz za kwartal nr " << i+1 << endl;
           cin >> s.sales[i];
           if (s.sales[i] < s.min) s.min = s.sales[i];
           if (s.sales[i] > s.max) s.max = s.sales[i];
           sum += s.sales[i];
        }
        s.average = sum/4;
    }

    void showSales(const Sales & s)
    {
        using std::cout;
        using std::endl;
        // brakuje jeszcze sales[]
        cout << "Srednia: " << s.average << " , max: " << s.max << " , min: " << s.min << endl;

    }
}
