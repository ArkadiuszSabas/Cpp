#include <iostream>

using namespace std;


const int strsize = 40;

// program wczytuje slowa. Jesli slowem bedzie znak 'q' (pojedyczny znak) to przerywa program.
// jesli bedzie to wyraz queue lub quit program bedzie dalej dzialal

int main()
{
    cout << "Podaj slowa (pojedyncze q konczy): \n";

    string slowo;
    int samogloski = 0;
    int spolgloski = 0;
    int roznosci = 0;

    while (cin >> slowo)
    {
        if (slowo[1] == '\0' && slowo[0] == 'q' ) // jesli wyraz bedzie pojedynczym q to koniec programu
        {
            cout << "\n";
            break;
        }
        else if (isalpha(slowo[0]))  // znak jest litera
        {
            if (slowo[0] == 'a' || slowo[0] == 'e' || slowo[0] == 'o' || slowo[0] == 'u' || slowo[0] == 'i' || slowo[0] == 'y') samogloski++;
            else spolgloski++;
        }
        else roznosci++;  // znak jest czyms innym

    }

    cout << spolgloski << " slow zaczyna sie od spolglosek\n";
    cout << samogloski << " slow zaczyna sie od samoglosek\n";
    cout << roznosci << " nie zalicza sie do zadnej z tych kategorii\n";

    return 0;
}
