#include <iostream>
#include <math.h>
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
    cout<<n<<endl;

    return ResaltSum;
}


int main()
{
    //cout << setprecision(40) << fixed;
    cout<<SumOfFirst<float>(0.000001)<<endl;
    cout<<SumOfFirst<double>(0.000001)<<endl;
    cout<<SumOfSecound<float>(0.00000001)<<endl;
    //cout<<SumOfSecound<double>(0.00000001)<<endl;
    cout<<scientific<<MacloranOfSin<double>(0.05, 0.000000001, 33) - sin(0.05)<<endl;
    return 0;
}
