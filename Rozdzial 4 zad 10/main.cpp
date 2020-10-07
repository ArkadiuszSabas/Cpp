#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<double,3> czasy;
    cout << "Podaj pierwszy czas na 100 metrow: " << endl;
    cin >> czasy[0];
    cout << "Podaj drugi czas na 100 metrow: " << endl;
    cin >> czasy[1];
    cout << "Podaj trzeci czas na 100 metrow: " << endl;
    cin >> czasy[2];

    double sredniaCzasow = (czasy[0] + czasy[1] + czasy[2])/3;

    cout << "Twoje czasy to " << czasy[0] << ", " << czasy[1] << ", " <<  czasy[2] << ", a srednia to: " << sredniaCzasow << endl;

    return 0;
}
