/* BOJ_17135 캐슬 디펜스 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 15;
const int dx[3] = { 0,-1,0 };
const int dy[3] = { -1,0,1 };

int N, M, D, ans = 0;
int map[MAXN][MAXN], tmap[MAXN][MAXN];
bool visit[MAXN][MAXN];
int archer[3];
queue<pii> q;
void game();
void bfs(pii pos);
void dfs(int p, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0);
	cout << ans;

	return 0;
}

void game() {
	int tans = 0;
	memcpy(tmap, map, sizeof map);

	for (int xPos = N; xPos > 0; xPos--) {
		for (int i = 0; i < 3; i++) {
			bfs(make_pair(xPos, archer[i]));
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmap[i][j] == 2) {
					tans++;
					tmap[i][j] = 0;
				}
			}
		}
	}

	ans = max(ans, tans);

}

void bfs(pii pos) {
	memset(visit, false, sizeof visit);
	q = queue<pii>();
	q.push(make_pair(pos.first - 1, pos.second));
	visit[pos.first - 1][pos.second] = true;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		if (tmap[u.first][u.second] > 0) {
			tmap[u.first][u.second] = 2;
			return;
		}

		if ((abs(u.first - pos.first) + abs(u.second - pos.second)) == D) continue;
		for (int i = 0; i < 3; i++) {
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];

			if (nx < 0 || ny < 0 || ny >= M || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}

}

void dfs(int p, int cnt) {
	if (cnt == 3) {
		game();
		return;
	}
	if (p >= M) return;

	dfs(p + 1, cnt);
	
	archer[cnt] = p;
	dfs(p + 1, cnt + 1);
}