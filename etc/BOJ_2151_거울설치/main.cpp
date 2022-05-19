/* BOJ_2151 거울 설치 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

enum {
	BLANK, WALL, DOOR, MIRROR
};

struct Point {
	int r, c, d, cnt;
	Point() {}
	Point(int r, int c, int d, int cnt) : r(r), c(c), d(d), cnt(cnt) {}
	bool operator<(const Point& rhs) const {
		return cnt > rhs.cnt;
	}
};

const int MAXN = 50;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, ans = 500, map[MAXN][MAXN];
bool visit[4][MAXN][MAXN];
string s;
priority_queue<Point> q;
Point p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			switch (s[j]) {
			case '*': 
				map[i][j] = WALL; break;
			case '#': 
				map[i][j] = DOOR; 
				p = Point(i, j, -1, 0);
				break;
			case '!':
				map[i][j] = MIRROR;
			}
		}
	}

	q.push(p);
	for(int i=0;i<4;i++) visit[i][p.r][p.c] = true;
	while (!q.empty()) {
		Point u = q.top();
		q.pop();

		if (u.d == -1) {
			for (int i = 0; i < 4; i++) {
				int nr = u.r + dx[i];
				int nc = u.c + dy[i];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[i][nr][nc] || map[nr][nc] == WALL) continue;

				if (map[nr][nc] == DOOR) {
					cout << 0;
					return 0;
				}

				q.push(Point(nr, nc, i, 0));
				if (map[nr][nc] == MIRROR) {
					q.push(Point(nr, nc, (i + 1) % 4, 1));
					q.push(Point(nr, nc, (i + 3) % 4, 1));
				}
			}
			continue;
		}

		int nr = u.r + dx[u.d];
		int nc = u.c + dy[u.d];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[u.d][nr][nc] || map[nr][nc] == WALL) continue;

		if (map[nr][nc] == DOOR) {
			ans = min(ans, u.cnt);
			continue;
		}

		visit[u.d][nr][nc] = true;
		q.push(Point(nr, nc, u.d, u.cnt));
		if (map[nr][nc] == MIRROR) {
			visit[(u.d + 1) % 4][nr][nc] = true;
			visit[(u.d + 3) % 4][nr][nc] = true;
			q.push(Point(nr, nc, (u.d + 1) % 4, u.cnt + 1));
			q.push(Point(nr, nc, (u.d + 3) % 4, u.cnt + 1));
		}
	}


	cout << ans;
	return 0;
}