/* BOJ_2468 안전 영역 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, maxh = 0, ans = 0, cnt = 0;
int map[MAXN][MAXN];
bool visit[MAXN][MAXN];

void bfs(pii s, int h);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			maxh = max(maxh, map[i][j]);
		}
	}


	for (int h = 0; h <= maxh + 1; h++) {
		memset(visit, false, sizeof visit);
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && map[i][j] > h) {
					bfs(make_pair(i,j), h);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}

void bfs(pii s, int h) {
	queue<pii> q;
	q.push(s);
	visit[s.first][s.second] = true;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = u.first + dx[i];
			int nc = u.second + dy[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc] || map[nr][nc] <= h) continue;

			visit[nr][nc] = true;
			q.push(make_pair(nr, nc));
		}
	}
}