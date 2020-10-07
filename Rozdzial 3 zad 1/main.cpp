#include <iostream>

using namespace std;

// PROTOTYPY
double cmToStopy(double);
double cmToCal(double);

// MAIN
int main()
{
    cout << "Podaj wzorst w centymetrach: " << endl;
    double wzrost;
    cin >> wzrost;
    double wzrostWStopach = cmToStopy(wzrost);
    double wzrostWCalach = cmToCal(wzrost);
    cout << "Twoj wzrost to " << wzrostWStopach
         << " stop lub " << wzrostWCalach << " cali \n";

    return 0;
}

// DEFINICJIE
double cmToStopy(double wzrost)
{
    const double stopa = 30.48;
    double wzrostWStopach = wzrost/stopa;
    return wzrostWStopach;
}

double cmToCal(double wzrost)
{
    const double cal = 2.54;
    double wzrostWCalach = wzrost/cal;
    return wzrostWCalach;
}
