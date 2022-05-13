/* BOJ_2157 여행 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 300;
const int INF = 987654321;
int N, M, K, A[MAXN + 1][MAXN + 1], dp[MAXN + 1][MAXN + 1];
int a, b, c;

int get_route(int city, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	fill(&dp[0][0], &dp[MAXN][MAXN + 1], -1);

	while (K--) {
		cin >> a >> b >> c;
		if (a > b || A[a][b] > c) continue;
		A[a][b] = c;
	}

	cout << get_route(N, 1);

	return 0;
}

int get_route(int city, int cnt) {
	if (cnt == M && city != 1) return -INF;
	if (city == 1) return 0;
	if (dp[city][cnt] >= 0) return dp[city][cnt];

	int& score = dp[city][cnt] = -INF;

	for (int i = 1; i < city; i++) {
		if (A[i][city] > 0) {
			score = max(score, get_route(i, cnt + 1) + A[i][city]);
		}
	}

	return score;
}