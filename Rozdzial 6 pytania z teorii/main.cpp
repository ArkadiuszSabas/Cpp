#include <iostream>
#include <cctype> // biblioteka z funkcjami ktora sprawdz czy dany znak jest np litera, cyfra, znakiem przystankowym

using namespace std;

int main()
{

    // 4
    int waga = 120;
    if (waga >= 115 && waga < 125) cout << "Twoja waga miesci sie w zakresie 115-125\n";

    char ch = 'q';
    if (ch == 'q' || ch == 'Q') cout << "Twoj znak to q lub Q\n";

    int x = 20;
    if (x%2==0 && x!=26) cout << "Twoja liczba jest parzysta ale rozna od 26\n";

    int y = 30;
    if (y%2 == 0 && y%26!=0) cout << "Twoja liczba jest parzysta i nie jest wielokrotnoscia liczby 26\n";

    double donacja = 1100;
    int gosc = 1;
    if ((1000<=donacja && 2000 >= donacja) || 1 == gosc) cout << "Donacja ma zakres 1000-2000 lub gosc wynosi 1\n";

    char znak = 'a';
    if (isalpha(znak)) cout << "Twoj znak to litera\n";

    // 5
    // beda inne jesli zmienna to int
    int liczba = 10;
     cout << "liczba to " << liczba << endl
          << "!liczba to " << !liczba << endl
          << "a !!liczba to " << !!liczba << endl;

    // beda tym zamym jesli zmienna to bool
    bool b = true;
    cout << boolalpha    // manimuluje obiektem cout wyswietlajac wartosci bool jako bool. (normalnie bool jest konwertowany na int czyli wartosc 0 lub 1)
         << "bool to " << b << endl
         << "a !!bool to " << !!b << endl;

   // 6
   int c = -5;
   if (0>c) cout << -c << endl;
   else cout << c << endl;
   // lub
   (c < 0)? -c : c;
   //lub
   (c >=0)? c : -c;

   // 7
   char cha = 'a';

   switch (cha)
   {
       case 'A' : cout << "A"; break;
       case 'B' : cout << "B"; break;
       case 'C' : cout << "C"; break;
       case 'D' : cout << "D"; break;
       case 'E' : cout << "E"; break;
       default  : cout << "F";
   } cout << endl;

   // 8
   // W instrukcji switch lepiej uzywac znakow niz liczb. Bo gdy uzywamy liczb a ktos wpsize znak to program sie zawiesi
   // ale jesli uzyjemy znaku a ktos wpisze liczbe to program przekonwertuje ta liczbe na znak i program bedzie dzialal dalej

   // 9
   int line = 0;
   char znaczek;
   cout << "Zeby wyjsc wpisz Q \n";
   while ('Q' != znaczek)
   {
       if ('\n' == znaczek) line++;
       cin.get(znaczek);
   }

    return 0;
}
