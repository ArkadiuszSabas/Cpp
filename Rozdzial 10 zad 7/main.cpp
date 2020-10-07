#include <iostream>
#include "gwiazda.h"

int main()
{
    Gwiazda Plorg("Plorg betelgeski");
    Plorg.showGwiazda();
    Plorg.setSytosc(99);
    Plorg.showGwiazda();

    cout << "Tworze niewiadoma gwiazde. Powinna przyjac imie Plorga" << endl;
    Gwiazda cos;
    cos.showGwiazda();

    return 0;
}
