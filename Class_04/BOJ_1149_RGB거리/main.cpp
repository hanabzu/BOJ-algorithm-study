/* hanabzu */
/* BOJ_1149 RGB거리 */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int rgb[3][1000] = { 0, };
int cost[3][1000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
	}

	cost[0][0] = rgb[0][0];
	cost[1][0] = rgb[1][0];
	cost[2][0] = rgb[2][0];

	for (int i = 1; i < N; i++) {
		cost[0][i] = rgb[0][i] + min(cost[1][i - 1], cost[2][i - 1]);
		cost[1][i] = rgb[1][i] + min(cost[2][i - 1], cost[0][i - 1]);
		cost[2][i] = rgb[2][i] + min(cost[0][i - 1], cost[1][i - 1]);
	}

	cout << min(min(cost[0][N - 1], cost[1][N - 1]), cost[2][N - 1]);
	return 0;
}