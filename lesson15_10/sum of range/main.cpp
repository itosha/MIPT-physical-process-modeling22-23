#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

template<class T>
T SumOfFirst(T est)
{
    T ResaltSum = 0;
    T PrevStep = 0;
    unsigned long long n = 1;
    do {
        PrevStep = ResaltSum;
        ResaltSum += 1 / static_cast<T>(pow(2, n));
        n++;
    } while(ResaltSum != PrevStep);

    return ResaltSum;
}

template<class T>
T SumOfSecound(T est)
{
    T ResaltSum = 0;
    T PrevStep = 0;
    unsigned long long n = 1;
    do {
        PrevStep = ResaltSum;
        ResaltSum += 1 / static_cast<T>(n);
        n++;
    } while(ResaltSum != PrevStep);

    return ResaltSum;
}

template<class T>
T MacloranOfSin(T x, T est, unsigned number)
{
    T ResaltSum = 0;
    T PrevStep = 0;
    unsigned long long n = 0;
    unsigned long long factorial = 1;
    do {
        PrevStep = ResaltSum;
        ResaltSum += static_cast<T>(pow(-1,n%2)) * pow(x, 2*n + 1) / factorial;
        n++;
        factorial = factorial * 2 * n * (2 * n + 1);
    }  while(n < number);
   // cout<<n<<endl;

    return ResaltSum;
}

template<class T>
T MacloranOfSinRevers(T x, T est, unsigned number)
{
    T ResaltSum = 0;
    unsigned long long factorial = 1;
    for(int i = 1; i <= number; i++) {
        factorial *= i;
    }
    do {
        ResaltSum += static_cast<T>(pow(-1,number%2)) * pow(x, 2*number + 1) / factorial;
        factorial = factorial / number;
        number--;
    }  while(number > -1);

    return ResaltSum;
}

double Integral(unsigned stop, double dx)
{
    double ResaltSum = 0;
    double x = 0;
    do {
        ResaltSum += static_cast<double>(pow(M_E,-pow(x, 2))) * dx;
        x+=dx;
    }  while(x < stop);
   // cout<<n<<endl;

    return ResaltSum;
}


int main()
{
    //cout << setprecision(40) << fixed;
    cout<<SumOfFirst<float>(0.000001)<<endl;
    cout<<SumOfFirst<double>(0.000001)<<endl;
    cout<<SumOfSecound<float>(0.00000001)<<endl;
    //cout<<SumOfSecound<double>(0.00000001)<<endl;
    cout<<scientific<<MacloranOfSin<double>(-0.05, 0.000000001, 33) <<endl<<sin(-0.05)<<endl;
    cout<<scientific<<MacloranOfSinRevers<double>(-0.05, 0.000000001, 33)<<endl;
    cout<<"Intergate result:   "<<scientific<<Integral(10, 0.01)<<endl;
    cout<<"Intergate result:   "<<scientific<<Integral(10000, 0.01)<<endl;
    cout<<"Intergate result:   "<<scientific<<Integral(1000, 0.0001)<<endl;
    return 0;
}
