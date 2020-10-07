#include <iostream>
#include <cctype>

using namespace std;

int main()
{

    char ch;
    cout << "Podawaj znaki, znak @ konczy program: \n";
    cin.get(ch);
    while('@' != ch)
    {
        // obslugujemy wszystkie przypadki, mala litera, duza litera, cyfra. Reszte mozna przepisac
        if (islower(ch))
           putchar(toupper(ch));
        else if (isupper(ch))
           putchar(tolower(ch));
        else if (isdigit(ch))
            {}
        else if (isprint(ch))
           putchar(ch);

        cin.get(ch);
    }

    cout << "\nKoniec programu" << endl;
    return 0;
}
