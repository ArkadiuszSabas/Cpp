#include <iostream>
#include <string.h>

using namespace std;

// KLASA BAZOWA
class Cd
{
    private:
        char * performers;
        char * label;
        int selections; //liczba utworow
        double playtime; //dlugosc plyty w minutach

    public:
        Cd()   // konstruktor domyslny
        {
            performers = new char[1];
            performers[0] = '\n';
            label = new char[1];
            label[0] = '\n';
            selections = 0;
            playtime = 0.0;
        }

        Cd(char * s1, char * s2, int n, double x)  // konstruktor z parametrami
        {
            performers = new char[strlen(s1)+1];
            strcpy(performers, s1);
            label = new char[strlen(s2)+1];
            strcpy(label, s2);
            selections = n;
            playtime = x;
        }

        Cd(const Cd & d)   // kosntruktor kopiujacy
        {
            performers = new char[strlen(d.performers) + 1];
            strcpy(this->performers, d.performers);
            label = new char[strlen(d.label) + 1];
            strcpy(this->label, d.label);
            this->selections = d.selections;
            this->playtime = d.playtime;
        }

        virtual ~Cd()   // destruktor. Dobrze dodac slowko virtual bo mamy virtualna metode i by kompilator wywolywal konstruktor kaldy pochodnej a pozniej destruktor klasy bazowej
        {
            delete [] performers;
            delete [] label;
        }

        Cd & operator=(const Cd & d) // tresc oepratora przypisania jest praktycznei taka sama jak konstruktora kopiujacego + delete wczesniejszych stringow
        {
            if (this == &d)
                return *this;

            delete [] performers; // usuniecie miejsca zajmowane przed poprzednie stringi
            delete [] label;

            performers = new char[strlen(d.performers) + 1];
            strcpy(this->performers, d.performers);
            label = new char[strlen(d.label) + 1];
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
        char * mainSong;

    public:
        Classic() : Cd()  // wywolanie kosntruktora domyslnego by zainicjalizowac 4 skladowe klasy Cd
        {
            mainSong = new char[1];
            mainSong[0] = '\n';
        }

        Classic(char * s1, char * s2, char * s3, int n, double x) : Cd(s1, s2, n, x)  // inicjalizacja konstruktorem z parametrami klasy Cd
        {
            mainSong = new char[strlen(s3)+1];
            strcpy(mainSong, s3);
        }

        // drugi sposob na konstruktor z parametrami
        Classic(char * s3, const Cd & d) : Cd(d)  // inicjalizacja konstruktorem kopiujacego klasy Cd
        {
            mainSong = new char[strlen(s3)+1];
            strcpy(mainSong, s3);
        }

        // Konieczny operator przypisania w kalsie pochodnej gdyz zostala dodana nowa skladowa ktora jest wskaznikiem. (choc bez neigo tez o dziwo dzialalo)
        Cd & operator=(const Classic & d) // tresc oepratora przypisania jest praktycznei taka sama jak konstruktora kopiujacego + delete wczesniejszych stringow
        {
            if (this == &d)
                return *this;

            Cd::operator=(d); // wywolujemy operator przypisania dla klasy bazowej

            delete [] mainSong; // usuniecie miejsca zajmowane przed poprzednie stringi
            mainSong = new char[strlen(d.mainSong) + 1];
            strcpy(this->mainSong, d.mainSong);
            return *this;
        }

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
    Classic c3 = Classic("Blabla", "Digi", "Agostino", 66, 6.77);

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

    return 0;
}

void Bravo(const Cd & disc)
{
    disc.Report();
}
