#include <iostream>

using namespace std;

int main()
{

    char ch;
    cout << "r) roslinozerca     p) pianista\n";
    cout << "d) drzewo           g) gra\n";

    do
    {
        cout << "Prosze podac litere r, p, d lub g: ";
        cin.get(ch).get();  // drugi get() usuwa znak entera

        switch (ch)
        {
            case 'r' : cout << "Krowa laciata\n"; break;
            case 'p' : cout << "Chopen to gosc\n"; break;
            case 'd' : cout << "Klon jest drzewem\n"; break;
            case 'g' : cout << "Tylko LoL\n"; break;
        }
    }
    while ('r' != ch && 'p' != ch && 'd' != ch && 'g' != ch);

    cout << "Koniec programu\n";

    return 0;
}
