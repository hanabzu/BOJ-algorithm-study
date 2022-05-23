/* BOJ_1965 상자넣기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N, A[MAXN + 1], dp[MAXN + 1], ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	dp[1] = A[1];

	for (int i = 1; i <= N; i++) {
		if (dp[ans] < A[i]) {
			dp[++ans] = A[i];
			continue;
		}
		dp[lower_bound(dp + 1, dp + ans + 1, A[i]) - dp] = A[i];
	}
	cout << ans;
	return 0;
}