// Code for Binary Search
#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(logn)

int binarySearch(int A[], int n, int key) {
	int l = 0, h = n - 1;
	while (l <= h) {
		int mid = l + ((h - l) / 2);
		if (key == A[mid]) return mid;
		else if (key < A[mid]) h = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

int main() {

	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	cout << "Enter the values for the array: \n";
	int *A = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	int key;
	cout << "Enter the key element to be searched: ";
	cin >> key;

	int res = binarySearch(A, n, key);

	if (res) cout << key << " exists at position " << res << "\n";
	else cout << key << " does not exists\n";

	delete []A;

	return 0;
}
