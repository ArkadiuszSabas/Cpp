#include <iostream>
#include <string>
#include <string.h>

using namespace std;

// STRUCTURES
struct szef
{
    int liczba;
};

struct map
{
    int liczba;
};

struct applicant
{
    char name[30];
    int credit_ratings[3];
};



//PROTOTYPES
void zad4(int * poczatek, int * koniec, int liczba);

// 2
void igor();
float tofu(int);
double mpg(double, double);
double summation(long[], int);
double doctor(const char[]);
void oczyswiscie(szef);
char * plot(map*);
// 8
int zad8(char * str, char c1, char c2);
// 11
int judge(int (*pf)(const char *));
// 12
void zad12a(applicant app);
void zad12b(applicant * app);
// 13
void f1(applicant *a);
const char * f2(const applicant * a1, const applicant *a2);


// MAIN
int main()
{
    // 4
//    int tabsize = 5;
//    int tab[tabsize];
//    zad4(tab, tab+tabsize, 3); // operuje na oryginale
//    cout << tab[2] << endl;

    // 8
  // char * zdanie = "Arek to mistrz";     // ZLE, nie da sie zmieniac tego lancucha ?? chuj wie czemu. Jakas kompatybilnosc wsteczna
   //  zdanie[3] = 'Z'  // Taka podmiana znaku NIE ZADZIALA
   // char zdanie[25] = "Arek to mistrz";   // DOBRZE
   //  zdanie[3] = 'Z'  // Taka podmiana znaku zadziala
   // string zdanie = "Arek to mistrz";  // ZLE to string, a nie char *, nie da sie przekazac tego do tej funkcji
   // zad8(zdanie, 'k', 'Z');


   // 12
   applicant app1;
   // app1.name = "Janek";   // NIE ZADZIALA.....
   strcpy(app1.name, "Sara");
   app1.credit_ratings[0] = 11;
   app1.credit_ratings[1] = 45;
   app1.credit_ratings[2] = 78;

   zad12a(app1);    // przekazanie przez wartosc (oryginal nie zmienia wartosci)
   zad12b(&app1);   // przekazanie adresu. Oryginal bedzie modyfikowany


   // 13

   typedef void (*p_f1)(applicant *); // typ "wskzanik na funkcje"
   typedef const char *(p_f2) (const applicant *, const applicant *); // typ wskaznik na funkcje
   p_f1 p1 = f1;    // stworzenie pojedynczego obiektu
   p_f2 p2 = f2;
   p_f1 ap[5];      // stworzenie tablicy
   p_f2 (*pa)[10];

    return 0;
}

// 3
void zad3(int tab[], int tabsize, int liczba)
{
    for (int i=0; i<tabsize; i++)
    {
        tab[i] = liczba;
    }
}

// 4   mozna j¹ latwo wywyolac np zad4(tablica, tablica+tabsize). tablica to wskaznik na tablice po prostu. A tablica+tabsize to wskaznik na element ZA tabica
void zad4(int * poczatek, int * koniec, int liczba)
{
    for (int * pt = poczatek; pt!=koniec; pt++)
    {
        *pt=liczba;
    }
//    for (int * pt = poczatek; pt!=koniec; pt++)
//    {
//        cout << *pt << endl;
//    }
}

// zad 5
double zad5(const double tab[], int tabsize)
{
    int maxvalue = tab[0];
    for (int i=1; i<tabsize; ++i)
    {
        if (maxvalue>tab[i]) maxvalue=tab[i];
    }
    return maxvalue;
}

// zad 8
int zad8(char * str, char c1, char c2)
{
    int counter = 0;
    int licznikZnakow = 0;
    cout << str;     // &str TO NIE &str[0]. Oba adresy wskazuja ten sam adres, ale &str wyswietla caly lancuch znakowy, a &str[0] tylko pierwszy znak. Dlatego w cout str i *str daja rozne wyniki

    while (*str)
    {
       if (*str == c1)
       {
           *str = c2;
           counter++;
       }
        str++;
        licznikZnakow++;
    }
    cout << "\nTwoje nowe zdanie wyglada nastepujaco: \n" << str-licznikZnakow;
    cout << "\nIlosc zamienionych znakow w twoim zdaniu: " << counter << endl;
    return counter;
}

// zad 12

void zad12a(applicant app)
{
   cout << app.name << endl;
   cout << app.credit_ratings[0] << endl;
   cout << app.credit_ratings[1] << endl;
   cout << app.credit_ratings[2] << endl;
}

void zad12b(applicant * app)
{
   cout << app->name << endl;
   cout << app->credit_ratings[0] << endl;
   cout << app->credit_ratings[1] << endl;
   cout << app->credit_ratings[2] << endl;
}
