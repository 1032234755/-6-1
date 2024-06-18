#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double f1(vector<double> x) {
    return pow(x[0], 2) + 3 * pow(x[1], 2) + cos(x[0] + x[1]);
}

vector<double> coordinate_descent(double (*f)(vector<double>), vector<double> x0, double lr = 0.1, int max_iter = 100) {
    vector<double> x = x0;
    for (int iter = 0; iter < max_iter; ++iter) {
        for (size_t i = 0; i < x.size(); ++i) {
            vector<double> grad(x.size(), 0.0);
            grad[i] = 1.0;
            x[i] -= lr * grad[i] * (f({ x[0] + grad[0], x[1] + grad[1] }) - f({ x[0] - grad[0], x[1] - grad[1] })) / 2;
        }
    }
    return x;
}

int main() {
    vector<double> x0 = { 0.5, 0.5 };
    vector<double> solution = coordinate_descent(f1, x0);
    cout << "Решение методом покоординатного спуска: [" << solution[0] << ", " << solution[1] << "]" << endl;
    return 0;
}
