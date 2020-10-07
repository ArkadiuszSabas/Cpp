#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void to_Upper(string & napis);

int main()
{
    cout << "Podaj napis (q aby zakonczyc): ";
    string napis;
    cin >> napis;

    while(napis != "q")
    {
        to_Upper(napis);
        cout << napis << endl;
        cout << "Podaj nowy napis (q aby zakonczyc): ";
        cin >> napis;
    }

    cout << endl << "Do widzenia!" << endl;
    return 0;
}


void to_Upper(string & napis)
{
    for(char & c: napis)
        c = toupper(c);
}
