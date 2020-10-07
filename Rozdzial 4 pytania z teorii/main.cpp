#include <iostream>
#include <limits>
#include <array>
#include <string>
#include <vector>

using namespace std;

struct Ryba
{
    char rodzaj[55];
    int waga;
    double dlugosc;
};

int main()
{

    char aktorzy[30];
    short betsie[100];
    float chuck[13];
    long double dipsea[64];

    array <char, 30> aktorzy2;
    array <short, 100> betsie2;
    array <float, 13> chuck2;
    array <long double, 64> dipsea2;

    int nieparzyste[5] = {1,3,5,7,9};

    int even = nieparzyste[0] + nieparzyste[4];

    float ideas[2];
    *(ideas+0) = 33;
    ideas[1] = 44; // *(ideas+1) = 44
    cout << "drugi element tablicy ideas: " << ideas[1] << endl;

    char obiad[] = "cheeseburger";  // polecenie 6

    char * potrawa = "Waldorf Salad"; // polecenie 7
    string lunch = "Waldorf Salad";  // mozna tez tak. Stringa nazywa sie ³ancuchem znakowym

    Ryba makrela = {"Andrzej", 200, 22.5}; // polecenie 8
    cout << makrela.rodzaj << endl;

    enum Odpowiedz {Tak = 1, Nie = 0, Chyba = 2};

    double ted = 5.4;
    double * ptDouble;
    ptDouble = &ted;
    cout << "Wartosc wyluskana za pomoca wskaznika: " << *ptDouble << endl;

    float treacle[10] { 0,1,2,3,4,5,6,7,8,9};
    float * ptFloatTablica = treacle;
    cout << "Wyswietlam za pomoca wskaznika pierwszy element tablicy: " << *(ptFloatTablica) << ". I ostatni element tablicy: " << *(ptFloatTablica+9) << endl; // mozna tez wywolac jak tablice czyli ptFloatTablica[0] i ptFloatTablica[9]

    cout << "Podaj liczbe calkowita: ";
    int wielkoscTablicyDynamicznej;
    cin >> wielkoscTablicyDynamicznej;
    int * tabDynamiczna = new int[wielkoscTablicyDynamicznej];

    vector <int> vectorTablica(wielkoscTablicyDynamicznej);

    cout << (int *) "Dom wesolych bajtow" << endl; // wyswietli adres pod ktorym jest znak 'D'
                                                // stala lancuchowa "dowolny napis umieszczony w cudzyslowach bez przypisanego typu np string lub cha[]"


    Ryba * plotka = new Ryba;
    cout << "Podaj gatunek ryby: ";
    cin >> plotka->rodzaj;
    cout << plotka->rodzaj;

//    char * napis = new char;  //
//    napis = makrela.rodzaj;
//    cout << napis << endl;
    //napis = obiad;  // obiad to tablica znakow eic &obiad wskazywal by na cala tablice a nie na peirwszy element tej tablicy znakow


    const int rozmiarTablic = 10;
    vector<string> vec(rozmiarTablic); // potrzeba #include <vector> oraz #include <string>
    array<string,rozmiarTablic> arr;   // potrzeba #include <array> oraz #include <string>

    return 0;
}
