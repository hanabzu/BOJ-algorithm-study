/* BOJ_7578 공장 */
/* hanabzu */

#include <iostream>

#define MAX_IDX 1000000
#define MAXN 500000
#define POWN 20

using namespace std;

int N, B, n;
long long total = 0;
int M[MAX_IDX + 1];
int idt[1 << POWN];
void update(int p);
long long idtSum(int b, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (B = 1; B < N; B <<= 1);

	for (int i = 1; i <= N; i++) {
		cin >> n;
		M[n] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> n;
		int idx = M[n];
		total += idtSum(idx, N);
		update(idx);
	}

	cout << total;

	return 0;
}


void update(int p) {
	p += (B - 1);
	idt[p] = 1;
	while (p >>= 1) {
		idt[p] += 1;
	}

}

long long idtSum(int b, int c) {
	b += (B - 1);
	c += (B - 1);
	long long s = 0;
	while (b <= c) {
		if ((b & 1) == 1) {
			s += idt[b];
		}
		if ((c & 1) == 0) {
			s += idt[c];
		}
		b = (b + 1) >> 1;
		c = (c - 1) >> 1;
	}
	return s;
}