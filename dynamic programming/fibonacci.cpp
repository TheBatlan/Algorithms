#include <bits/stdc++.h>
using namespace std;

// Code for fibonnaci number of nth position in O(n) time
int fibonacci(int n) {
    int x;
    int* fib = new int[n + 1];
    if (n <= 1) {
        x = n;
    }
    else {
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 2] + fib[i - 1];
        }
        x = fib[n];
        delete [] fib;
    } 
    return x;
}

int main() {

    int n;
    cout << "Enter the nth number: ";
    cin >> n;

    cout << n << "th fibonacci number is : " << fibonacci(n) << "\n";

    return 0;
}
