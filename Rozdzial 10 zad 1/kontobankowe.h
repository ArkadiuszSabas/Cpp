#ifndef KONTOBANKOWE_H_INCLUDED
#define KONTOBANKOWE_H_INCLUDED

#include <string>

using namespace std;  // ta przestrzen nazw przejdzei takze do plikow ktore includuja plik kontobankowe.h

class KontoBankowe
{
    private:
        string nazwisko;
        string numerkonta;
        double saldo;

    public:
        KontoBankowe(const string & klient, const string & num, double sal = 0.0);
        void pokaz(void) const;
        void deponuj(double kwota);
        void podejmij(double kwota);
};


#endif // KONTOBANKOWE_H_INCLUDED
