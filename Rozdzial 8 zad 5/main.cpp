#include <iostream>

using namespace std;

const int tabSize = 5;

template <typename T>
T max5(T tab[tabSize]);

int main()
{
    int intTab[tabSize] = {4,2,3,6,5};
    double doubleTab[tabSize];
    doubleTab[0] = 2.2;
    doubleTab[1] = 2.3;
    doubleTab[2] = 2.4;
    doubleTab[3] = 2.5;
    doubleTab[4] = 2.6;

    auto maxV = max5(intTab);  // skoro nie wiemy co zostanie zwrocone trzeba uzyc typu auto. Trzeba od razu zainicjalizowac zmienna.
    cout << maxV << endl;
    //cout << max5(intTab) << endl; // lub mozna od razu wyswietlic

    maxV = max5(doubleTab);  // teraz nie zadziala bo maxV ma juz przypisany typ int.
    cout << maxV << endl;

    auto maxV2 = max5(doubleTab);
    cout << maxV2 << endl;
    //cout << max5(doubleTab) << endl;


    cout << "\nHello world!" << endl;
    return 0;
}

template <typename T>
T max5(T tab[tabSize])
{
    T maxV = tab[0];
    for(int i = 1; i < tabSize; i++)
    {
        if(tab[i] > maxV) maxV = tab[i];
    }
   return maxV;
}
