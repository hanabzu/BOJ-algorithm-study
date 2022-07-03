/* BOJ_25330 SHOW ME THE DUNGEON */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 20;

int N, K, A[MAXN + 1], P[MAXN + 1], ans = 0;
bool visit[MAXN + 1];

void dfs(int a, int people);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> P[i];

	dfs(0, 0);

	cout << ans;
	return 0;
}


void dfs(int a, int people) {
	ans = max(ans, people);

	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		visit[i] = true;
		int na = a + A[i];
		if (K >= na) {
			K -= na;
			dfs(na, people + P[i]);
			K += na;
		}
		visit[i] = false;
	}
}