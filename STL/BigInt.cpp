#include <iostream>
using namespace std;

class Big_int {
    // declare friend for the + operator
    friend Big_int operator+(const Big_int&, const Big_int&);
    friend ostream &operator<<(ostream &, const Big_int &);
    int *d, len;
public:
    Big_int() {
    }
    Big_int(long long);
    ~Big_int();
};

ostream &operator<<(ostream &, const Big_int &);
Big_int operator+(const Big_int &, const Big_int &);

int main() {
    Big_int a(123456789012345ll);
    cout << 12345ll + a << '\n';
    cout << a + 999999999999999ll << '\n';
    return 0;
}

// implement the constructor with a long long argument
Big_int::Big_int(long long a) {
    for (int i = 1; pow(10, i) <= a; i++) {
        len = i + 1;
    }
    d = new int[len+1];
    for (int i = 0; i < len; i++) {
        d[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        d[i] = a % 10;
        a /= 10;
    }
    len--;
}


ostream &operator<<(ostream &os, const Big_int &x) {
    for (int i = x.len; i >= 0; --i)
        os << x.d[i];
    return os;
}

Big_int operator+(const Big_int &x, const Big_int &y) {
    Big_int ans;
    ans.len = (x.len < y.len ? y.len : x.len) + 1;
    ans.d = new int[ans.len + 1];
    for (int k = 0; k <= ans.len; ++k)
        ans.d[k] = 0;
    for (int i = 0; i <= x.len; ++i)
        ans.d[i] = x.d[i];
    for (int j = 0; j <= y.len; ++j)
        ans.d[j] += y.d[j];
    for (int k = 0; k < ans.len; ++k) {
        ans.d[k + 1] += ans.d[k] / 10;
        ans.d[k] %= 10;
    }
    if (ans.d[ans.len] == 0)
        --ans.len;
    return ans;
}

Big_int::~Big_int() {
    delete [] d;
}
