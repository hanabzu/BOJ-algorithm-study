/* hanabzu */
/* BOJ_13172 Σ */

#include <iostream>

#define PRIME 1000000007

using namespace std;

int M, N, S, G;
unsigned long long bi, result = 0; // bi = b_inversed

unsigned long long power(int num, int p);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> N >> S;

		bi = power(N, PRIME - 2);

		result += (S * bi) % PRIME;
		result %= PRIME;
	}

	cout << result;
	return 0;
}

unsigned long long power(int num, int p) { // divide and conquer
	if (p == 0) {
		return 1;
	}
	if (p == 1) {
		return num % PRIME;
	}
	unsigned long long t = power(num, p >> 1);
	if (p % 2 == 0) {
		return (t * t) % PRIME;
	}
	else {
		return (((num * t) % PRIME) * t) % PRIME;
	}
}