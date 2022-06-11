/* BOJ_11052 카드 구매하기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N, P[MAXN + 1], dp[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = P[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + P[i - j]);
		}
	}

	cout << dp[N];

	return 0;
}