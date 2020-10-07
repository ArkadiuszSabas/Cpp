// tempover.cpp -- przeci¹¿anie szablonów
#include <iostream>

template <typename T>            // szablon A
void ShowArray(T arr[], int n);

template <typename T>            // szablon B
void ShowArray(T * arr[], int n);

template <typename T>            // MOJ SZABLON A
T SumArray(T arr[], int n);

template <typename T>            // MOJ SZABLON B
T SumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3] =   // inicjalizacja
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];

// ustawienie wskaŸników na pola amount struktur z tablicy Mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;  // przypisanie adresu pod ktorym jest pole amount objektu debts.

    cout << "Wyliczanie rzeczy pana E.:\n";
// things to tablica int
    ShowArray(things, 6);  // u¿ywamy szablonu A
    cout << "Wyliczanie sumy rzeczy pana E.";
    auto suma = SumArray(things, 6);  // u¿ywamy szablonu A
    cout << "Wyliczanie d³ugów pana E:\n";
// pd to tablica wskaŸników na double
    ShowArray(pd, 3);      // u¿ywa szablonu B (bardziej wyspecjalizowanego)
    cout << "Wyliczanie sumy dlugow pana E.";
    auto suma2 = SumArray(pd, 3);  // u¿ywamy szablonu B

    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    using namespace std;
    int suma = 0;
    cout << "Obliczanie sumy. szablon A\n";
    for (int i = 0; i < n; i++)
        suma += arr[i];
    cout << "suma: " << suma << endl;
    return suma;
}

template <typename T>
T SumArray(T * arr[], int n)
{
    using namespace std;
    double suma = 0;
    cout << "Obliczanie sumy. szablon B\n";
    for (int i = 0; i < n; i++)
        suma += *arr[i];
    cout << "suma: " << suma << endl;
    return suma;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "szablon A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "szablon B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}
