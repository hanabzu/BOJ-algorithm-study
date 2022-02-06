/* BOJ_16566 카드 게임 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int POWN = 23;

int idt[1 << POWN];

int N, M, K, B, card;

void find(int c);
void update(int p, int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (B = 1; B < M; B <<= 1);

	for (int i = B; i < B + M; i++) {
		cin >> idt[i];
	}
	sort(idt + B, idt + B + M);
	for (int i = B - 1; i > 0; i--) { // initialize max_idt
		idt[i] = max(idt[i << 1], idt[(i << 1) | 1]);
	}

	for (int i = 0; i < K; i++) {
		cin >> card;
		find(card);
	}
}

void find(int c) {
	int p = 1, lhs, rhs;
	do {
		lhs = p << 1;
		rhs = lhs | 1;
		if (idt[lhs] > c && idt[rhs] > c) {
			p = idt[lhs] < idt[rhs] ? lhs : rhs;
		}
		else if (idt[lhs] > c) {
			p = lhs;
		}
		else {
			p = rhs;
		}

	} while (p < B);

	cout << idt[p] << '\n';
	update(p, 0);
}

void update(int p, int v) {
	idt[p] = 0;
	while (p >>= 1) {
		idt[p] = max(idt[p << 1], idt[(p << 1) | 1]);
	}
}