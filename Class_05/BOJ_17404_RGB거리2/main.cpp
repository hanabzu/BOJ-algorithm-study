/* BOJ_17404 RGB거리 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const int MAXCOST = 1000001;
int N;
int rgb[3][MAXN] = { 0, };
int cost[3][MAXN] = { 0, };
int ans = MAXN * MAXN + 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
	}

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			if (i == k) {
				cost[k][0] = rgb[k][0];
			}
			else {
				cost[i][0] = MAXCOST;
			}
		}

		for (int i = 1; i < N; i++) {
			cost[0][i] = rgb[0][i] + min(cost[1][i - 1], cost[2][i - 1]);
			cost[1][i] = rgb[1][i] + min(cost[2][i - 1], cost[0][i - 1]);
			cost[2][i] = rgb[2][i] + min(cost[0][i - 1], cost[1][i - 1]);
		}
		for (int i = 0; i < 3; i++) {
			if (i == k) continue;
			ans = min(ans, cost[i][N - 1]);
		}

	}

	cout << ans;
	return 0;
}