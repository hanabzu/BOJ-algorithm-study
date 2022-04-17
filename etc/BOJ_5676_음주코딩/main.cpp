/* BOJ_5676 음주 코딩 */
/* hanabzu */

#include <iostream>
#include <string.h>

using namespace std;

const int POWN = 18;

int N, K, B, idt[1 << POWN], a, b;
char cha;

void testcase();
void update(int p, int c);
int mul(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (cin >> N >> K) {
		testcase();
	}

	return 0;
}

void testcase() {
	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < N + B; i++) {
		cin >> a;
		if (a > 0) idt[i] = 1;
		else if (a < 0) idt[i] = -1;
		else idt[i] = 0;
	}

	for (int i = B - 1; i > 0; i--) {
		idt[i] = idt[i << 1] * idt[(i << 1) | 1];
	}

	while (K--) {
		cin >> cha >> a >> b;
		if (cha == 'C') {
			update(a, b);
		}
		else { // char == 'P'
			int v = mul(a, b);
			if (v > 0) cout << '+';
			else if (v < 0) cout << '-';
			else cout << '0';
		}
	}
	cout << '\n';
	memset(idt, 0, sizeof idt);
}

void update(int p, int c) {
	p += (B - 1);
	if (c > 0) idt[p] = 1;
	else if (c < 0) idt[p] = -1;
	else idt[p] = 0;
	while (p >>= 1) {
		idt[p] = idt[p << 1] * idt[(p << 1) | 1];
	}
}

int mul(int lhs, int rhs) {
	lhs += (B - 1);
	rhs += (B - 1);
	int m = 1;

	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			m = m * idt[lhs];
		}
		if ((rhs & 1) == 0) {
			m = m * idt[rhs];
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return m;
}