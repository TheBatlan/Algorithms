#include <bits/stdc++.h>
using namespace std;

class Merge {
private:
    int *M, *temp;
    int n;

public:
    Merge(int size) {
        this -> n = size;
        this -> M = new int[this -> n];
        int index;
        cout << "Enter the Array data: \n";
        for (index = 0; index < this -> n; index++) {
            cin >> this -> M[index];
        }

        this -> merge_sort(0, n - 1);
    }

    void merge_sort(int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            this -> merge_sort(low, mid);
            this -> merge_sort(mid + 1, high);
            this -> merge(low, mid, high);
        }
    }

    // recursive merge sort
    void merge(int low, int mid, int high) {
        this -> temp = new int[high + 1];
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high) {
            if (this -> M[i] < this -> M[j]) {
                this -> temp[k++] = this -> M[i++];
            } else {
                this -> temp[k++] = this -> M[j++];
            }
        }

        while (i <= mid) {
            this -> temp[k++] = this -> M[i++];
        }
        while (j <= high) {
            this -> temp[k++] = this -> M[j++];
        }

        for (k = low; k <= high; k++) {
            this -> M[k] = this -> temp[k];
        }
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < this -> n; i++) {
            cout << this -> M[i] << " ";
        }
        cout << "\n";
    }
};
