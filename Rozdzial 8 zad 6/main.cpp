#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T maxn(T tab[], int n);
template <> char * maxn<char *>(char * tab[], int n);

int main()
{

    int intTab[5] = {4,2,3,6,5};
    double doubleTab[4] = {1.1, 2.2, 4.4, 3.3};
    char * strTab[5] = { "A", "BB", "CCCCC", "DDDD", "EEE"};

    auto maxV = maxn(intTab, 5);  // skoro nie wiemy co zostanie zwrocone trzeba uzyc typu auto. Trzeba od razu zainicjalizowac zmienna.
    cout << maxV << endl;
    //cout << maxn(intTab) << endl; // lub mozna od razu wyswietlic

    auto maxV2 = maxn(doubleTab, 4);
    cout << maxV2 << endl;
    //cout << maxn(doubleTab) << endl;

    auto maxV3 = maxn(strTab, 5);
    cout << maxV3 << endl;
    return 0;
}

template <typename T>
T maxn(T tab[], int n)
{
    T maxV = tab[0];
    for(int i = 1; i < n; i++)
    {
        if(tab[i]>=maxV) maxV = tab[i];
    }
   return maxV;
}

template <> char * maxn<char *>(char * tab[], int n)
{
    int index = 0;
    int maxlen = strlen(tab[0]);
    for(int i = 1; i < n; i++)
    {
        if(strlen(tab[i])> maxlen)
        {
            maxlen = strlen(tab[i]);
            index = i;
        }
    }
    return tab[index]; // nie trzeba dawac & bo TABLICA to tablica wskaznikow czyli adresow
}
