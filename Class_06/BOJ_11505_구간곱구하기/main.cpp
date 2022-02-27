/* BOJ_11505 구간 곱 구하기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
const int POWN = 21;
const long long MOD = 1000000007;

int N, M, K, B, a, b, c;
long long idt[1 << POWN];

void update(int p, long long c);
long long mul(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++) {
		cin >> idt[i];
	}

	for (int i = B - 1; i > 0; i--) {
		idt[i] = (idt[i << 1] * idt[(i << 1) | 1]) % MOD;
	}

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << mul(b, c) << '\n';
		}
	}


	return 0;
}

void update(int p, long long c) {
	p += (B - 1);
	idt[p] = c;
	while (p >>= 1) {
		idt[p] = (idt[p << 1] * idt[(p << 1) | 1]) % MOD;
	}
}


long long mul(int lhs, int rhs) {
	lhs += (B - 1);
	rhs += (B - 1);
	long long m = 1;

	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			m = (m * idt[lhs]) % MOD;
		}
		if ((rhs & 1) == 0) {
			m = (m * idt[rhs]) % MOD;
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return m;
}