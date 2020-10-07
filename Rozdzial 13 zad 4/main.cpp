#include <iostream>
#include <string.h>

using namespace std;

class Port
{
    private:
        char * brand;
        char style[20];  // np brazowe, rubinowe, z najlepszego rocznika
        int bottles;

    public:
        Port(const char * br = "Brak", const char * st = "Brak", int b = 0)
        {
            brand = new char[strlen(br) + 1];
            strcpy(brand, br);
            strncpy(style, st, 20);
            style[19] = '\n';
            bottles = b;
        }

        Port(const Port & p) //konstruktor kopiujacy
        {
            brand = new char[strlen(p.brand) + 1];
            strcpy(this->brand, p.brand);
            strcpy(this->style, p.style);  // nei trzeba sie martwic o dlugosc tablicy bo ebdzie zawsze odpowiednia
            this->bottles = p.bottles;
        }

        virtual ~Port()
        {
            delete [] brand;
        }

        Port & operator=(const Port & p)
        {
            if (this == &p)
                return *this;

            delete [] brand; // usuniecie miejsca zajmowane przed poprzednie stringi

            brand = new char[strlen(p.brand) + 1];
            strcpy(this->brand, p.brand);
            strcpy(this->style, p.style);
            this->bottles = p.bottles;
            return *this;
        }

        Port & operator+=(int b)  // dodaje b do bottles
        {
            this->bottles += b;
            return *this;
        }

        Port & operator-=(int b)  // odejmuje b do bottles o ile jest to mozliwe
        {
            if(this->bottles >= b) this->bottles -= b;
            return *this;
        }

       int BottleCount() const
       {
           return bottles;
       }

       virtual void Show() const
       {
           cout << "Marka: " << brand << endl;
           cout << "Rodzaj: " << style << endl;
           cout << "Butelek: " << bottles << endl;
       }

       friend ostream & operator<<(ostream & os, const Port & p)
       {
           os << p.brand << ", " << p.style << ", " << p.bottles;
           return os;
       }
};

class VintagePort : public Port
{
    private:
        char *nickname;  // na przyklad "Szlachetny", "Aksamitny"
        int year;  // rok produkcji

    public:
        VintagePort() : Port() // dziala takie wywolanie mimo ze nie ma domyslnego konstruktora w klasie Port. Dziala bo konstruktor z parametrami z kalsy Port ma domyslne argumenty dla kazdego pola co jest pseudo rownowazne konstruktorowi domyslnemu
        {                       // tak naprawde to wywolanie konstruktora z parametrami do ktorego nei rpzekazalo sie zadnych argumentow
            nickname = new char[5];
            strcpy(this->nickname, "Brak");
            year = 0;
        }

        VintagePort(const char * br, const char * st, int b, const char * nn, int y) : Port(br, st, b)
        {
            nickname = new char[strlen(nn) + 1];    // nie trzeba uzywac slowka this->, tak samo w klasie bazowej tez nei trzeba. Jak kto woli.
            strcpy(nickname, nn);
            year = y;
        }

     // KONSTRUKTOR KOPIUJACY. Wywoluje konstruktor kopiujacy kalsy bazowej w liscie inicjalizacyjnej
        VintagePort(const VintagePort & vp) : Port(vp)
        {
           nickname = new char[strlen(vp.nickname) + 1];
           strcpy(nickname, vp.nickname);
           year = vp.year;
        }

        ~VintagePort() // kazdy destruktor martwi sie swoim obiektem. Pierw zostanie wywolany destruktor klasy VintagePort, a pozniej Port, wiec cala pamiec zostanie oczyszczona
        {
            delete [] nickname;
        }

        VintagePort & operator=(const VintagePort & vp)
        {
            if (this == &vp) return *this;

            Port::operator=(vp); // wywolujemy operator przypisania dla klasy bazowej

            delete [] nickname;

            nickname = new char[strlen(vp.nickname) + 1];
            strcpy(nickname, vp.nickname);

            year = vp.year;

            return *this;
        }

        virtual void Show() const
        {
            Port::Show(); // obiekt na rzecz ktorego wywolujemy ta funkcje uzywa metody show() z klasy bazowej
            cout << "Ksywka: " << nickname << endl;
            cout << "Wiek: " << year << endl;
        }

        friend ostream & operator<<(ostream & os, const VintagePort & vp)
        {
            os << (const Port&) vp;
            os << ", " << vp.nickname << ", " << vp.year;
            return os;
        }
};



int main()
{
    // MOZNA SOBIE POTESTOWAC
    Port gdansk;  // tworzy psuty obiekt, uzywa pseudodomyslnego konstruktora
    Port gdynia("aaa", "dsd dsds", 33);

    VintagePort v("aa", "bb" , 10, "nick", 1999);

    cout << v;

    return 0;
}
