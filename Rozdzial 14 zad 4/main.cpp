#include <iostream>
#include <string>

using namespace std;

// DZIEDZICZENIE WIELOKROTNE - klasy posrednie musza byc dziedziczone jako wirtualne
// charakterystyka
// posiadamy jedna klase bazowa (moze byc abstrakcyjna). Nastepnie 2 klasy pochodne ktore korzystaja z klasy bazowej. Nastepnie na samym koncu mamy klase pochodna ktora dziedziczy po obu klasach pochodnych klasy bazowej
// wtedy musimy obie klasy pochodne klasy Person zapisac jako wirtualne (VIRTUAL). Wtedy NIE nastapi podwojne odziediczenie obiektu klasy Person. Jest to sposob na radzenie sobie z dziedziczeniem wielokrotnym.
// PROBLEM 1. trzeba inaczej tworzyc konstruktory w ostatniej klasie pochodnej ktora dziedziczy po klasach wirtualnych. Trzeba jawnie wywolac konstruktor klasy bazowej
// PROBLEM 2. podwojne metody. W klasie BadDude gdybysmy niezdefiniowali metody Show() to wywolujac ta metode w main bylo by to wieloznaczne bo Show() jest i w Gunslinger i PokerPlayer, wiec blad, kompilator nie wie jaka wywolac. (oczywiswcie mozna uzyc operatora dostepu w main ale to i tak jest slabe.
// Najlepiej przedefiniowac metode Show() w klasie BadDude. Jednak wywolanie funkcji Show() obu klas jest niezalecane bo podwojnie  wyswietli imie i nazwisko.
// Trzeba utworzyc funkcje pomocnicze Dane() ktore sa chronione (protected - klasy pochodne maja dostep do funkcji ale nie da sie jej wywolac bezposrednie na obiekcie w mainie) i ich uzywac w metodach Show() wszystkich klas. Oznaczenie tych meteod jako prywatnych nie jest mozliwe bo nie bedzie mozliwe wywolanie ich w klasach pochodnych. MUSZA BYC PROTECTED !!!
// Warto zwrocic tez uwage na metody Gdraw i Cdraw w klasie BadDude. Sluza one do dostepu do skladowych klas po ktorych sie dziedziczy. Jest to tzw opakowywanie. Gdzy nie mozna uzyc na obiekcie metody Draw() bo jest ona i w Gunslinger i PokerPlayer wiec powstaje wieloznacznosc. Stad trzeba dodac nowe metody w klasie BadDude ktore wywoluja konkretne metody klas z ktorych dziedzicza
class Person
{
    private:
        string imie;
        string nazwisko;
    protected:      // metody ktorych nie mozna uzyc w main
        void Dane() const { cout << "imie: " << imie << ", naziwsko: " << nazwisko << endl; }
    public:
        Person() : imie("Brak"), nazwisko("Brak") {}
        Person(char * i, char * n) : imie(i), nazwisko(n) {}
        virtual void Show() { Dane(); }
};

class Gunslinger : virtual public Person
{
    private:
        int naciecia;
        double time;
    protected:          // metody ktorych nie mozna uzyc w main
        void Dane() const { cout << "naciecia: " << naciecia << ", czas: " << time << endl; }
    public:
        Gunslinger() : Person(), naciecia(0), time(0.0) {}
        Gunslinger(char * i, char * n, int nac, double t) : Person(i,n), naciecia(nac), time(t) {}
        double Draw() { return time; }
        virtual void Show()
        {
            Person::Dane();   // Dane klasy Person
            Dane();           // Dane klasy Gunslinger
        }
};

class PokerPlayer : virtual public Person
{
    private:
        int numerKarty;
    protected:                  // metody ktorych nie mozna uzyc w main
        void Dane() const { cout << "numer karty: " << numerKarty << endl;}
    public:
        PokerPlayer() : Person(), numerKarty(0) {}
        PokerPlayer(char * i, char * n, int nk) : Person(i, n), numerKarty(nk) {}
        int Draw() { return 5; } // powinna zwracac liczbe z zakresu 1-52 ale nei chce mi sie tego robic
        virtual void Show()
        {
            Person::Dane();   // Dane klasy Person
            Dane();           // Dane klasy PokerPlayer
        }
};

// dwukrotne dziedziczenie klasy Person !!!
class BadDude : public Gunslinger, public PokerPlayer
{
    protected:
        void Dane() const {}  // tutaj umieszcamy ewentualne skladowe klasy BadDude
    public:
        BadDude () : Person(), Gunslinger(), PokerPlayer() {}  // TRZEBA JAWNIE WYWOLAC KONSTRUKTOR KLASY BAZOWEJ
        BadDude (char * i, char * n, int nac, double t, int nk) : Person(i,n), Gunslinger(i,n,nac,t), PokerPlayer(i,n, nk) {}  // TRZEBA JAWNIE WYWOLAC KONSTRUKTOR KLASY BAZOWEJ (by nie zostal uzyty konstruktor domyslny tej klasy) ORAZ KAZDY OBIEKT ZAINICJALIZOWAC WSZYSTKIMI DANYMI (stad powtorzenia i,n)
        double Gdraw() { return Gunslinger::Draw(); }   // tzw opakowywanie metod klasy po ktorej sie dziedziczy
        int Cdraw(){ return PokerPlayer::Draw(); }      // tzw opakowywanie metod klasy po ktorej sie dziedziczy
        virtual void Show()
        {
            Person::Dane();         // Dane klasy Person
            Gunslinger::Dane();     // Dane klasy Gunslinger
            PokerPlayer::Dane();    // Dane klasy PokerPlayer
            Dane();                 // Dane klasy BadDude
        }

};


int main()
{
    Person p = {"Zwykly" , "Kowalski"};
    Gunslinger g = {"Bronio" , "Wladacz", 4, 3.3};
    PokerPlayer pp = {"Twisted" , "Fate", 52};
    BadDude bd = {"Zly" , "Koles", 11, 2.2, 33};



    cout << "Person: " << endl;  p.Show(); cout << endl;
    cout << "Gunslinger: " << endl;  g.Show(); cout << endl;
    cout << "PokerPlayer: " << endl;  pp.Show(); cout << endl;
    cout << "BadDude: " << endl;  bd.Show(); cout << endl;

   // double czasWyciagnieciaRewolweru = g.getTime(); nie zadziala bo metoda jest protected
   cout << "czas wyciagniecia rewolweru: " << bd.Gdraw() << endl;
   cout << "numer wyciagnietej karty: " << bd.Cdraw() << endl;

    return 0;
}
