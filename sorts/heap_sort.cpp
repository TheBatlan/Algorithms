#include <bits/stdc++.h>
using namespace std;

void get_data(int* H, int n) {
	cout << "Enter the heap data: \n";
	H[0] = 0;
	for (int i = 1; i <= n; i++) 
		cin >> H[i];
}

void display(int* H, int n) {
	cout << "The sorted heap elements are:\n";
	for (int i = 1; i <= n; i++) 
		cout << H[i] << " ";
	cout << "\n"; 
}

void insert_heap(int* H, int n) {
	int i = n;
	int temp = H[i];
	while (i > 1 && temp > H[i / 2]) {
		swap(H[i], H[i / 2]);
		i = i / 2;
	}
}

void delete_heap(int* H, int n) {
	swap(H[1], H[n]);

	int i = 1;
	int j = 2 * i;

	while (j < n - 1) {
		if (H[j + 1] > H[j])
			j = j + 1;
		if (H[i] < H[j]) {
			swap(H[i], H[j]);
			i = j; j = 2 * i;
		}
		else 
			break;
	}
}

void heap_sort(int* H, int n) {
	for (int i = 1; i <= n; i++) {
		insert_heap(H, i);
	}

	for (int i = n; i >= 1; i--) {
		delete_heap(H, i);
	}
}

int main() {

	int n;
	cout << "Enter the size of the heap: \n";
	cin >> n;

	int* H = new int[n + 1];
	get_data(H, n);

	heap_sort(H, n);

	display(H, n);

	delete [] H;

	return 0;
}
