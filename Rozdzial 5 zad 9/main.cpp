#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    cout << "Podaj slowa (kiedy skonczysz, napisz \"gotowe\")" << endl;
    string slowa;
    cin >> slowa;    // pobiera pare slow do entera na raz (taka jest tresc zadania)

    int licznikSlow = 0;

    while (slowa != "gotowe")
    {
        ++licznikSlow;
        cin >> slowa;
    }

    cout << "Ilosc slow do slowa \"gotowe\" wynosi " << licznikSlow;

    return 0;
}
