#include <bits/stdc++.h>
using namespace std;

// get the maximum value
int max(int x, int y) {
	return (x >= y) ? x : y;
}

void largestCommonSubsequence(char* str1, char* str2, int l1, int l2) {

	// creating the matrix
	int dp[l1 + 1][l2 + 1];
	int i, j, k;

	// Set 0th row and 0th column as 0
	for (i = 0; i <= l1; i++) 
		dp[i][0] = 0;
	for (i = 0; i <= l2; i++) 
		dp[0][i] = 0;

	// filling the matrix with values based on the equality of characters
	for (i = 1; i <= l1; i++) {
		for (j = 1; j <= l2; j++) {
			if (str1[i - 1] == str2[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// the last cell has the largest length 
	int len = dp[l1][l2];
	k = len;
	// creating a string fot the result subsequence
	char* sub = new char[len + 1];
	sub[len] = '\0';
	len--;

	// bottom top approach in dp
	i = l1;
	j = l2;
	while (i >= 1 && j >= 1) {
		// take diagonal cut => this is where the characters are to be copied
		if (str1[i - 1] == str2[j - 1]) {
			i--; 
			j--;
			sub[len] = str1[i];
			len--;
		} 
		// go up
		else if (dp[i -1][j] > dp[i][j - 1]) {
			i--;
		}
		// go left
		else {
			j--;
		}
	}

	// Output
	cout << "\n\nLength: " << k << "\n";
	cout << "The longest common substring is : ";
	for (i = 0; sub[i]; i++) 
		cout << sub[i] << " ";
	cout << "\n";

	// freeing the pointer
	delete [] sub;
}

int main() {

	int l1, l2;

	// getting the input

	cout << "Enter the string 1 and string 2 length: ";
	cin >> l1 >> l2;

	char* str1 = new char[l1 + 1];
	cout << "Enter the string 1: ";
	cin >> str1;

	char* str2 = new char[l2 + 1];
	cout << "Enter the string 2: ";
	cin >> str2;

	largestCommonSubsequence(str1, str2, l1, l2);

	delete[] str1;
	delete[] str2;

	return 0;
}
