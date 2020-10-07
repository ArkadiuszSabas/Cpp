// vect.h -- klasa Vector z operatorem << i prze³¹cznikiem trybu
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
        public:
            enum Mode {RECT, POL};
            // RECT to wspó³rzêdne kartezjañskie, POL to wspó³rzêdne biegunowe
        private:
            double x;        // wartoœæ sk³adowej poziomej
            double y;        // wartoœæ sk³adowej pionowej
            double mag;      // d³ugoœæ wektora
            double ang;      // kierunek wektora (w stopniach)
            Mode mode;       // RECT lub POL
            // prywatne metody ustawiaj¹ce sk³adowe
            void set_mag();
            void set_ang();
            void set_x();
            void set_y();
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval() const {return x;}      // zwraca wartoœæ sk³adowej x
            double yval() const {return y;}      // zwraca wartoœæ sk³adowej y
            double magval() const {return mag;}  // zwraca d³ugoœæ
            double angval() const {return ang;}  // zwraca k¹t
            void polar_mode();    // ustawia tryb na biegunowy (POL)
            void rect_mode();     // ustawia tryb na kartezjañski (RECT)
            // metody przeci¹¿aj¹ce operatory
            Vector operator+(const Vector & b) const;
            Vector operator-(const Vector & b) const;
            Vector operator-() const;
            Vector operator*(double n) const;
            // funkcje zaprzyjaŸnione
            friend Vector operator*(double n, const Vector & a);
            friend std::ostream &
                operator<<(std::ostream & os, const Vector & v);
    };
} // koniec przestrzeni nazw VECTOR
#endif

