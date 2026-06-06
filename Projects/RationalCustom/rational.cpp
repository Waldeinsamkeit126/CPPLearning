#include "rational.h"

Rational::Rational(int num,int den):num(num),den(den) {
	reduce();
}

void Rational::reduce() {
	int minnum = min(num, den);
	for (int i = minnum; i > 1; i--) {
		if (num % minnum == 0) {
			if (den % minnum == 0) {
				num /= minnum;
				den /= minnum;
			}
		}
	}
}

Rational operator+(const Rational& r1, const Rational& r2) {
	int newnum = r1.num * r2.den + r2.num * r1.den;
	int newden = r1.den * r2.den;
	return Rational(newnum, newden);
}

Rational operator-(const Rational& r1, const Rational& r2) {
	int newnum = r1.num * r2.den + r2.num * r1.den;
	int newden = r1.den * r2.den;
	return Rational(newnum, newden);
}

Rational operator*(const Rational& r1, const Rational& r2) {
	int newnum = r1.num * r2.num;
	int newden = r1.den * r2.den;
	return Rational(newnum, newden);
}

Rational operator/(const Rational& r1, const Rational& r2) {
	int newnum = r1.num * r2.den;
	int newden = r1.den * r2.num;
	return Rational(newnum, newden);
}

istream& operator>>(istream& iput, Rational& r) {
	iput >> r.num >> r.den;
	r.reduce();
	return iput;
}

ostream& operator<<(ostream& oput, const Rational& r) {
	oput << "(" << r.num << "/" << r.den << ")";
	return oput;
}