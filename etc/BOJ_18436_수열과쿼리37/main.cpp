/* BOJ_18436 수열과 쿼리 37 */
/* hanabzu */

#include <iostream>

using namespace std;

const int POWN = 18;

int N, M, B, a, b, c, idt[1 << POWN];

void update(int i, int x);
int countOdd(int l, int r);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++) {
		cin >> a;
		idt[i] = ((a & 1) == 1) ? 1 : 0;
	}

	for (int i = B - 1; i > 0; i--) {
		idt[i] = idt[i << 1] + idt[(i << 1) | 1];
	}

	cin >> M;
	while (M--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else if (a == 2) {
			cout << (c - b + 1) - countOdd(b, c) << '\n';
		}
		else { // a == 3
			cout << countOdd(b, c) << '\n';
		}

	}
	return 0;
}


void update(int i, int x) {
	i += (B - 1);
	idt[i] = ((x & 1) == 1) ? 1 : 0;
	while (i >>= 1) {
		idt[i] = idt[i << 1] + idt[(i << 1) | 1];
	}
}


int countOdd(int l, int r) {
	l += (B - 1);
	r += (B - 1);
	int cnt = 0;
	while (l <= r) {
		if ((l & 1) == 1) {
			cnt += idt[l];
		}
		if ((r & 1) == 0) {
			cnt += idt[r];
		}
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return cnt;
}