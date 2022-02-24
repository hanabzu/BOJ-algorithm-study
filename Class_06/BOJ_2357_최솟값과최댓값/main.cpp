/* BOJ_2357 최솟값과 최댓값 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1987654321;
const int MAXN = 100000;
const int POWN = 18;

int minIDT[1 << POWN];
int maxIDT[1 << POWN];

int N, M, B, a, b;

void query(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++) {
		cin >> minIDT[i];
		maxIDT[i] = minIDT[i];
	}

	for (int i = B - 1; i > 0; i--) {
		minIDT[i] = min(minIDT[i << 1], minIDT[(i << 1) | 1]);
		maxIDT[i] = max(maxIDT[i << 1], maxIDT[(i << 1) | 1]);
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		query(a, b);
	}


	return 0;
}

void query(int a, int b) {
	a += (B - 1);
	b += (B - 1);
	int min_v = INF, max_v = 0;
	while (a <= b) {
		if ((a & 1) == 1) {
			min_v = min(min_v, minIDT[a]);
			max_v = max(max_v, maxIDT[a]);
		}
		if ((b & 1) == 0) {
			min_v = min(min_v, minIDT[b]);
			max_v = max(max_v, maxIDT[b]);
		}

		a = (a + 1) >> 1;
		b = (b - 1) >> 1;
	}
	cout << min_v << ' ' << max_v << '\n';

}