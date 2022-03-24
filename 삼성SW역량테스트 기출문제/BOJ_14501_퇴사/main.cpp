/* BOJ_14501 퇴사 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 15;
int N, ans = 0;
pair<int, int> n[MAXN];

void dfs(int p, int w);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i].first >> n[i].second;
	}
	dfs(0, 0);

	cout << ans;

	return 0;
}

void dfs(int p, int w) {
	if (p >= N) {
		ans = max(ans, w);
		return;
	}

	for (int i = p; i < N; i++) {
		int ni = i + n[i].first;
		if (ni > N) { // can't do
			dfs(ni, w);
		}
		else {
			dfs(ni, w + n[i].second);
		}
	}
}