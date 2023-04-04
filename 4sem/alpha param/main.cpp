#include <iostream>
#include <iterator>
#include <fstream>
#include <functional>

using namespace std;

void long_count(double start, double a) {
    ofstream fout;
    ofstream fout2;
    fout.open("table.txt");
    fout2.open("table2.txt");
    double y0 = start;
    double y = y0;
    double const alpha = a;
    long unsigned stop = 1000;
    fout<<y<<"  ";
    fout2<<0<<"    ";
    cout<<y0<<"  "<<alpha<<"    ";
    for (long unsigned i = 1; i <= stop; i++) {
        y = alpha * y * (1 - y);
        fout<<y<<"    ";
        fout2<<i<<" ";
    }

    fout.close();
    fout2.close();
}

void alpha_count(double start, unsigned Ynum, double alp_0, double alp_end, double step) {
    ofstream fout;
    fout.open("Alp_table.txt");
    double y = start;
    for (double alpha = alp_0; alpha <= alp_end; alpha+=step) {
        y = start;
        fout<<alpha<<"  "<<y<<"  ";
        for (long unsigned i = 1; i <= Ynum; i++) {
            y = alpha * y * (1 - y);
            fout<<y<<"  ";
        }
        fout<<endl;
    }
    fout.close();
}

int main(int argc, char** argv)
{
    //alpha_count(0.1, 10, 3, 4, 0.1);
    if (argc == 3) {
        double y0 = atof(argv[1]);
        double alpha = atof(argv[2]);
        long_count(y0, alpha);
    }

    if (argc == 6) {
        cout<<argv[3]<<"    ";
        double y0 = atof(argv[1]);
        double num_y = atof(argv[2]);
        double end_alp = atof(argv[4]);
        double alpha_0 = atof(argv[3]);
        double step = atof(argv[5]);
        alpha_count(y0, num_y, alpha_0, end_alp, step);
    }
    return 0;
}
