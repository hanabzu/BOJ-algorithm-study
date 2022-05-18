/* BOJ_1949 우수 마을 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 10000;
int N, A[MAXN + 1], dp[2][MAXN+1], a, b;
vector<int> e[MAXN + 1];

int get_good(int n, int parent);
int get_bad(int n, int parent);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	fill(&dp[0][0], &dp[1][MAXN + 1], -1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	cout << max(get_good(1, 0), get_bad(1, 0));
	return 0;
}

int get_good(int n, int parent) {
	if (dp[0][n] >= 0) return dp[0][n];

	dp[0][n] = A[n];
	for (int i = 0; i < e[n].size(); i++) {
		if (e[n][i] == parent) continue;

		dp[0][n] += get_bad(e[n][i], n);
	}
	return dp[0][n];
}


int get_bad(int n, int parent) {
	if (dp[1][n] >= 0) return dp[1][n];
	dp[1][n] = 0;

	for (int i = 0; i < e[n].size(); i++) {
		if (e[n][i] == parent) continue;

		dp[1][n] += max(get_bad(e[n][i], n), get_good(e[n][i], n));
	}
	return dp[1][n];

}