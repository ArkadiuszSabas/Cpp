#include <iostream>

using namespace std;

int licznikFunkcji = 0;

void wyswietlLancuch(const char * napis, int n = 0);

int main()
{
    char * zdanie = "Jestem Mistrzem C++";
    wyswietlLancuch(zdanie);
    wyswietlLancuch(zdanie);
    wyswietlLancuch(zdanie);

    int cyfra = 0;
    cout << "Podaj cyfre: ";
    cin >> cyfra;
    wyswietlLancuch(zdanie, cyfra);

    cout << "Podaj cyfre: ";
    cin >> cyfra;
    wyswietlLancuch(zdanie, cyfra);


    return 0;
}

void wyswietlLancuch(const char * napis, int n)
{
    if(0 == n)
    {
        cout << "Drugi parametr to 0. Napis wyswietle tylko raz" << endl;
        cout << napis << endl;
    }
    else
    {
        cout << "Drugi parametr rozny od 0. Funkcje wywolano " << licznikFunkcji << " razy dlatego tyle razy wyswietlimy ten napis: " << endl;
        for(int i = 0; i < licznikFunkcji; i++)
        cout << napis << endl;
    }

    ++licznikFunkcji;
}
