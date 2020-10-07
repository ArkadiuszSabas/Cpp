#include <iostream>

using namespace std;

// STALE
const int SLEN = 30;

struct student
{
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

int getinfo(student pa[], int tabSize);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    cout << "Podaj wielkosc grupy: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')  // mozna by dac tylko jedno cin.get() gdyz pobierze on znak nowej lini.
        continue;

    student * ptr_stu = new student[class_size]; // TO JEST DALEJ TABLICA MIMO ZE JEST NEW !!! NIE MYLIC Z LISTA JEDNOKIERUNKOWA I TEGO TYPU RZECZAMI. Mimo ze to wskaznik mozna operowac nim jak tablica !!!!
    int entered = getinfo(ptr_stu, class_size);
    for(int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Gotowe\n";



    cout << "Hello world!" << endl;
    return 0;
}

int getinfo(student pa[], int tabSize)
{
    int counter = 0;
    for(int i = 0; i<tabSize; i++)
    {
        cout << "Podaj nazwisko: ";
        cin >> pa[i].fullname;
        cout << "Podaj swoje hobby: ";
        cin >> pa[i].hobby;
        cout << "Podaj ooplevel: ";
        cin >> pa[i].ooplevel;
        counter++;
    }
    return counter;
}

void display1(student st)
{
    cout << "Student: \n";
    cout << "Imie: " << st.fullname << endl;
    cout << "Nazwisko: " << st.hobby << endl;
    cout << "Ooplevel: " << st.ooplevel << endl;
}

void display2(const student * ps)
{
    cout << "Student: \n";
    cout << "Imie: " << ps->fullname << endl;
    cout << "Nazwisko: " << ps->hobby << endl;
    cout << "Ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    cout << "Lista wszszytkich studentow przez tablice: \n";
    for(int i = 0; i < n; i++)
    {
        cout << "Imie: " << pa[i].fullname << endl;
        cout << "Nazwisko: " << pa[i].hobby << endl;
        cout << "Ooplevel: " << pa[i].ooplevel << endl;
    }
}


