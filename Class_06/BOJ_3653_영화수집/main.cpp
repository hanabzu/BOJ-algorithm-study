/* BOJ_3653 영화 수집 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int POWN = 19;
const int MAXN = 100000;

int idt[1 << POWN];
int pos[MAXN + 1];
int T, n, m, B, a;

void solution();
void update(int p, int c);
int watch(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		solution();
		cout << '\n';
	}

	return 0;
}

void solution() {
	memset(idt, 0, sizeof(idt));
	memset(pos, 0, sizeof(pos));

	cin >> n >> m;

	for (B = 1; B < n + m; B <<= 1);

	// movie position
	for (int i = n; i > 0; i--) {
		pos[i] = n + 1 - i;
	}

	// init
	for (int i = B; i < B + n; i++) {
		idt[i] = 1;
	}
	for (int i = B - 1; i > 0; i--) {
		idt[i] = idt[i << 1] + idt[(i << 1) | 1];
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		cout << watch(pos[a] + 1, B) << ' '; // count the movies on top
		update(pos[a], -1); // pull out 
		pos[a] = n + i + 1; // get new pos
		update(pos[a], 1);  // put on top
	}
}

void update(int p, int c) {
	p += (B - 1);
	do {
		idt[p] += c;
	} while (p >>= 1);
}

int watch(int lhs, int rhs) {
	lhs += (B - 1);
	rhs += (B - 1);
	int sum = 0;
	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			sum += idt[lhs];
		}
		if ((rhs & 1) == 0) {
			sum += idt[rhs];
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return sum;
}