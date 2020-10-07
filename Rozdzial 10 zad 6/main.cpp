#include <iostream>
#include "Move.h"

int main()
{
    Move jeden;  // NIE MOZNA wywolac w ten sposob  "Move jeden();"
    Move dwa(5);
    Move trzy(8, 12);

    jeden.showmove();
    dwa.showmove();
    trzy.showmove();

    cout << "Ustawiam nowe wartosci Punktu 3" << endl;
    trzy.setParameters(15, 15);
    trzy.showmove();

    cout << "Do punktu 1 wstawie sume punktow 2 i 3" << endl;
    jeden = dwa.add(trzy);
    cout << "Oto nowe dane punktu 1 " << endl;
    jeden.showmove();

    return 0;
}
