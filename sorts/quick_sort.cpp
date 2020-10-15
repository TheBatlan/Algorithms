#include <bits/stdc++.h>
using namespace std;

void getArray(int* A, int n) {
	cout << "Enter the array: ";
	for (int i = 0; i < n; i++) cin >> A[i];
}

void displayArray(int* A, int n) {
	cout << "The array: ";
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << endl;
}

int partition(int A[], int l, int h) {
	int i = l, j = h;
	// selecting the first element as pivot
	int pivot = A[l];

	do {
		// i looks for element greater than pivot
		do {i++;} while (A[i] <= pivot);
		// j looks for element lesser than or equal to pivot
		do {j--;} while (A[j] > pivot);

		if (i < j) swap(A[i], A[j]); 
	} while (i < j);

	// swapping the pivot for the partitioning position
	swap(A[l], A[j]);

	// returing the partition position
	return j;
}

void QuickSort(int A[], int l, int h) {
	int j;
	// atleast two elements
	if (l < h) {
		// partitioning position
		j = partition(A, l, h);
		// first half
		QuickSort(A, l, j);
		// second half
		QuickSort(A, j + 1, h);
	}
}

int main() {

	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int A[n + 1];

	// get input
	getArray(A, n);
	A[n] = INT32_MAX;

	// QuickSort
	QuickSort(A, 0, n);

	// display the array
	displayArray(A, n);

	return 0;
}

