/* BOJ_5557 1학년 */
/* hanabzu */

#include <iostream>
#define MAXN 100
using namespace std;

int N, K;
int n[MAXN];
long long dp[MAXN][21];

long long dfs(int p, int sum);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	N--;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	cin >> K;

	cout << dfs(0, n[0]);
	return 0;
}

long long dfs(int p, int sum) {
	if (p == N - 1) {
		if (sum == K) {
			return dp[p][sum] = 1;
		}
		return 0;
	}

	int new_p = p + 1;
	int new_sum = sum + n[new_p];
	if (new_sum >= 0 && new_sum <= 20) {
		if (dp[new_p][new_sum] > 0) {
			dp[p][sum] += dp[new_p][new_sum];
		}
		else {
			dp[p][sum] += dfs(new_p, new_sum);
		}
	}

	new_sum = sum - n[new_p];
	if (new_sum >= 0 && new_sum <= 20) {
		if (dp[new_p][new_sum] > 0) {
			dp[p][sum] += dp[new_p][new_sum];
		}
		else {
			dp[p][sum] += dfs(new_p, new_sum);
		}
	}
	
	return dp[p][sum];
}