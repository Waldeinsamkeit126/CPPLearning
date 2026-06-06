#include <iostream>
#include "rational.h"
using namespace std;

int main() {
    Rational a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;
    return 0;
}