#include <iostream>
#include <string.h>
#include "Person.h"

Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT-1);
    fname[LIMIT-1] = '\0';  // zabezpieczenie jakby ktos wpisal dluzszy napis niz tablica. I tak zostanie utworzony string bo ostatnim znakiem bedzie \0
}


void Person::Show() const   // imie nazwisko
{
    cout << lname << " " << fname << endl;
}

void Person::FormalShow() const
{
    cout << fname << " " << lname << endl;
}
