#ifndef GWIAZDA_H_INCLUDED
#define GWIAZDA_H_INCLUDED

using namespace std;

class Gwiazda
{
    private:
        static const int LIMIT = 19;
        char imie[LIMIT];
        int sytosc;

    public:
        Gwiazda(char * im = "Plorga");
        void showGwiazda() const;
        void setSytosc(int syt);

};


#endif // GWIAZDA_H_INCLUDED
