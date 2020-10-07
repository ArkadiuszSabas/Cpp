#include <iostream>
#include <string.h>
#include "gwiazda.h"

Gwiazda::Gwiazda(char * im)
{
    strncpy(imie, im, LIMIT-1);
    imie[LIMIT-1] = '\0';
    sytosc = 50;
}

void Gwiazda::showGwiazda() const
{
    cout << imie << ", sytosc: " << sytosc << endl;
}

void Gwiazda::setSytosc(int syt)
{
    cout << "Zmieniam sytosc na " << syt << endl;
    sytosc = syt;
}
