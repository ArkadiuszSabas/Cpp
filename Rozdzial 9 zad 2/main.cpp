// static.cpp -- stosowanie lokalnej zmiennej statycznej
#include <iostream>
#include <string>

using namespace std;

const int ArSize = 10;

void strcount(string str);

int main()
{
    using namespace std;
    string input;
    char next;

    cout << "WprowadŸ wiersz:\n";
    getline(cin, input);
    strcount(input);
    while(input != "")
    {
        cout << "WprowadŸ wiersz:\n";
        getline(cin, input);
        strcount(input);
    }

    cout << "Koniec\n";
    return 0;
}

void strcount(string str)
{
    static int total = 0;          // statyczna zmienna lokalna
    int count = 0;                 // automatyczna zmienna lokalna

    cout << "\"" << str << "\" zawiera ";
    for(char c : str)
    {
        ++count;
    }
    total += count;

    cout << count << " znakow\n";
    cout << "Lacznie "<< total << " znakow\n";
}
