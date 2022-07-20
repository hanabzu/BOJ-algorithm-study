/* BOJ_2665 미로만들기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int INF = 987654321;
const int MAXN = 50;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, cost[MAXN][MAXN];
string map[MAXN];
queue<pii> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];

	fill(&cost[0][0], &cost[MAXN - 1][MAXN], INF);
	cost[0][0] = 0;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			int ncost = (map[x][y] == '0' ? 1 : 0);
			if (cost[nx][ny] > cost[x][y] + ncost) {
				cost[nx][ny] = cost[x][y] + ncost;
				q.push(make_pair(nx, ny));
			}
		}

	}

	cout << cost[N - 1][N - 1];

	return 0;
}
