#include <iostream>
#include <string>

using namespace std;

struct Car
{
    string marka;
    int rokBudowy;
};

int main()
{
    cout << "Podaj liczbe katalogowanych aut: ";
    int liczbaKatalogowanychAut;
    cin >> liczbaKatalogowanychAut;
    cin.get();    // pobiera pusty znak konca lini, pozostalosc po wczytaniu liczby.
                  // mozna zapisac (cin >> liczbaKatalogowanychAut).get()   Da taki sam efekt czyli pobierze znak konca lini
                  // To jest potrzebne bo po wpisaniu liczby klikamy enter, czyli znak nowej lini zostaje w buforze
                  // jesli bedziemy chcieli pobrac inna liczbe to nic zlego sie nie stanie bo biale znaki zostana zignorowane
                  // natomiast jesli bedziemy chcieli pobrac string lub znak to bedzie problem bo pobierze wlasnie ten znak nowej lini
                  // dlatego jesli na zmiane pobieramy liczba, napis, liczba, napis to trzeba po kazdym pobraniu liczby czyscic bufor

    Car * samochody = new Car[liczbaKatalogowanychAut];

    for (int i = 0; i<liczbaKatalogowanychAut; ++i)
    {
        cout << "Samochow nr " << i+1 << endl;
        cout << "Prosze podac marke: ";
        getline(cin, samochody[i].marka); // tutaj nie ma problemu ze znakiem konca lini bo funkcja getline() go po prostu kasuje
        cout << "Podaj rok produkcji: ";
        cin >> samochody[i].rokBudowy;
        cin.get();
    }

    for (int i = 0; i<liczbaKatalogowanychAut; ++i)
    {
        cout << samochody[i].rokBudowy << " " << samochody[i].marka << endl;
    }

    return 0;
}
