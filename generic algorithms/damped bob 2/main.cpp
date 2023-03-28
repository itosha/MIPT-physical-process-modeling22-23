#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>

double T = 100;
double tau = 30;

using namespace std;
template<typename value_type>
class MyState {
public:
    array <value_type, 3> state;

    double omega2;
    double TwoGamma;
    double A;
    double omega;

    //MyState(array<value_type, 2> data): state(data), omega2(1), TwoGamma(1) {    }
    MyState(array<value_type, 3> data, double omega2, double gamma, double A, double omega): state(data), omega2(omega2), TwoGamma(gamma), A(A), omega(omega) {    }

    value_type& operator[] (int i) {
        return state[i];
    }

    MyState operator + (MyState other_state) {
        array <value_type, 3> arr;
        for(size_t i = 0; i < state.size(); i++) {
            arr[i] = state[i] + other_state[i];
        }
        return MyState(arr, omega2, TwoGamma, A, omega);
    }

    template <typename P>
    MyState operator * (P constant) {
        array <value_type, 3> arr;
        for(size_t i = 0; i < state.size(); i++) {
            arr[i] = state[i] * constant;
        }
        return MyState(arr, omega2, TwoGamma, A, omega);
    }

    static MyState dfdt(MyState& s){
        //cout<<s.omega2<<"   "<<s.TwoGamma<<"    ";
        return MyState {array<value_type, 3> {s[1], s.A * cos(s.omega * s[2]) - (s.TwoGamma * s[1] + s.omega2 * s[0]), 1}, s.omega2, s.TwoGamma, s.A, s.omega};
    }

    friend int F(MyState& s) {
        if (fmod(s[2], T) > tau) {
            return 0;
        } else {
            return 1;
        }
    }
};

template <class T>
T generic_euler (T& last_state, double dt) {
    T step = T :: dfdt(last_state);
    T new_state(last_state);
    for (size_t i = 0; i < last_state.state.size(); i++) {
        new_state[i] = last_state[i] + dt * step[i];
    }
    return new_state;
}

template <class T>
T generic_hoen (T& last_state, double dt) {
    T step = T :: dfdt(last_state);
    T next_state = generic_euler<T>(last_state, dt);
    T next_step = T :: dfdt(next_state);
    T new_state(last_state);
    for (size_t i = 0; i < last_state.state.size(); i++) {
        new_state[i] = last_state[i] + dt * (step[i] + next_step[i]) /  2;
    }
    return new_state;
}

template <class T>
T generic_genge4 (T& last_state, double dt) {
    T k1 = T :: dfdt(last_state);
    T cup = last_state + k1 * (dt * 0.5);
    T k2 = T :: dfdt(cup);
    cup = last_state + k2 * (dt * 0.5);
    T k3 = T :: dfdt(cup);
    cup = last_state + k3 * dt;
    T k4 = T :: dfdt(cup);
    T new_state = last_state + (k1 + k2 * 2 + k3 * 2 + k4) * (dt / 6);
    return new_state;
}

void Solve() {
    cout<<tau<<"    "<<T<<";";
    ifstream fin;
    fin.open("data.txt");
    double X0, Y0, T0, omega, gamma, A, omegaforce, dt;
    long long numb_of_tests;
    fin>>X0>>Y0>>T0>>omega>>gamma>>A>>omegaforce>>dt>>numb_of_tests;
    fin.close();
cout<<"!";
    //double constant = -1 * fma(omega, omega, 0.d);
    double* Xdata =  new double[numb_of_tests];
    double* Vdata =  new double[numb_of_tests];
    Xdata[0] = X0;
    Vdata[0] = Y0;
    cout<<"!";
    double* Tdata =  new double[numb_of_tests];
    //double Tdata[numb_of_tests];
    Tdata[0] = T0;
    cout<<"!";
    //cout<<X0<<" "<<Y0<<"    "<<omega<<" "<<gamma<<" "<<dt<<"    "<<numb_of_tests;
    MyState<double> init(std::array<double,3>{X0, Y0, T0}, omega * omega, 2 * gamma, A, omegaforce);

    for (long long i = 1; i < numb_of_tests; i++) {
        init = generic_genge4<MyState<double>>(init, dt);
        Xdata[i] = init[0];
        Vdata[i] = init[1];
        Tdata[i] = init[2];
    }

    ofstream fout;
    fout.open("table.txt");

    for(long long i = 0; i < numb_of_tests; i++)
    {
        fout<<scientific<<Xdata[i]<<"   "<<endl;
    }

    fout.close();

    fout.open("Vtable.txt");

    for(long long i = 0; i < numb_of_tests; i++)
    {
        fout<<scientific<<Vdata[i]<<"   "<<endl;
    }

    fout.close();

    fout.open("Ttable.txt");

    for(long long i = 0; i < numb_of_tests; i++)
    {
        fout<<scientific<<Tdata[i]<<"   "<<endl;
    }

    fout.close();

    fout.open("EnergyTable.txt");

    for(long long i = 0; i < numb_of_tests; i++)
    {
        fout<<0<<"  "<<endl;
        //fout<<0.5*fma(-1*constant, Xdata[i]*Xdata[i], Vdata[i]*Vdata[i])<<"   "<<endl;
    }

    fout.close();

    delete[] Xdata;
    delete[] Vdata;
    delete[] Tdata;
}

int main()
{
    Solve();
    /*MyState<float> init(std::array<float,2>{1.0f, 0.0f});
    auto step = generic_euler<MyState<float>>(init, 0.01);
    auto step2 = generic_hoen<MyState<float>>(init, 0.01);
    auto step3 = generic_genge4<MyState<float>>(init, 0.01);

    cout << "hello" << endl;
    cout << step[0] << "    " <<step[1] << endl;
    cout << step2[0] << "    " <<step2[1] << endl;
    cout << step3[0] << "    " <<step3[1] << endl;*/
    return 0;
}
