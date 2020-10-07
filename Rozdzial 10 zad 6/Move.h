#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

using namespace std;

class Move
{
    private:
        double x;
        double y;

    public:
        Move(double a = 0, double b = 0);
        void showmove() const;
        Move add(const Move & m) const;
        void setParameters(double a = 0, double b = 0);
};

#endif // MOVE_H_INCLUDED
