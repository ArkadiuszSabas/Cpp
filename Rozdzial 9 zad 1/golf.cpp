#include <iostream>
#include <string.h>
#include "golf.hpp"

void setgolf(golf & g, char * name, int hc)
{
    strcpy(g.fullname,name);
    //g.fullname = name;   // niedozwolone jest kopiowanie char * na char[] za pomoca oepratora przypisania. W druga srone char[] do char * chyba mozna
    g.handicap = hc;
}

void setgolf(golf & g)
{
    using namespace std;
    cout << "Podaj nazwe golfa: ";
    cin >> g.fullname;
    cout << "Podaj handicap: ";
    cin >> g.handicap;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using std::cout;   // w takim przypadku podaje sie tylko metody bez "namespace". Przy dyrektywie psize sie namespace np "using namespace std"
    using std::endl;
    cout << g.fullname << ", "
         << g.handicap << endl;
}
