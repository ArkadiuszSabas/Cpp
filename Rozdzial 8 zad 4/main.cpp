#include <iostream>
#include <cstring> // dla strlen i strcpy
#include <string>

using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & beany, char * str);

void show(char * str, int n = 0);
void show(const stringy beany, int n = 0); // przeciazaona funkcja

int main()
{
    stringy beany;
    char testing[] = "Rzeczywistosc to juz nie to, co kiedys.";

    set(beany, testing);

    show(beany);
    show(beany, 2);

    cout << endl;

    testing[0] = 'D';
    testing[1] = 'u';

    show(testing);
    show(testing, 3);
    show("Gotowe!");


    cout << "Hello world!" << endl;
    return 0;
}

// FUNKCJE

void set(stringy & beany, char * str)
{
    beany.str = str;
}

void show(char * str, int n)
{
    if(0 == n)
    {
        cout << "Drugi parametr to 0. Napis wyswietle tylko raz" << endl;
        cout << str << endl;
    }
    else
    {
        cout << "Drugi parametr rozny od 0. Napis wyswietle " << n << " razy: " << endl;
        for(int i = 0; i < n; i++)
        cout << str << endl;
    }
}

void show(const stringy beany, int n)
{
    if(0 == n)
    {
        cout << "Drugi parametr to 0. Stringy.str wyswietle tylko raz" << endl;
        cout << beany.str << endl;
    }
    else
    {
        cout << "Drugi parametr rozny od 0. Stringy.str wyswietle " << n << " razy: " << endl;
        for(int i = 0; i < n; i++)
        cout << beany.str << endl;
    }
}
