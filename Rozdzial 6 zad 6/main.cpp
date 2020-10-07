#include <iostream>
#include <vector>

using namespace std;

struct wplacajacy
{
    string nazwisko;
    double kwota;
};

int main()
{
    int liczbaWplacajacych;
    cout << "Podaj liczbe wplacajacych: ";
    cin >> liczbaWplacajacych;

    // mozna na dwa sposoby. VECTOR tez jest struktura dynamiczna.
    // vector <wplacajacy> ludzie(liczbaWplacajacych);
    wplacajacy * ludzie = new wplacajacy[liczbaWplacajacych];

    for(int i=0; i<liczbaWplacajacych; i++)
    {
        cout << "Podaj nazwisko: ";
        cin >> ludzie[i].nazwisko;
        cout << "Podaj kwote: ";
        cin >> ludzie[i].kwota;
    }

    cout << "Nasi Wspaniali Sponsorzy: \n";
    for(int i=0; i<liczbaWplacajacych; i++)
    {
        if (10000 <= ludzie[i].kwota) cout << ludzie[i].nazwisko << endl;
    }

    cout << "Nasi Sponsorzy: \n";
    for(int i=0; i<liczbaWplacajacych; i++)
    {
        if (10000 > ludzie[i].kwota) cout << ludzie[i].nazwisko << endl;
    }

    return 0;
}
