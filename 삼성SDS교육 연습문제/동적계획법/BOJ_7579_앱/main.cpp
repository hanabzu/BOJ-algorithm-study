/* BOJ_7579 앱 */
/* hanabzu */

#include <iostream>
#include <algorithm>

#define MAXN 100
#define MAXM 10000000
using namespace std;

int N, M;
int memory[MAXN], cost[MAXN];
int D[MAXM + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}
	int MAX_COST = N * 100;
	for (int i = 0; i < N; i++) {
		for (int w = MAX_COST; w >= 1; w--) {
			if (w - cost[i] >= 0) {
				D[w] = max(D[w], D[w - cost[i]] + memory[i]);
			}
		}
	}

	for (int i = 1; i <= MAX_COST; i++) {
		if (D[i] >= M) {
			cout << i;
			break;
		}
	}

	return 0;
}