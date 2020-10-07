#include <iostream>
#include "golf.h"

using namespace std;

int main()
{
    Golf jeden("Audi A3");
    Golf dwa("Mazda supreame", 100);

    cout <<"Pokazuje Audi" << endl;
    jeden.showgolf();
    cout <<"Pokazuje Mazde" << endl;
    dwa.showgolf();
    cout <<"Zmieniam handicap Audi" << endl;
    jeden.changeHandicap(333);
    cout <<"Pokazuje Audi" << endl;
    jeden.showgolf();

    return 0;
}
