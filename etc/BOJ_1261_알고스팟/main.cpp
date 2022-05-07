/* BOJ_1261 알고스팟 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
const int INF = 987654321;

int N, M;
string map[MAXN];
int d[MAXN][MAXN];
void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	dijkstra();

	cout << d[N - 1][M - 1];

	return 0;
}

void dijkstra() {
	fill(&d[0][0], &d[N - 1][M], INF);

	d[0][0] = 0;
	queue<pii> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (d[nr][nc] > d[r][c] + (map[nr][nc] - '0')) {
				d[nr][nc] = d[r][c] + (map[nr][nc] - '0');
				q.push(make_pair(nr, nc));
			}
		}
	}
}