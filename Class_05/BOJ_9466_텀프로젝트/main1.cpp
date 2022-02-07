/* BOJ_9466 텀 프로젝트 */
/* hanabzu */

#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100000;

int T, n, ans;
int pick[MAXN + 1];
int indegree[MAXN + 1];
void solution();

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

	fill(indegree, indegree + n + 1, 0);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> pick[i];
		indegree[pick[i]]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans++;
		int v = pick[u];
		if (--indegree[v] == 0) {
			q.push(v);
		}
	}
	cout << ans << '\n';
}
