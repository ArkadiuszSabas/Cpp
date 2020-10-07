#include <iostream>

using namespace std;

int main()
{
    cout << "Podaj liczbe wierszy: ";
    int liczbaWierszy;
    cin >> liczbaWierszy;

    // nie mozna bylo uzyc instrukcji warunkowej if
    for (int i = 1; i<=liczbaWierszy; ++i)
    {
        for (int iloscKropek = liczbaWierszy-i; iloscKropek>0; --iloscKropek)
        {
            cout.put('.');
        }
        for (int iloscGwiazdek = 1; iloscGwiazdek<=i; ++iloscGwiazdek)
        {
            cout.put('*');
        }
    cout << endl;
    }

    return 0;
}
