/* BOJ_5427 불 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <utility>

using namespace std;

enum {
	BLANK, WALL, FIRE, START
};
typedef pair<int, int> pii;

const int MAXW = 1000;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int T, R, C, map[MAXW][MAXW], ans;
bool visit[MAXW][MAXW];
string s;
queue<pii> q, fq;

void testcase();
void burn();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) testcase();

	return 0;
}

void testcase() {
	memset(map, 0, sizeof map);
	memset(visit, false, sizeof visit);
	q = queue<pii>();
	fq = queue<pii>();

	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '#') map[i][j] = WALL;
			else if (s[j] == '*') {
				map[i][j] = FIRE;
				fq.push(make_pair(i, j));
			}
			else if (s[j] == '@') {
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}

	ans = 1;
	int q_size = 1;
	burn();
	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = u.first + dx[i];
			int nc = u.second + dy[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				cout << ans << '\n';
				return;
			}

			if (visit[nr][nc] || map[nr][nc] == WALL || map[nr][nc] == FIRE) continue;

			q.push(make_pair(nr, nc));
			visit[nr][nc] = true;
		}
		
		if (--q_size == 0) {
			burn();
			q_size = q.size();
			ans++;
		}

	}
	cout << "IMPOSSIBLE\n";
}

void burn() {
	int fq_size = fq.size();

	while (fq_size--) {
		pii u = fq.front();
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int nr = u.first + dx[i];
			int nc = u.second + dy[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == WALL || map[nr][nc] == FIRE) continue;

			map[nr][nc] = FIRE;
			fq.push(make_pair(nr, nc));
		}
	}
}