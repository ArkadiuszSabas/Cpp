#include <iostream>

using namespace std;

int main()
{
    //    zakres
//        0-5000     0%
//        5000-15000 10%
//        15000-35000 15%
//        >35000  20%


    double podatek=0;
    double reszta=0;
    double sumaPodatkow=0;
    int zarobek;
    cout << "Podaj swoje roczne zarobki: ";
    while (cin >> zarobek && 0 <= zarobek)
    {
       if (35000 < zarobek)
       {
           podatek = (zarobek-35000) * 0.2;
           sumaPodatkow += podatek;
           zarobek = 35000;
       }
       if (15000 < zarobek && 35000 >= zarobek)
       {
           podatek = (zarobek-15000) * 0.15;
           sumaPodatkow += podatek;
           zarobek = 15000;
       }
         if (5000 < zarobek && 15000 >= zarobek)
       {
           podatek = (zarobek-5000) * 0.1;
           sumaPodatkow += podatek;
       }

    cout << "Twoj podatek wynosi " << sumaPodatkow << " zl\n";
    sumaPodatkow=0;
    cout << "Podaj swoje roczne zarobki: ";
    }

    return 0;
}
