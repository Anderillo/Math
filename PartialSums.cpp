#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
    // return (6/sqrt(x)-6/sqrt(x+1));
    // return 1/(3*x);
    // return x/sqrt(pow(x, 2) + 4);
    return (sin(1/x)-sin(1/x+1));
}

pair<vector<double>, vector<double>> partialSum(int n_starting, int n_ending) {
    vector<double> terms, partial_sums;
    double running = 0;
    for (int i = n_starting; i <= n_ending; i++) {
        double current = f(i);
        terms.push_back(current);
        running += current;
        partial_sums.push_back(running);
    }
    pair<vector<double>, vector<double>> result;
    result.first = terms;
    result.second = partial_sums;
    return result;
}

int main(int argc, char* argv[]) {
    int n_starting = stoi(argv[1]);
    int n_ending = stoi(argv[2]);
    int precision = stoi(argv[3]);

    cout << fixed << setprecision(precision);
    cout << "Partial sums" << endl;
    pair<vector<double>, vector<double>> result = partialSum(n_starting, n_ending);
    for (int i = 0; i < result.first.size(); i++) {
        cout << "\ta" << i + n_starting << ": " << result.first[i] << "\tS" << i + n_starting << ": " << result.second[i] << endl;
    }

    return 0;
}