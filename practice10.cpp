#include <iostream>
using namespace std;

void merge(int a[], int s, int mid, int e) {
    int temp[1000]; // temporary array, large enough for most cases
    int i = s;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= e) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= e) {
        temp[k++] = a[j++];
    }

    for (int index = 0; index < k; index++) {
        a[s + index] = temp[index]; // copying back to original array
    }
}

void mergesort(int a[], int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        mergesort(a, s, mid);
        mergesort(a, mid + 1, e);
        merge(a, s, mid, e);
    }
}

int main() {
    int a[] = {2, 6, 3, 4, 7, 1, 8, 9, 5};
    int n = sizeof(a) / sizeof(a[0]);

    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
