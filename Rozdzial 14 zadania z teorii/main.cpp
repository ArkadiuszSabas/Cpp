#include <iostream>
#include <string.h>

using namespace std;

// ZAD 2  PATRZ TAKZE TEORIA C++/ZAWIERANIE
//
//class Frabjous
//{
//    private:
//        char fab[20];
//    public:
//        Frabjous(const char * s = "C++")
//        {
//            strncpy(fab, s, 20);
//            fab[19] = '\0';
//        }
//        virtual void tell() { cout << "fab: " << fab; }
//        friend ostream & operator<<(ostream & os, const Frabjous & f)
//        {
//            os << "fab: " << f.fab;
//            return os;
//        }
//};
//
//
////ZAWIERANIE CHARAKTERYSTYKA
//
//// Gloam zawiera obiekt classy Frabjous (psudorownowaznik prywatnego dziedziczenia)
//// METODY klasy Gloam moga uzywac interfejsu klasy Frabjous (czyli metod publicznych). Metody zaprzyjaznione maja takie same uprawnienia. Dokladnie to obiekt zawarty(Frabjous) moze uzywac swoich metod publicznych w metodach klasy zawierajacej(Gloam).
//// sam obiekt klasy Gloam NIE moze uzywac interfejsu klasy Frabjous. Nie mozna w mainie napisac Gloam g; g.MetodaklasyFrab().
//// funkcje spoza klasy Gloam nie moga uzywac interfejsu klasy Frabjous. W skrocie nie jest dziediczony interefjs klasy ktora sie zawiera.
//class Gloam
//{
//    private:
//        int glip;
//        Frabjous fb;
//    public:
//        Gloam(int g = 0, const char * s = "C++") : glip(g), fb(s) {}; // do inicjalizacji uzywa sie nazw obiektow. (zamiast nazwy klasy Frabjous)
//        Gloam(int g, const Frabjous & f) : glip(g), fb(f) {};
//        virtual void tell()
//        {
//            cout << "Glip: " << glip << ", ";
//            fb.tell();                // sam obiekt Gloam nie moze uzywac interejsu klasy Frabjous. Ale skladowa fb moze wywolac swoja metode
//        }
//        friend ostream & operator<<(ostream & os, const Gloam & g)
//        {
//            os << "Glip: " << g.glip << ", ";
//            os << g.fb;         // mozliwe bylo wywolanie funkcji zaprzyjaznionej klasy Frabjous na obiekcie Frabjous (dokladnie przeciazonego operatora <<)
//            return os;
//        }
//
//};


// ZAD 3 PATRZ TAKZE TEORIA C++/DZIEDZICZENIE PRYWATNE

class Frabjous
{
    private:
        char fab[20];
    public:
        Frabjous(const char * s = "C++")
        {
            strncpy(fab, s, 20);
            fab[19] = '\0';
        }
        virtual void tell() { cout << "fab: " << fab; }
        friend ostream & operator<<(ostream & os, const Frabjous & f)
        {
            os << "fab: " << f.fab;
            return os;
        }
};

// DZIEDZICZENIE PRYWATNE CHARAKTERYSTYKA
// skladowe (pola) publiczne chronione i prywatne klasy bazowej (Frabjous) staja sie skladowymi prywatnymi w klasie pochodnej (Gloam). Oznacza to ze metody klasy bazowej nie wchodza w skald interfejsu klasy pochodnej
// Metody klady Gloam moga uzywac metod klasy Frabjous (a dokladnie anonimowy obiekt klasy Frabjous moze uzywac sowich metod w metodach klasy Gloam)
// jesli dziediczymy prywatnie klase Frabjous to w klasie pochodnej jest tylko JEDEN anonimowy obiekt tej klasy. (Przy ZAWIERANIU mozemy stworzyc pare obiektow np tak: Frabjous a1, b2,c3; (trzy obiekty) )
// zeby dostac sie do metody podobiektu (obiekt klasy bazowej) to uzywamy nazwaklasy::metoda() np Frabjous::tell();
// zeby dostac sie do samego oiektu trzeba rzutowac na tym klasy bazowej (const Frabjous &). Patrz metoda zwrocFrabjous(). Oczywiscie nie trzeba zwracac tego obiektu Frabjous, to tylko pokazuje jak sie odwolywac do obiektu klasy bazowej
// w funkcjach zaprzyjaznionych uzywamy tej samej techniki by uzyskac dostep do obiektu klasy bazowej lecz zamiast *this uzywamy po prostu nazwy obiektu przekazanej do funkcji np: (const Frabjous &)glo (gdzie 'glo' to obiekt klasy Gloam). Patrz metode: friend ostream & operator<<(ostream & os, const Gloam & g)
class Gloam : private Frabjous
{
    private:
        int glip;
    public:
        Gloam(int g = 0, const char * s = "C++") : glip(g), Frabjous(s) {}; // do inicjalizacji uzywa sie nazwy KLASY (a dokladniej jest to anonimowy obiekt tej klasy)
        Gloam(int g, const Frabjous & f) : glip(g), Frabjous(f) {};
        virtual void tell()
        {
            cout << "Glip: " << glip << ", ";
            Frabjous::tell();                // sam obiekt Gloam nie moze uzywac interejsu klasy Frabjous. Ale anonimowy obiekt moze za pomoca operatora dostepu
        }

        const Frabjous & zwrocFrabjous() const
        {
            return (const Frabjous &) *this; // this jest to obiekt klasy Gloam. By dostac obiekt klasy bazowej to jawnie rzutujemy go na ta klase.
        }

        friend ostream & operator<<(ostream & os, const Gloam & glo)
        {
            os << "Glip: " << glo.glip << ", ";
            os << (const Frabjous &)glo;    // w funkcjach zaprzyjaznionych takze wykorzystujemy jawne rzutowanie lecz tym razem uzywamy nazwy obiektu przekazanego do funkcji 'glo' zamiast slowka 'this'
            return os;
        }

};

int main()
{
    // testujemy tylko klase Gloam, bo to ona zawiera obiekt Frabjous. Sama klasa Frabjous nie jest istotna (jedynie jej metody i pola sa istotne)
    Gloam g;
    g.tell();

    cout << endl;
    Gloam w(5, "gloamidlo");
    cout << endl << "Za pomoca metody tell(): ";
    w.tell();
    cout << endl << "Za pomoca cout: " << w << endl;

//    cout << endl;
//    Frabjous frab = w.zwrocFrabjous();  // zwrocenie obiektu klasy bazowej. W metodzie uzyto rzutowania na typ klasy bazowej
//    cout << endl << "Za pomoca metody tell(): ";
//    frab.tell();
//    cout << endl << "Za pomoca cout: " << frab << endl;

    return 0;
}
