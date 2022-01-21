/* BOJ_2243 사탕상자 */
/* hanabzu */

#include <iostream>
#define MAXN 1000000
#define POWN 21

using namespace std;

int idt[1 << POWN];
int n, a, b, c, B, l, r;

int pick(int b);
void update(int b, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (B = 1; B < MAXN; B <<= 1);

	cin >> n;

	while (n--) {
		cin >> a >> b;
		if (a == 1) {
			cout << pick(b) << '\n';
		}
		else {
			cin >> c;
			update(b, c);
		}
	}

	return 0;
}

int pick(int b) {
	int p = 1;
	while (p < B){
		p <<= 1;
		if (b > idt[p]) {
			b -= idt[p];
			p++;
		}
	 }
	update(p - B + 1, -1);
	return p - B + 1;
}

void update(int b, int c) {
	b += (B - 1);
	do {
		idt[b] += c;
	} while (b >>= 1);
}