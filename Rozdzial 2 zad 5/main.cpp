#include <iostream>

using namespace std;
long double proporcjaPopulacji(long long int, long long int);

int main()
{
    long long int worldPopulation;
    long long int polandPopulation;


    cout << "Podaj populacje swiata: " << endl;
    cin >> worldPopulation;
    cout << "Podaj populacje Polski: " << endl;
    cin >> polandPopulation;
    cout << "Populacja Polski stanowi " <<  proporcjaPopulacji(worldPopulation, polandPopulation)  << "% populacji swiata\n";

    return 0;
}

long double proporcjaPopulacji(long long int worldPopulation, long long int polandPopulation)
{
    long double proportion = 100 * (long double)polandPopulation /(long double)worldPopulation;
    return proportion;
}
