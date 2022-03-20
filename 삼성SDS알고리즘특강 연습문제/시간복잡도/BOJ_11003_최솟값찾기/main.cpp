/* BOJ_11003 최솟값 찾기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include "limits.h"
#define MAXN 5000000
#define POWN 24

using namespace std;

int idt[1 << POWN];
int N, L, B;

void update(int i);
int find_min(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	
	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++) {
		cin >> idt[i];
		update(i);
	}
	for (int i = 1; i <= N; i++) {
		cout << find_min(max(1, i - L + 1), i) << ' ';
	}

	return 0;
}

void update(int i) {
	while (i>>=1) {
		idt[i] = min(idt[i << 1], idt[(i << 1)|1]);
	}
}

int find_min(int a, int b) {
	int m = INT_MAX;
	a += (B - 1);
	b += (B - 1);
	while (a <= b) {
		if ((a & 1) == 1) {
			m = min(m, idt[a]);
		}
		if ((b & 1) == 0) {
			m = min(m, idt[b]);
		}
		a = (a + 1) >> 1;
		b = (b - 1) >> 1;
	}
	return m;
}

