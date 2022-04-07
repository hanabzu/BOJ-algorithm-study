/* BOJ_17142 연구소 3 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
enum {
	BLANK, WALL, VIRUS
};
const int MAXN = 50;
const int MAXM = 10;
const int INF = 987654321;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, M, ans = INF, num_blank = 0, m = 0;
int map[MAXN][MAXN];
pii candi[MAXM];
bool selected[MAXM];
bool visit[MAXN][MAXN];
queue<pii> q;

void dfs(int p, int depth);
void bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == VIRUS) {
				candi[m++] = make_pair(i, j);
			}
			else if (map[i][j] == BLANK) {
				num_blank++;
			}
		}
	}

	if (num_blank == 0) {
		cout << 0;
	}
	else {
		dfs(0, 0);
		cout << ((ans == INF) ? -1 : ans);
	}
	return 0;
}

void dfs(int p, int depth) {
	if (depth == M) {

		memset(visit, 0, sizeof visit);
		for (int i = 0; i < m; i++) {
			if (selected[i]) {
				q.push(candi[i]);
				visit[candi[i].first][candi[i].second] = true;
			}
		}
		bfs();
		return;
	}

	for (int i = p; i < m; i++) {
		selected[i] = true;
		dfs(i + 1, depth + 1);
		selected[i] = false;
	}
}

void bfs() {
	int t = 0, num = 0;
	int q_size = q.size();
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		q_size--;
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny]) continue;

			visit[nx][ny] = true;
			if (map[nx][ny] == WALL) continue;

			q.push(make_pair(nx, ny));
			if (map[nx][ny] == BLANK) {
				num++;
			}
		}

		if (q_size == 0) {
			q_size = q.size();
			t++;
			if (num == num_blank) {
				ans = min(ans, t);
				q = queue<pii>();
				return;
			}
		}
	}

}