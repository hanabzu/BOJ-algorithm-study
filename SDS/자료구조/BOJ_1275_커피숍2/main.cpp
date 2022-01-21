/* BOJ_1275 커피숍2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#define MAXN 100000
#define POWN 18

using namespace std;

long long idt[1 << 18];
int N, Q, B;

void init();
void update(int a, int b);
long long sumIdt(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	for (B = 1; B < N; B <<= 1);
	
	for (int i = B; i < B + N; i++) {
		cin >> idt[i];
	}
	
	init();

	for (int i = 0, x, y, a, b; i < Q; i++) {
		cin >> x >> y >> a >> b;
		cout << sumIdt(x, y) << '\n';
		update(a, b);
	}


	return 0;
}

void init() {
	for (int i = B - 1; i > 0; i--) {
		idt[i] = idt[i << 1] + idt[(i << 1) | 1];
	}
}

void update(int a, int b) {
	a += B - 1;
	idt[a] = b;
	while (a >>= 1) {
		idt[a] = idt[a << 1] + idt[(a << 1) | 1];
	}
}

long long sumIdt(int x, int y) {
	if (x > y) {
		swap(x, y);
	}

	x += B - 1;
	y += B - 1;

	long long s = 0;
	while (x <= y) {
		if ((x & 1) == 1) {
			s += idt[x];
		}
		if ((y & 1) == 0) {
			s += idt[y];
		}
		x = (x + 1) >> 1;
		y = (y - 1) >> 1;
	}
	return s;
}