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

    fout.open("Vtable.txt");

    for(int i = 0; i < numb_of_tests; i++)
    {
        fout<<Vdata[i]<<"   "<<endl;
    }

    fout.close();

    fout.open("EnergyTable.txt");

    for(int i = 0; i < numb_of_tests; i++)
    {

        fout<<0.5*fma(-1*constant, Xdata[i]*Xdata[i], Vdata[i]*Vdata[i])<<"   "<<endl;
    }

    fout.close();
}

int main()
{
    ifstream fin;
    fin.open("data.txt");
    double X0, V0, omega, dt;
    long long num_of_tests;
    fin>>X0>>V0>>omega>>dt>>num_of_tests;
    fin.close();
    dataCount(X0, V0, omega, dt, num_of_tests);
    return 0;
}
