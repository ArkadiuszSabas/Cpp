#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int wielkoscSlowa = 100;

int main()
{
    cout << "Podaj slowa (kiedy skonczysz, napisz \"gotowe\")" << endl;
    char slowa[wielkoscSlowa];
    cin >> slowa;    // pobiera pare slow do entera na raz (taka jest tresc zadania)

    int licznikSlow = 0;

    while (strcmp(slowa, "gotowe"))
    {
        ++licznikSlow;
        cin >> slowa;
    }

    cout << "Ilosc slow do slowa \"gotowe\" wynosi " << licznikSlow;

    return 0;
}
