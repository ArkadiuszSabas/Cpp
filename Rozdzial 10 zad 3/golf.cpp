#include <iostream>
#include <string.h>
#include "golf.h"

Golf::Golf(const char * name, int hc)
{
    strncpy(fullname, name, Len - 1);
    fullname[Len-1] = '\0';
    handicap = hc;
}



void Golf::changeHandicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf(void) const
{
    cout << fullname << ", handicap: " << handicap << endl;
}
