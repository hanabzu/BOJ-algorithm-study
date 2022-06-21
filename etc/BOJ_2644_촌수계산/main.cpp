/* BOJ_2644 촌수계산 */
/* hanabzu */

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int N, M, a, b, x, y;
vector<int> e[MAXN + 1];
bool visit[MAXN + 1];

void dfs(int x, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> a >> b >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	visit[a] = true;
	dfs(a, 0);

	cout << -1;
	return 0;
}

void dfs(int x, int depth) {
	if (x == b) {
		cout << depth;
		exit(0);
	}

	for (int i = 0; i < e[x].size(); i++) {
		if (visit[e[x][i]]) continue;

		visit[e[x][i]] = true;
		dfs(e[x][i], depth + 1);
	}
}