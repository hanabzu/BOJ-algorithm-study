/* BOJ_2631 줄세우기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200;
const int POWN = 9;

int N, B, a, idt[1 << POWN], lis[MAXN];

void update(int p, int v);
int idt_max(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (B = 1; B < N; B <<= 1);

	for (int i = 0; i < N; i++) {
		cin >> a;
		lis[i] = idt_max(1, a - 1) + 1;
		update(a, lis[i]);
	}

	cout << (N - *max_element(lis, lis + N));
	return 0;
}

void update(int p, int v) {
	p += (B - 1);
	idt[p] = v;
	while (p >>= 1) {
		idt[p] = max(idt[p << 1],idt[(p << 1) | 1]);
	}
}
int idt_max(int lhs, int rhs) {
	lhs += (B - 1);
	rhs += (B - 1);
	int s = 0;
	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			s = max(s, idt[lhs]);
		}
		if ((rhs & 1) == 0) {
			s = max(s, idt[rhs]);
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return s;
}