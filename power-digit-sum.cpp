#include <iostream>
#include <string>

using namespace std;

// Global variables for input strings and parsed integers
string a, b;
int n, m;

// Validates whether an input string contains only numeric digits (0-9).
// Returns false for negative numbers, decimals, or non-numeric characters.
bool check(string a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < '0' || a[i] > '9') {
			return false;
		}
	}
	return true;
}

// Checks whether the length of the string input does not exceed 4 digits
// to prevent integer overflow when parsing.
bool check_value(string a) {
	if (a.size() > 4) return false;
	return true;
}

// Computes a raised to the power of b (a^b).
// Handles non-negative exponents, including 0 (where a^0 = 1).
int power(int a, int b) {
	int res = 1; 
	for (int i = 1; i <= b; i++) {
		res *= a;
	}
	return res;
}

// Calculates the sum of all individual digits in an integer.
int sum_digits(int a) {
	int res = 0;
	while (a != 0) {
		res += a % 10; // Extract and add the last digit
		a = a / 10;    // Remove the last digit
	}
	return res;
}

int main() {
	// Read inputs for base and exponent
	cin >> a >> b;

	// Validate that inputs consist only of positive integers/digits
	if (!check(a) || !check(b)) {
		cout << "Integer only and no negatives allowed!";
		return 0;
	}

	// Validate that input sizes are within acceptable limits
	if (!check_value(a) || !check_value(b)) {
		cout << "value too large";
		return 0;
	}

	// Convert validated string inputs to integer values
	n = stoi(a);
	m = stoi(b);

	// Compute n^m, sum its digits, and output the result
	cout << sum_digits(power(n, m));

	return 0;
}
