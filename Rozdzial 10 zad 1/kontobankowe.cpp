#include <iostream>
#include "kontobankowe.h"

KontoBankowe::KontoBankowe(const string & klient, const string & num, double sal)
{
    this->nazwisko = klient;        // NIE MOZNA UZYC CZEGOS TAKIEGO this.nazwisko, BO THIS TO POINTER !!!
    numerkonta = num;               // DOMYSLNIE JEST ZE NEI TRZEBA W KONSTRUKTORZE PISAC SLOWKA THIS (ALE MOZNA). OBIE FORMY POPRAWNE
    saldo = sal;
}

void KontoBankowe::pokaz(void) const
{
    cout << nazwisko << ", " << this->numerkonta << ", " << "saldko: " << saldo << endl; // tak samo mozna uzywac slowka this, ale nie trzeba
}

void KontoBankowe::deponuj(double kwota)
{
    if (kwota < 0)
    {
        cout << "Podales ujemna kwote. Przerywam operacje" << endl;
    }
    else
    {
        saldo += kwota;
    }
}

void KontoBankowe::podejmij(double kwota)
{
    if (kwota < 0)
    {
        cout << "Podales ujemna kwote. Przerywam operacje" << endl;
    }
    else
    {
        saldo -= kwota;
    }
}
