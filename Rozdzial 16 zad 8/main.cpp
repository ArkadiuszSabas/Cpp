#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    vector<string> goscieBolka;
    vector<string> goscieLolka;
    vector<string> goscieBolkaLolka;

    int wybor;
    string imieGoscia;

    vector<string>::iterator it;

    while(true)
    {
        cout << "Wybierz opcje: \n"
         << "1. Dodaj goscia do listy Bolka \n"
         << "2. Wyswietl liste Bolka\n"
         << "3. Dodaj goscia do listy Lolka \n"
         << "4. Wyswietl liste Lolka \n"
         << "5. Wyswietl wspolna list Bolka i Lolka \n"
         << "0. Wyjscie \n";
         cin >> wybor;

        switch(wybor)
        {
        case 0:
            cout << "Dziekujemy za skorzystanie z programu\n";
            return 0;
            break;
        case 1:
            cout << "Podaj imie goscia: ";
            cin >> imieGoscia;
            goscieBolka.push_back(imieGoscia);
            goscieBolkaLolka.push_back(imieGoscia);
            break;
        case 2:
            sort(goscieBolka.begin(), goscieBolka.end());
            for(auto i : goscieBolka)
                cout << i << "\n";
            break;
        case 3:
            cout << "Podaj imie goscia: ";
            cin >> imieGoscia;
            goscieLolka.push_back(imieGoscia);
            goscieBolkaLolka.push_back(imieGoscia);
            break;
        case 4:
            sort(goscieLolka.begin(), goscieLolka.end());
            for(auto i : goscieLolka)
                cout << i << "\n";
            break;
        case 5:
            sort(goscieBolkaLolka.begin(), goscieBolkaLolka.end());
            it = unique(goscieBolkaLolka.begin(), goscieBolkaLolka.end()); // usuwa wszystkie duplikaty zastepujac je nastepna wartoscia, ale nie zmienia wielkosci wektora wiec trzeba to zrobic pozniej
            goscieBolkaLolka.resize(distance(goscieBolkaLolka.begin(),it));
            for(auto i : goscieBolkaLolka)
                cout << i << "\n";
            break;
        default:
            cout << "Podales zla wartosc\n";
            break;
        }
    }

    cout << "Hello world!" << endl;
    return 0;
}
