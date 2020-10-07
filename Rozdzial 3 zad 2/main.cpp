#include <iostream>

using namespace std;

int main()
{
    const double CAL = 0.0254; // metra
    const double KILO = 2.2; // funtow

    cout << "Podaj wzorst w calach: " << endl;
    double wzrostWCalach;
    cin >> wzrostWCalach;
    cout << "Podaj wage w funtach: " << endl;
    double wagaWFuntach;
    cin >> wagaWFuntach;

    double wzrostWMetrach = wzrostWCalach * CAL;
    double wagaWKilogramach = wagaWFuntach/KILO;

    cout << "Twoj wzrost to " << wzrostWMetrach << " metra. \n"
         << "Twoja waga to " << wagaWKilogramach << " kilogramow. \n"
         << "Twoje BMI wynosi: " << wagaWKilogramach/(wzrostWMetrach*wzrostWMetrach) << endl;

    return 0;
}
