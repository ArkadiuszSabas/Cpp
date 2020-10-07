#include <iostream>
#include <string.h>

using namespace std;

class Cow
{
    private:
        char name[20];
        char * hobby;
        double weight;
    public:
        Cow()   // konstruktor domyslny
        {
            name[0] = '\0';     // pierwszy element to NULL

            hobby = new char[1];  // jednoelementowa tablica. Musi byc tablica bo musi sie zgadzac z destruktorem
            hobby[0] = '\0';

            weight = 0;
        }

        Cow(const char * nm, const char * ho, double wt)
        {
            strncpy(name, nm, 20);   // skopiowanie tylko 20 znakow
            name[19] = '\0';    // upewnienei sie ze bedzie null na koncu

            hobby = new char[strlen(ho) + 1];
            strcpy(hobby, ho);   // automatycznie doda \0 na koniec

            weight = wt;
        }

        Cow(Cow & c)
        {
            strcpy(name, c.name);  // wiemy ze kopiujemy od krowy wiec na 100% nie przekroczymy zakresu

            hobby = new char[strlen(c.hobby) + 1];
            strcpy(hobby, c.hobby);

            weight = c.weight;
        }

        ~Cow()
        {
            delete [] hobby;
        }

        Cow & operator=(const Cow & c)
        {
            if (this == &c)    // kontrola autoprzypisania
                return *this;

            strcpy(name, c.name);

            delete [] hobby;            // przypisanie jest gdy mamy Cow1 = Cow2. wiec Cow1.hobby istnieje i trzeba zwolnic przydzielona wczesniej pamiec
            hobby = new char[strlen(c.hobby) + 1];
            strcpy(hobby, c.hobby);

            weight = c.weight;
            return *this;          // zwrocenie obiektu na ktorym wywolalo sie ta metode
        }

        void ShowCow() const
        {
            cout << "Imie: " << name << ", hobby: " << hobby << ", waga: " << weight;
        }
};


int main()
{
    // TEST DOMYSLNEGO
    Cow milka;
    milka.ShowCow();


    // TEST KONSTRUKTORA Z PARAMETRAMI
    cout << endl;
   // Cow krowcia("mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "muczenie", 200);
    Cow * krowcia = new Cow("mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm", "muczenie", 200);
    krowcia->ShowCow();


    // TEST KOPIUJACEGO
    cout << endl;
    Cow mucka = *krowcia;
    mucka.ShowCow();


    // TEST PRZYPISANIA
    cout << endl;
    milka = *krowcia;
    milka.ShowCow();

    // PO USUNIECIU ORYGINALU
    cout << endl << "Usuwamy oryginal i sprawdzamy czy naprawde nastapilo glebokie kopiowanie w konstruktorach i operatorze przypisania \n";
    delete krowcia;
    mucka.ShowCow();
    cout << endl;
    milka.ShowCow();
    cout << endl << "Tak udalo sie, dane nie zostaly usuniete!" << endl;


    return 0;
}
