#include <iostream>

using namespace std;

int silnia(int liczba);

int main()
{
    int liczba = 4;
    cout << liczba << "! = " << silnia(liczba);

    return 0;
}

int silnia(int liczba)
{
    if(0 == liczba || 1 == liczba) return 1;
    else return liczba * silnia(liczba-1);
}
