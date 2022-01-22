/* BOJ_2094 강수량 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#define MAXN 50000
#define POWN 17

using namespace std;

int idt[1 << POWN];
int year[MAXN + 1];
int n, y, r, m, Y, X, B;

void init();
int find_max(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (B = 1; B < n; B <<= 1);

	for (int i = 0; i < n; i++) {
		cin >> y >> r;
		year[i] = y;
		idt[i + B] = r;
	}

	init();


	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> Y >> X;
		int Yidx = lower_bound(year, year + n, Y) - year;
		int Xidx = lower_bound(year, year + n, X) - year;
		//cout << Yidx << ' ' << Xidx << '\n';
		bool existY = (Yidx < n) && (year[Yidx] == Y);
		bool existX = (Xidx < n) && (year[Xidx] == X);

		int prev_max = find_max(lower_bound(year, year + n, Y + 1) - year + 1, Xidx);
		//cout << prev_max << '\n';
		if (existY && existX && idt[Yidx + B] < idt[Xidx + B]) {
			cout << "false\n";
		}
		else if (existX && prev_max >= idt[Xidx + B]) {
			cout << "false\n";
		}
		else if (existY && prev_max >= idt[Yidx + B]) {
			cout << "false\n";
		}
		else if (existY && existX && Xidx - Yidx == X - Y) {
			cout << "true\n";
		}
		else {
			cout << "maybe\n";
		}

	}


	return 0;
}


void init() {
	for (int i = B - 1; i > 0; i--) {
		idt[i] = max(idt[i << 1], idt[(i << 1) | 1]);
	}
}

int find_max(int a, int b) {
	a += (B - 1);
	b += (B - 1);
	int m = 0;
	while (a <= b) {
		if ((a & 1) == 1) {
			m = max(m, idt[a]);
		}
		if ((b & 1) == 0) {
			m = max(m, idt[b]);
		}
		a = (a + 1) >> 1;
		b = (b - 1) >> 1;
	}
	return m;
}