#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>

using namespace std;

class Person
{
    private:
        static const int LIMIT = 256;  // stala dla kazdego obiektu Person
        string lname;           // nazwisko
        char fname[LIMIT];      // imie
    public:
        Person() { lname = ""; fname[0] = '\0'; }                  // #1  nie trzeba pisac definicji w Peson.cpp bo definicja metody jest tutaj
        Person(const string & ln, const char * fn = "HejTy");    // #2

        void Show() const;              // imie nazwisko
        void FormalShow() const;        // nazwisko imie
};

#endif // PERSON_H_INCLUDED
