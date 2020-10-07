#include <iostream>

using namespace std;

int main()
{
    cout << "Podaj pierwsza liczbe calkowita: ";
    int a;
    cin >> a;

    cout << "Podaj druga liczbe calkowita wieksza od pierwszej: ";
    int b;
    cin >> b;

    int suma=0;
    for (int i=a; i<=b; i++)
    {
        suma +=i;
    }

    cout << "Suma liczb od " << a << " do " << b << " wynosi: " << suma << endl;

    return 0;
}
