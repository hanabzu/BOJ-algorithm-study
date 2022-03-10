/* BOJ_2618 경찰차 */
/* hanabzu */

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1000;

int N, W, a, b;
pii w[MAXN + 1];
int dp[MAXN][MAXN];

int dfs(int c1, int c2);
int cost(pii t, pii c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> W;

	for (int i = 1; i <= W; i++) {
		cin >> a >> b;
		w[i] = make_pair(a, b);
	}

	cout << dfs(0, 0) << '\n';

	int c1 = 0, c2 = 0;
	pii car1 = make_pair(1, 1);
	pii car2 = make_pair(N, N);
	for (int i = 1; i <= W; i++) {
		if (dp[c1][c2] == cost(w[i], car1) + dp[i][c2]) {
			c1 = i;
			car1 = w[i];
			cout << 1 << '\n';
		}
		else {
			c2 = i;
			car2 = w[i];
			cout << 2 << '\n';
		}
	}

	return 0;
}


int dfs(int c1, int c2) {
	if (c1 == W || c2 == W) {
		return 0;
	}
	if (dp[c1][c2] > 0) {
		return dp[c1][c2];
	}

	int next = max(c1, c2) + 1;
	pii pos1 = (c1 == 0) ? make_pair(1, 1) : w[c1];
	pii pos2 = (c2 == 0) ? make_pair(N, N) : w[c2];

	return dp[c1][c2] = min(cost(w[next], pos1) + dfs(next, c2), cost(w[next], pos2) + dfs(c1, next));
}

int cost(pii t, pii c) {
	return abs(t.first - c.first) + abs(t.second - c.second);
}