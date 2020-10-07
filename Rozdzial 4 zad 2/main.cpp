#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string dessert;

    cout <<"Podaj swoje imie: " << endl;
    getline(cin, name);
    cout << "Podaj swoj ulubiony deser: " << endl;
    getline(cin, dessert);

    cout << "Mam dla ciebie " << dessert;
    cout << ", " << name << ".\n";

    return 0;
}
