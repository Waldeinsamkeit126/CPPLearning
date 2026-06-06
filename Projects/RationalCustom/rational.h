#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&); // assumes non-zero second argument
    friend istream& operator>>(istream&, Rational&);
    friend ostream& operator<<(ostream&, const Rational&);
private:
    int num, den; // always stored in the reduced form
    void reduce();
public:
    Rational(int = 0, int = 1);
};

#endif