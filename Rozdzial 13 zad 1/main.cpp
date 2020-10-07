#include <iostream>
#include <string.h>

using namespace std;

// KLASA BAZOWA
class Cd
{
    private:
        char performers[50];
        char label[20];
        int selections; //liczba utworow
        double playtime; //dlugosc plyty w minutach

    public:
        Cd()   // konstruktor domyslny
        {
            performers[0] = '\0';
            label[0] = '\0';
            selections = 0;
            playtime = 0.0;
        }

        Cd(char * s1, char * s2, int n, double x)  // konstruktor z parametrami
        {
            strncpy(performers, s1, 50);
            performers[49] = '\n';
            strncpy(label, s2, 20);
            label[19] = '\n';
            selections = n;
            playtime = x;
        }

        Cd(const Cd & d)   // kosntruktor kopiujacy
        {
            strcpy(this->performers, d.performers);
            strcpy(this->label, d.label);
            this->selections = d.selections;
            this->playtime = d.playtime;

        }

        ~Cd()   // destruktor
        {
        }

        // jako ze nie ma skaldowych ktore sa wskaznikami ten operator przypisania nie jest konieczny. Wystarczylby ten tworzony przez kompilator
        Cd & operator=(const Cd & d)  // tresc oepratora przypisania jest praktycznei taka sama jak konstruktora kopiujacego
        {
            if (this == &d)
                return *this;

            strcpy(this->performers, d.performers);
            strcpy(this->label, d.label);
            this->selections = d.selections;
            this->playtime = d.playtime;
            return *this;
        }

        virtual void Report() const // wyswietla informacje o wszystkich danych plyty
        {
             cout << "Performers: " << performers << ", label: " << label << ", songs: " << selections << ", playtime: " << playtime;
        }
};


// KLASA POCHODNA
class Classic : public Cd
{
    private:
        char mainSong[30];

    public:
        Classic() : Cd()  // wywolanie kosntruktora domyslnego by zainicjalizowac 4 skladowe klasy Cd
        {
            mainSong[0] = '\0';
        }

        Classic(char * s1, char * s2, char * s3, int n, double x) : Cd(s1, s2, n, x)  // inicjalizacja konstruktorem z parametrami klasy Cd
        {
            strncpy(mainSong, s3, 30);
            mainSong[29] = '\n';
        }

            // drugi sposob na konstruktor z parametrami
        Classic(char * s3, const Cd & d) : Cd(d)  // inicjalizacja konstruktorem kopiujacego klasy Cd
        {
            strncpy(mainSong, s3, 30);
            mainSong[29] = '\n';
        }

        //  PRAWDOPOODBNIE NEI TRZEBA DEFINIOWAC OPERATORA PRZYPISANIA BO DOMYSLNY WYSTARCZY DLA KOPIOWANIA PLYTKIEGO

        virtual void Report() const
        {
            Cd::Report();  // sposob na wyswietlenie danych prywatnych skladowych Cd
            cout << ", main song: " << mainSong;
        }
};


// MAIN

void Bravo(const Cd & disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Sonata fortepianowa B-dur, Fantazja C-moll", "Alfred Brendel", "Philips", 2, 57.17);

    cout << "Bezposrednie uzycie obiektu:\n";
    c1.Report(); cout << endl; // uzywa metody klasy Cd
    c2.Report(); cout << endl; // uzywa metody klasy Classic
    cout << endl;

        // BEZ SLOWA VIRTUAL PRZY REPORT TO NIE DZIALALO BY POPRAWNIE
    cout << "Uzycie wskaznika na typ Cd:\n";
    Cd * pcd = &c1;
    pcd->Report(); cout << endl; // uzywa metody klasy CD dla kazdego obiektu tej klasy
    pcd = &c2;
    pcd->Report(); cout << endl; // uzywa metody klasy Classic dla obiektu tej klasy
    cout << endl;

        // BEZ SLOWA VIRTUAL PRZY REPORT TO NIE DZIALALO BY POPRAWNIE
    cout <<"Wywolanie funkcji z argumentem w postaci referencji do typu Cd:\n";
    Bravo(c1); cout << endl;
    Bravo(c2); cout << endl;
    cout << endl;

    cout << "Test przypisania: \n";
    Classic copy;
    copy = c2;
    copy.Report();
    cout << endl;


    return 0;
}

void Bravo(const Cd & disc)
{
    disc.Report();
}
