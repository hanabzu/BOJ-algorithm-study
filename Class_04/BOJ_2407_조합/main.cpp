/* hanabzu */
/* BOJ_2407 조합 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M, x;

string result;

class BigInt { // Big Integer using string
public:
	string value;
	BigInt();
	BigInt(int num);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
	void print_value();
};

BigInt combination(int n, int m);
BigInt memo[101][101]; // memoization array

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	combination(N, M).print_value();

	return 0;
}

BigInt combination(int n, int m) { // paskal's triangle

	if (m > (n >> 1)) {
		m = n - m;
	}

	if (memo[n][m].value != "0") {
		return memo[n][m];
	}

	if (n == 0) {
		return BigInt(1);
	}

	if (m == 1) {
		return BigInt(n);
	}

	memo[n][m] = combination(n - 1, m - 1) + combination(n - 1, m);
	return memo[n][m];
}

BigInt::BigInt() {
	this->value = "0";
}

BigInt::BigInt(int num) {
	this->value = to_string(num);
	reverse(this->value.begin(), this->value.end());
}

BigInt operator+(const BigInt& a, const BigInt& b) {
	BigInt newBigInt, big, small;
	if (a.value.size() > b.value.size()) {
		big.value = a.value;
		small.value = b.value;
	}
	else {
		big.value = b.value;
		small.value = a.value;
	}

	newBigInt.value.resize(big.value.size(), '0');

	for (int i = 0; i < small.value.size(); i++) {
		newBigInt.value[i] += (big.value[i] - '0') + (small.value[i] - '0');
		if (newBigInt.value[i] > '9') {
			newBigInt.value[i] -= 10;
			if (i != big.value.size() - 1 || big.value.size() != small.value.size()) {
				newBigInt.value[i + 1]++;
			}
			else {
				newBigInt.value += "1";
			}

		}
	}

	for (int i = small.value.size(); i < big.value.size(); i++) { // add left digits
		newBigInt.value[i] += big.value[i] - '0';
		if (newBigInt.value[i] > '9') {
			newBigInt.value[i] -= 10;
			if (i != big.value.size() - 1) {
				newBigInt.value[i + 1]++;
			}
			else {
				newBigInt.value += "1";
			}
		}
	}

	return newBigInt;
}

void BigInt::print_value() { // reversed order
	for (int i = value.size() - 1; i >= 0; i--) {
		cout << value[i];
	}
}