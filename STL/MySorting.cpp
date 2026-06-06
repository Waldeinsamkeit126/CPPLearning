#include <iostream>
using namespace std;


bool greater_than(int, int);
bool less_than(int, int);
bool odd_first(int, int);
void print(int *, int *);

void my_sort(int* st, int* ed, bool (*cmp)(int, int)) {
    int n = ed - st;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (cmp(st[j+1], st[j])) {
                int t = st[j];
                st[j] = st[j + 1];
                st[j + 1] = t;
            }
        }
    }
}

int main() {
    int x[] = {2, 1, 4, 7, 4, 8, 3, 6, 1, 4, 7};
    my_sort(x, x + 10, greater_than);
    print(x, x + 10);
    my_sort(x, x + 10, less_than);
    print(x, x + 10);
    my_sort(x, x + 10, odd_first);
    print(x, x + 10);
    return 0;
}

bool greater_than(int a, int b) {
    return a > b;
}

bool less_than(int a, int b) {
    return a < b;
}

bool odd_first(int a, int b) {
    if ((a % 2) && !(b % 2))
        return true;
    if (!(a % 2) && (b % 2))
        return false;
    return a < b;
}

void print(int *st, int *ed) {
    for (int *iter = st; iter < ed; ++iter)
        std::cout << *iter << ' ';
    std::cout << '\n';
}
