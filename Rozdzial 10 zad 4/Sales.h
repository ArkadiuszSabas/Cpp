#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

using namespace std;

namespace SALES
{
    const int QUARTERS = 4;
    class Sales
    {
        private:
            double sales[QUARTERS];
            double average;
            double max;
            double min;

        public:
            Sales();
            Sales(double ar[], int n);
            void showSales() const ;
            void setSales();
    };
}

#endif // SALES_H_INCLUDED
