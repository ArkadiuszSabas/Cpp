#include <iostream>
#include <string>

using namespace std;

// CZÊŒÆ FUNCKJI JEST WIRTUALNA BO CHODZI O POLIMORFIZM

class abstr_emp  // klasa jest abstrakcyjna gduz ma czysto wirtualne funkcje ~abstr_emp()
{
    private:
        string fname;   // imie
        string lname;   // nazwisko
        string job;     // praca
    public:
        abstr_emp (){}
        abstr_emp(const string & fn, const string & ln, const string & j)
        {
            fname = fn;
            lname = ln;
            job = j;
        }

        virtual void ShowAll() const  // wyswietla wszystkie dane
        {
            cout << "ShowAll() - " << fname << ", " << lname << ", " << job;
        }
        virtual void SetAll()  // prosi uzytkownika o podanie wartosci
        {
            cout << "Podaj firstname: ";
            cin >> fname;
            cout << "Podaj nazwisko: " ;
            cin >> lname;
            cout << "Podaj swoja prace: ";
            cin >> job;
        }

        // niby opakowaa funkcja ShowAll ale musi byc bo ianczej cout nie bedzie wiedzial co obiekt oznacza
        friend ostream & operator<<(ostream & os, const abstr_emp & e)
        {
            e.ShowAll();  // tutaj zamiast os << e.fname << e.lname << e.job, wystarczy wywolac funkcje ktora wyswietla wsyzstko. Choc nie iwem czy tak powinno sie robic
            return os;
        }
        virtual ~abstr_emp()=0; // czysto wirtualna funkcja. ZEBY DZIALALO TO TRZEBA DODAC PO ZA KLASA DEFINICJE DESTRUKTORA

};
abstr_emp::~abstr_emp(){};   // TO MUSI ISTNIEC ZEBY ZADZIALAL DESTRUKTOR KTORY JEST CZYSTO WIRTUALNY

class employee : public abstr_emp
{
    public:
        employee() : abstr_emp() {}
        employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j){}
        virtual void ShowAll() const  // wyswietla wszystkie dane
        {
            abstr_emp::ShowAll();
        }
        virtual void SetAll() // prosi uzytkownika o podanie wartosci
        {
            abstr_emp::SetAll();
        }
};

class manager : virtual public abstr_emp
{
    private:
        int inchargeof;  // liczba obiektow abstr_emp, ktorymi zarzadza
    protected:
        int InChargeOf() const { return inchargeof; }   // wyjscie
        // tu musi byc seter bo bez sensu miec dwietakie same metody. Wiec to zmienilem
        SetInChargeOf() // wejscie
        {
             cout << "Podaj inchargeof: ";
             cin >> inchargeof;
        }
    public:
        manager() : abstr_emp(){}
        manager(const string & fn, const string & ln, const string & j, int ico = 0) : abstr_emp(fn, ln, j), inchargeof(ico) {}
        manager(const abstr_emp & e, int ico = 0) : abstr_emp(e), inchargeof(ico) {} // uzycie niejawnego konstruktora kopiujacego
        manager(const manager & m) : abstr_emp(m) // kostruktor kopiujacy. Uzycie niejawnego konstruktora kopiujacego klasy bazowej
        {
            this->inchargeof = m.inchargeof;
        }
        virtual void ShowAll() const
        {
            abstr_emp::ShowAll();
            cout << ", " << inchargeof;
        }
        virtual void SetAll()
        {
            abstr_emp::SetAll();
            SetInChargeOf();
        }
};

class fink : virtual public abstr_emp
{
    private:
        string reportsto;  // do kogo fink(donosiciel) przesyla raport
    protected:
        const string ReportsTo() const { return reportsto; }
        SetReportsTo()
        {
            cout << "Podaj reportsto: ";
            cin >> reportsto;
        }
    public:
        fink() : abstr_emp(){}
        fink(const string & fn, const string & ln, const string & j, const string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}
        fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo) {}
        fink(const fink & e) : abstr_emp(e)
        {
            this->reportsto = e.reportsto;
        }
        virtual void ShowAll() const
        {
            abstr_emp::ShowAll();
            cout << ", " << reportsto;
        }
        virtual void SetAll()
        {
            abstr_emp::SetAll();
            SetReportsTo();
        }
};

class highfink : public manager, public fink  // glowny donosiciel
{
    public:
        highfink() : abstr_emp(), manager(), fink() {}  // jako ze jest dziedziczenei wielokrotne trzeba wywolac wszystkie 3 klasy
        highfink(const string & fn, const string & ln, const string & j, const string &rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
        highfink(const abstr_emp & e, const string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo){}
        highfink(const fink & e, int ico) : abstr_emp(e), manager(e, ico), fink(e){}
        highfink(const manager & m, const string & rpo) : abstr_emp(m), manager(m), fink(m, rpo){}
        highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h){}
        virtual void ShowAll() const
        {
            abstr_emp::ShowAll();
            cout << ", " << manager::InChargeOf();
            cout << ", " << fink::ReportsTo();
        }
        virtual void SetAll()
        {
            abstr_emp::SetAll();
            manager::SetInChargeOf();
            fink::SetReportsTo();
        }
};


int main()
{
    employee em("Tadeusz", "Hubert", "Sprzedawca");
    em.ShowAll();
    cout << "\n" << em << "\n\n";

    manager ma("Amforiusz", "Smoczewski", "Malarz", 5);
    ma.ShowAll();
    cout << "\n" << ma << "\n\n";

    fink fi("Maurycy", "Okulski", "Hydraulik", "Julian Bar");
    fi.ShowAll();
    cout << "\n" << fi << "\n\n";

    highfink hf(ma, "Jan Kudlaty");
    hf.ShowAll();
    cout << "\n";

//    fi.SetAll();
//    fi.ShowAll();


    highfink hf2;
    hf2.SetAll();

    cout << "Uzywa wskaznika abstr_emp *:\n";
    abstr_emp * tri[4] = { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
    {
         tri[i]->ShowAll();
         cout << "\n";
    }



    cout << "\n\nHello world!" << endl;
    return 0;
}
