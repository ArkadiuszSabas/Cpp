// randwalk.cpp -- test klasy Vector
// kompilować z plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include <fstream>
#include "vect.h"

int main()
{
    using namespace std;
    ofstream fout;
    fout.open("marsz.txt");
    using VECTOR::Vector;
    srand(time(0));   // inicjalizacja generatora liczb pseudolosowych
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Podaj dystans do przejcia (k, zakonczyc zakonczyc): ";
    while (cin >> target)
    {
        cout << "Podaj dlugosc kroku: ";
        if (!(cin >> dstep))
            break;
        fout << "Dystans do przejscia: " << target << ", dlugosc kroku: " << dstep << endl;
        int stepsCounter = 0;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            fout << steps << ": " << result << endl;
            steps++;
        }

        fout << "Po " << steps << " krokach delikwent "
            "osiagnal polozenie:\n";
        fout << result << endl;

        cout << "Po " << steps << " krokach delikwent "
            "osiagnal polozenie:\n";
        cout << result << endl;

        result.polar_mode();

        fout << "czyli\n" << result << endl;
        fout << "Srednia dlugosc kroku pozornego = "
            << result.magval()/steps << endl;

        cout << "czyli\n" << result << endl;
        cout << "Srednia dlugosc kroku pozornego = "
            << result.magval()/steps << endl;



        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
    }
    cout << "Koniec!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}

