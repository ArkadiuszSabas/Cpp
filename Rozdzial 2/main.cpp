#include <iostream>

using namespace std;

// PROTOTYPES
// 2
int milesToMeters(int);
// 3
void wyswietlEntliczek();
void wyswietlStoliczek();
// 4
int yearsToMonths(int);
// 5
double CelsjuszToFarenhait(double);
// 6
double lightyearsToOtherUnit(double lightyears);
// 7
void wyswietlGodzine(int, int);

// MAIN
int main()
{
    // 1
    cout << "Sthepen Prata, " << endl;

    // 2
    int miles;
    cout << "Podaj dlugosc w milach morskich: ";
    cin >> miles;
    int meters = milesToMeters(miles);
    cout << "Dlugosc w metreach: " << meters << endl;

    // 3
    wyswietlEntliczek();
    wyswietlEntliczek();
    wyswietlStoliczek();
    wyswietlStoliczek();

    // 4
    cout << "Podaj swoj wiek: ";
    int wiek;
    cin >> wiek;
    int months = yearsToMonths(wiek);
    cout <<"Twoj wiek w miesiacach wynosi: " << months << endl;

    // 5
    cout << "Podaj temperature w stopniach Celsjusza: ";
    double tempratureCelsjusz;
    cin >> tempratureCelsjusz;
    double tempratureFarenhait = CelsjuszToFarenhait(tempratureCelsjusz);
    cout << tempratureCelsjusz << " stopnie Celsjusza to " << tempratureFarenhait << " stopnie Farenhaita.\n";

    // 6
    cout << "Podaj liczbe lat swietlnych: ";
    double lightYears;
    cin >> lightYears;
    double otherUnit = lightyearsToOtherUnit(lightYears);
    cout << lightYears << " lat swietlnych = " << otherUnit << " jednostek astronomicznych\n";

    // 7
    cout << "Podaj liczbe godzin: ";
    int hours;
    cin >> hours;
    cout << "podaj liczbe minut: ";
    int minuts;
    cin >> minuts;
    wyswietlGodzine(hours, minuts);

}

// DEFINITION
// 2
int milesToMeters(int lengthInMiles)
{
    int lengthInMeters = lengthInMiles * 1852;
    return lengthInMeters;
}
// 3
void wyswietlEntliczek()
{
    cout << "Entliczek pentliczek\n";
}

void wyswietlStoliczek()
{
    cout << "Czerwony stoliczek\n";
}
//4
int yearsToMonths(int age)
{
    int months = age * 12;
    return months;
}
// 5
double CelsjuszToFarenhait(double celsjusz)
{
    double farenhait = 1.8 * celsjusz + 32.0;
    return farenhait;
}
// 6
double lightyearsToOtherUnit(double lightyears)
{
    double unit = lightyears * 63240;
    return unit;
}
// 7
void wyswietlGodzine(int hours, int minuts)
{
    cout << "Czas: " << hours << ":" << minuts;
}

