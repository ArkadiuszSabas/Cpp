#include "complex0.h"

int main()
{
   complex a(3.0, 4.0);
   complex c;
   cout << "Podaj liczbe zespolona (k, aby zakonczyc): \n";
   while (cin >> c)
   {
       cout << "c to " << c << '\n';
       cout << "sprzezona z c to " << ~c << '\n';
       cout << "a to " << a << '\n';
       cout << "a + c wynosi " << a + c << '\n';
       cout << "a - c wynosi " << a - c << '\n';
       cout << "a * c wynosi " << a * c << '\n';
       cout << "2 * c wynosi " << 2 * c << '\n';
       cout << "Podaj liczbe zepolona (k, aby zakonczyc):\n";
   }
   cout << "Gotowe! \n";


    return 0;
}
