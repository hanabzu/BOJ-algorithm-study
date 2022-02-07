/* BOJ_9466 텀 프로젝트 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 100000;

enum {
	UNVISITED, VISITED, SUCCESS, FAIL
};
int T, n, ans;
int pick[MAXN + 1];
int visit[MAXN + 1];
void solution();
void dfs(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		solution();
	}


	return 0;
}

void solution() {
	cin >> n;

	fill(visit, visit + n + 1, 0);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> pick[i];
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == UNVISITED) {
			dfs(i);
		}
	}
	cout << ans << '\n';
}

void dfs(int p) {
	if (visit[pick[p]] == SUCCESS || visit[pick[p]] == FAIL) {
		visit[p] = FAIL;
		ans++;
		return;
	}

	visit[p] = VISITED;

	if (visit[pick[p]] == VISITED) {
		visit[pick[p]] = SUCCESS; // team
		return;
	}

	dfs(pick[p]);

	if (visit[pick[p]] == VISITED) {
		visit[pick[p]] = SUCCESS;
	}
	else if (visit[pick[p]] == SUCCESS || visit[pick[p]] == FAIL) {
		visit[p] = FAIL;
		ans++;
	}
	else {
		visit[p] = UNVISITED;
	}
}