#ifndef GOLF_H_INCLUDED
#define GOLF_H_INCLUDED

const int Len = 40;

struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf & g, char * name, int hc);

void setgolf(golf & g);

void handicap(golf & g, int hc);

void showgolf(const golf & g);

#endif // GOLF_H_INCLUDED
