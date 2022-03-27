/* BOJ_14888 연산자 끼워넣기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 11;
const int INF = 1987654321;
int N, A[MAXN], OP[4], ans_max = -INF, ans_min = INF;

void dfs(int p, int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> OP[i];
	}

	dfs(1, A[0]);

	cout << ans_max << '\n' << ans_min;

	return 0;
}

void dfs(int p, int n) {
	if (p == N) {
		ans_max = max(ans_max, n);
		ans_min = min(ans_min, n);
		return;
	}

	for (int j = 0; j < 4; j++) {
		if (OP[j] == 0) continue;

		OP[j]--;
		if (j == 0) {
			dfs(p + 1, n + A[p]);
		}
		else if (j == 1) {
			dfs(p + 1, n - A[p]);
		}
		else if (j == 2) {
			dfs(p + 1, n * A[p]);
		}
		else {
			dfs(p + 1, n / A[p]);
		}
		OP[j]++;
	}
}