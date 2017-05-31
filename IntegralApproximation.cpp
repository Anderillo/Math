#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    // return sqrt(x) * cos(x);
    // return sqrt(x + pow(x, 3));
    // It breaks on this one!
    // return exp(1/x);
    // return 1/sqrt(x);
    // return cos((atan(1)*4)*x);
    return log(1+exp(x));
}

double trapezoidalRule(double a, double b, int n/*, function f*/) {
    double dx = (b-a)/n;
    // cout << "b: " << b << endl;
    // cout << "dx: " << dx << endl;
    double Tn = 0;
    cout << fixed << setprecision(3);
    int counter = 0;
    for (double i = a; i <= b; i += dx) {
        cout << i << ", ";
        double temp = f(i);
        // cout << temp;
        if (counter > 0 && counter < n) {
            temp *= 2;
            // cout << "*2";
        }
        // cout << "+";
        Tn += temp;
        counter++;
    }
    // Tn += f(b);
    // cout << endl;
    // cout << "(dx/2): " << dx << "/" << 2 << endl;
    Tn *= (dx/2.0);
    return Tn;
}

double midpointRule(double a, double b, int n) {
    double dx = (b-a)/n;
    double Mn = 0;
    cout << fixed << setprecision(3);
    for (double i = a+(dx/2); i < b; i += dx) {
        cout << i << ", ";
        Mn += f(i);
    }
    Mn *= dx;
    return Mn;
}

double simpsonsRule(double a, double b, int n) {
    double dx = (b-a)/n;
    // cout << "dx: " << dx << endl;
    double Sn = 0;
    int counter = 0;
    cout << fixed << setprecision(3);
    for (double i = a; i <= b; i+= dx) {
        cout << i << ", ";                                              
        double to_multiply = 1;
        if (counter > 0 && counter < n) {
            if (counter % 2 == 0) to_multiply = 2;
            else to_multiply = 4;
        }
        Sn += (f(i) * to_multiply);
        counter++;
    }

    Sn *= (dx/3);
    return Sn;
}

void testF() {
    for (double i = 0; i <= 1; i += 0.1) {
        cout << i << "|" << f(i) << endl;
    }
}

int main(int argc, char* argv[]) {
    // double (*my_func)(double);
    // my_func = &f;
    double a = stoi(argv[1]);
    double b = stoi(argv[2]);
    int n = stoi(argv[3]);
    // testF();
    cout << "T" << n << ": " << fixed << setprecision(6) << trapezoidalRule(a, b, n) << endl;
    cout << "M" << n << ": " << fixed << setprecision(6) << midpointRule(a, b, n) << endl;
    cout << "S" << n << ": " << fixed << setprecision(6) << simpsonsRule(a, b, n) << endl;
    return 0;
}
