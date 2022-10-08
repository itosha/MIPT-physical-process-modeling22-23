#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


void HcEulerSch(double *X, double *V, double x0, double v0, double dt, double constant) {
    *V = fma(dt, fma(constant, x0, 0.d), v0);
    *X = fma(dt, v0, x0);
}

void dataCount(double x0, double v0, double omega, double dt, int numb_of_tests) {
    ofstream fout;
    fout.open("table.txt");

    double constant = -1 * fma(omega, omega, 0.d);
    double Xdata[numb_of_tests];
    double Vdata[numb_of_tests];
    Xdata[0] = x0;
    Vdata[0] = v0;

    for(int i = 1; i < numb_of_tests; i++)
    {
        HcEulerSch(&Xdata[i], &Vdata[i],Xdata[i-1], Vdata[i-1], dt, constant);
    }

    for(int i = 0; i < numb_of_tests; i++)
    {
        fout<<Xdata[i]<<"   "<<endl;
    }

    fout.close();
}

int main()
{
    double X0 = 1.d;
    double V0 = 0.d;
    double omega = 1.d;
    double dt = 0.1;
    int num_of_tests = 9000;
    dataCount(X0, V0, omega, dt, num_of_tests);
    return 0;
}
