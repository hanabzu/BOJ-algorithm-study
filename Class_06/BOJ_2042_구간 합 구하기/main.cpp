/* BOJ_2042 구간 합 구하기 */
/* hanabzu */

#include <iostream>
#define POWN 21
using namespace std;

long long idt[1 << POWN];
int N, M, K, B, T;

void init();
void update(int b, long long c);
void printSum(int b, int c);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < N + B; i++) { // get numbers
		cin >> idt[i];
	}

	init();
	int a, b;
	long long c;
	T = M + K;
	while (T--) {
		cin >> a>> b>> c;

		if (a == 1) {
			update(b, c);
		}
		else {
			printSum(b, c);
		}
	}

	return 0;
}

void init() {
	for (int i = B - 1; i > 0; i--) {
		idt[i] = idt[i << 1] + idt[(i << 1) | 1];
	}
}

void update(int b, long long c) {
	b += (B - 1);
	long long offset = c - idt[b];
	idt[b] = c;
	while (b >>= 1) {
		idt[b] += offset;
	}

}

void printSum(int b, int c) {
	b += (B - 1);
	c += (B - 1);
	long long s = 0;
	while (b <= c) {
		if ((b & 1) == 1) { // b is odd
			s += idt[b];
		}
		if ((c & 1) == 0) { // c is even
			s += idt[c];
		}
		b = (b + 1) >> 1;
		c = (c - 1) >> 1;
	}
	cout << s << '\n';
}