#include <iostream>
#include <fstream>
#include <limits>
#include <array>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool solve(string napis1, string napis2)
    {
        bool flag = false;
        int kwadratoweL = 0, okragleL = 0, kwadratoweP = 0, okragleP = 0, klamroweL = 0, klamroweP = 0;
        for(char c : napis1)
        {
            switch (c)
            {
            case '[':
                ++kwadratoweL;
                break;
            case '(':
                ++okragleL;
                break;
            case ']':
                ++kwadratoweP;
                break;
            case ')':
                ++okragleP;
                break;
            case '{':
                ++klamroweL;
                break;
            case '}':
                ++klamroweP;
                break;
            }
        }

        if (kwadratoweL != kwadratoweL || okragleL != okragleP || klamroweL != klamroweP) return flag;

        kwadratoweL = kwadratoweP = okragleL = okragleP = klamroweL = klamroweP = 0;

        for(char c : napis2)
        {
            switch (c)
            {
            case '[':
                ++kwadratoweL;
                break;
            case '(':
                ++okragleL;
                break;
            case ']':
                ++kwadratoweP;
                break;

            case ')':
                ++okragleP;
                break;
            case '{':
                ++klamroweL;
                break;
            case '}':
                ++klamroweP;
                break;
            }
        }

        if (kwadratoweL != kwadratoweP || okragleL != okragleP || klamroweL != klamroweP) return flag;
        else return flag = true;
	}

int main()
{

    bool s = solve("asdas(')[]([{}])","()[]{}");
    cout << s;

    return 0;
}


