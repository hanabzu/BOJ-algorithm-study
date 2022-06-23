/* BOJ_1315 RPG */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 50;
const int MAXV = 1000;

int N, dp[MAXV + 1][MAXV + 1], ans = 0;
int STR[MAXN], INT[MAXN], PNT[MAXN];
bool solved[MAXN];

void dfs(int s, int i, int prev);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> STR[i] >> INT[i] >> PNT[i];
	}
	
	memset(dp, -1, sizeof dp);

	dfs(1, 1, 0);

	cout << ans;
	return 0;
}

void dfs(int s, int i, int prev) {
	vector<int> sol;

	if (dp[s][i] >= 0) return;

	int& ret = dp[s][i] = prev;
	int pnt = 0;
	for (int j = 0; j < N; j++) {
		if (solved[j]) continue;

		if (STR[j] <= s || INT[j] <= i) {
			ret++;
			pnt += PNT[j];
			solved[j] = true;
			sol.push_back(j);
		}
	}

	for (int j = 0; j <= pnt; j++) {
		dfs(min(MAXV, s + j), min(MAXV, i + pnt - j), ret);
	}

	for (int j = 0; j < sol.size(); j++) {
		solved[sol[j]] = false;
	}

	ans = max(ans, ret);
}