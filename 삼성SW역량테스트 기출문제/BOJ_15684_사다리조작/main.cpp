/* BOJ_15684 사다리 조작 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 10;
const int MAXH = 30;
int N, M, H, a, b, ans = 4;

bool lad[MAXH + 1][MAXN + 1];

void dfs(int n, int r, int c);
void game(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		lad[a][b] = true;
	}
	game(0);
	if (ans == 0) {
		cout << 0;
		return 0;
	}
	dfs(1, 1, 1);

	if (ans < 4) {
		cout << ans;
	}
	else {
		cout << -1;
	}
	return 0;
}

void dfs(int n, int r, int c) {
	if (n > 3) return;

	for (int i = r; i <= H; i++) {
		int j = (i == r) ? c : 1;
		for (j; j < N; j++) {
			if (lad[i][j] || lad[i][j - 1] || lad[i][j + 1]) continue;
			
			lad[i][j] = true;

			game(n);

			if (ans <= n) {
				lad[i][j] = false;
				return;
			}

			if (j == N - 1) {
				dfs(n + 1, i + 1, 1);
			}
			else {
				dfs(n + 1, i, j + 1);
			}
			lad[i][j] = false;
		}
	}
}

void game(int n) {
	int num[MAXN];
	for (int i = 1; i <= N; i++) {
		num[i] = i;
	}

	for (int h = 1; h <= H; h++) {
		for (int i = 1; i < N; i++) {
			if (lad[h][i] == true) {
				swap(num[i], num[i + 1]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (num[i] != i) {
			return;
		}
	}

	ans = min(ans, n);
}