#include <iostream>
#include <cmath>
using namespace std;

// declare friend and implement * operator as a global function ; implement the ^ operation as a member function
class Point {
    friend istream &operator>>(istream &, Point &);
    friend ostream &operator<<(ostream &, const Point &);
    friend double operator*(Point &, Point &);

private:
    double x, y;
public:
    Point(double = 0., double = 0.);
    Point operator-(const Point &) const;
    double operator^(const Point &) const;
};

istream &operator>>(istream &, Point &);
ostream &operator<<(ostream &, const Point &);

int main() {
    Point a, b, c, ab, ac;
    cin >> a >> b >> c;
    ab = b - a;
    ac = c - a;

    if (ab * ac == 0)
        cout << a << b << " is perpendicular to " << a << c << endl;
    else
        cout << a << b << " is not perpendicular to " << a << c << endl;

    if ((ab ^ ac) == 0)
        cout << a << b << c << " are on the same line." << endl;
    else
        cout << a << b << c << " are not on the same line." << endl;
    return 0;
}

istream &operator>>(istream &is, Point &p) {
    return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, const Point &p) {
    return os << '(' << p.x << ", " << p.y << ')';
}

Point::Point(double x, double y) : x(x), y(y) {
}

Point Point::operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
}

double operator*(Point &a, Point &b) {
    return a.x * b.x + a.y * b.y;
}

double Point::operator^(const Point& a) const {
    return a.x * x - a.y * y;
}
