#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a;
    int x;

    while (cin >> x) {
        a.push_back(x);
    }

    vector<int> tail1;

    for (int x : a) {
        x = -x;

        auto it = upper_bound(tail1.begin(), tail1.end(), x);

        if (it == tail1.end()) {
            tail1.push_back(x);
        }
        else {
            *it = x;
        }
    }

    vector<int> tail2;

    for (int x : a) {
        auto it = lower_bound(tail2.begin(), tail2.end(), x);

        if (it == tail2.end()) {
            tail2.push_back(x);
        }
        else {
            *it = x;
        }
    }

    cout << tail1.size() << '\n';
    cout << tail2.size() << '\n';

    return 0;
}