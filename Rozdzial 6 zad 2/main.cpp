#include <iostream>

using namespace std;
int SIZE = 10;

int main()
{
    double datki[SIZE];
    int ilosc = 0;
    double suma = 0;

    cout << "Podaj 10 datkow lub wpisz znak nieliczbowy by zakonczyc.\n";
    for (int i=0; i<SIZE; i++)
    {
        cout << "Podaj wartosc datku nr " << i+1 << " : ";

        // cin jesli jest w warunku (np w if lub while) zwraca wartosc ktora jest konwertowana na true lub false
        // true jesli uda sie wczytac liczbe, false jesli sie nie uda. (W tym przypadku liczbe, ogolnie czy uda sie wczytac i przypisac podane cos od uzytkownika do konkretnej zmiennej)
        if (cin >> datki[i])
        {
            suma += datki[i];
            ++ilosc;
        }
        else
        {
            break;
        }
    }

    // mozna tez uzyc petli while, ktora da taki sam efekt
    // NAWET LEPIEJ JEST TO ZROBIC TYM WHILE
    // while (i<SIZE && cin >> datki[i])

     for (int i=0; i<ilosc; i++)
     {
         if (0==i) cout << "Srednia wszystkich liczb to: " << suma/ilosc << endl;
         if (suma/ilosc < datki[i]) cout << "Ta liczba jest wieksza od sredniej: " << datki[i] << endl;
     }

    return 0;
}
