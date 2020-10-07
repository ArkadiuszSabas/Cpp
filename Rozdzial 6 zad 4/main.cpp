#include <iostream>

using namespace std;

const int strsize = 30;
const int iloscCzlonkowZakonu = 3;

struct zpdw
{
    char imie[strsize];
    char stanowisko[strsize];
    char pseudozpdw[strsize];
    int preferencje;  //0=imie, 1=stanowisko, 2=pseudonim
};

void wyswietlCzlonkow(zpdw czlonk[], char znak);

int main()
{

    zpdw czlonkowie[iloscCzlonkowZakonu] =
    {
        {"Arek", "Mistrz", "RapTiz", 2},
        {"Karol", "IT Assistant", "Zgred", 0},
        {"Zenek", "DevOps", "Wesolek", 0}
    };

    cout << "Zakon Programistow Dobrej Woli\n"
        << "a. lista wg imion           b. lista wg stanowisk\n"
        << "c. lista wg pseudonimow     d. lista wg preferencji\n"
        << "q. koniec\n";


    char ch;
    while (cin >> ch)
    {
        if ('a' == ch || 'b' == ch || 'c' == ch || 'd' == ch)
        {
            wyswietlCzlonkow(czlonkowie, ch);
        }
        else if ('q' == ch)
        {
            cout << "Do zobaczenia\n";
            exit(0);
        }
        else cout << "Podales zly znak!\n";
    }

    return 0;
}


// FUNCTIONS
void wyswietlCzlonkow(zpdw czlonk[], char znak)
{
    for (int i = 0; i<iloscCzlonkowZakonu; i++)
    {
        if (znak == 'a') cout << czlonk[i].imie << endl;
        else if (znak == 'b') cout << czlonk[i].stanowisko << endl;
        else if (znak == 'c') cout << czlonk[i].pseudozpdw << endl;
        else if (znak == 'd')
        {
            switch (czlonk[i].preferencje)
            {
                case 0 : cout << czlonk[i].imie << endl; break;
                case 1 : cout << czlonk[i].stanowisko << endl; break;
                case 2 : cout << czlonk[i].pseudozpdw << endl; break;
            }
        }
    }
}

