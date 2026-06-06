#include <iostream>
using namespace std;

template <class T>

void my_merge(T* start1, T* end1, T* start2, T* end2, T* ans) {
    int i = 0, j = 0, k = 0;
    while (start1 + i < end1 && start2 + j < end2) {
        if (start1[i] < start2[j]) {
            ans[k] = start1[i];
            i++;
            k++;
        }
        else {
            ans[k] = start2[j];
            j++;
            k++;
        }
    }
    while (start1 + i < end1) {
        ans[k] = start1[i];
        i++;
        k++;
    }
    while (start2 + j < end2) {
        ans[k] = start2[j];
        j++;
        k++;
    }
}

int main() {
    char s1[] = "ehllo", s2[] = "dlorw", s3[11];
    my_merge(s1, s1 + 5, s2, s2 + 5, s3);
    s3[10] = '\0';
    cout << s3 << endl;

    int x[] = { 1, 3, 6 }, y[] = { 2, 7, 9, 10 }, z[7];
    my_merge(x, x + 3, y, y + 4, z);
    for (int i = 0; i < 7; ++i)
        cout << z[i] << ' ';
    cout << endl;
    return 0;
}
