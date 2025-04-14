#include <iostream>
using namespace std;

void countsort(int a[], int s, int r) {
    int output[s];
    int count[r + 1]; // +1 to include 'r' as a possible value

    // Initialize count[] to 0
    for (int i = 0; i <= r; i++) {
        count[i] = 0;
    }

    // Count occurrences
    for (int i = 0; i < s; i++) {
        count[a[i]]++;
    }

    // Prefix sum (cumulative count)
    for (int i = 1; i <= r; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (STABLE sort)
    for (int i = s - 1; i >= 0; i--) {
        output[--count[a[i]]] = a[i];
    }

    // Copy back to original array
    for (int i = 0; i < s; i++) {
        a[i] = output[i];
    }
}

int main() {
    int a[] = {3, 5, 2, 7, 4, 6, 8, 1, 9};
    countsort(a, 9, 9);
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}
