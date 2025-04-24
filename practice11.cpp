#include <iostream>
using namespace std;

int part(int a[], int s, int e) {
    int i = s - 1;
    int pvt = a[e];

    for (int j = s; j < e; j++) {
        if (a[j] <= pvt) {
            i++;
            swap(a[j], a[i]);
        }
    }

    i++;
    swap(a[e], a[i]);
    return i;
}

void quicksort(int a[], int s, int e) {
    if (s < e) {
        int pvt = part(a, s, e);
        quicksort(a, s, pvt - 1);
        quicksort(a, pvt + 1, e);
    }
}

int main() {
    int a[] = {2, 6, 3, 4, 7, 1, 8, 9, 5};
    int n = sizeof(a) / sizeof(a[0]);

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
