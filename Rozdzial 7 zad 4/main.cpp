#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
    long double prawdopodobienstwo1 = 0;
    long double prawdopodobienstwo2 = 0;
    double total, choices;
    cout << "Podaj najwieksza liczbe jaka mozesz wybrac, oraz liczbe skreslen \n";
    cout << "np 49 i 6 (polski duzy lotek, losowanie 6 liczb z 49) \n";

    if((cin >> total >> choices) && choices <= total && total > 0)
    {
        cout << "Szansa wygranej to jeden do ";
        prawdopodobienstwo1 = probability(total, choices);
        cout << prawdopodobienstwo1;
        cout << ".\n";
    }
    else
    {
        cout << "Podales zle dane, konczymy program";
        return 0;
    }

    cout << "Teraz podaj liczbe okreslajaca najwieksa liczbe w losowaniu \"Plusa\" (jednej dodatkowej liczby):  ";
    if((cin >> total) && total > 0)
    {
        cout << "Szansa wygranej w Plusie to jeden do ";
        prawdopodobienstwo2 = probability(total, 1);
        cout << prawdopodobienstwo2;
        cout << ".\n";
    }
    else
    {
        cout << "Podales zle dane, konczymy program";
        return 0;
    }

    cout << "Prawdopodobienstwo trafienia wszystkich liczb to jeden do " << prawdopodobienstwo1 * prawdopodobienstwo2;


    cout << "\nDo widzenia\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for(n = numbers, p = picks; p > 0 ; n--, p--)
    {
        result = result * n / p;
    }
    return result;
}
