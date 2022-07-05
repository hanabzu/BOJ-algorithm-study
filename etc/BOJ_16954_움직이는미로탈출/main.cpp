/* BOJ_16954 움직이는 미로 탈출 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
const int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };

int q_size;
queue<pii> q, wall;
bool map[8][8], visit[8][8], tmap[8][8];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '#') {
				map[i][j] = true;
				wall.push(make_pair(i, j));
			}
		}
	}

	q.push(make_pair(7, 0));
	q_size = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (!map[x][y]) {
			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx == 0 && ny == 7) {
					cout << 1;
					return 0;
				}

				if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || map[nx][ny] || visit[nx][ny]) continue;

				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
		}

		if (--q_size == 0) {
			q_size = q.size();
			memset(visit, false, sizeof(visit));
			memset(tmap, false, sizeof(tmap));
			int wall_size = wall.size();
			for (int i = 0; i < wall_size; i++) {
				int wx = wall.front().first;
				int wy = wall.front().second;
				wall.pop();

				if (++wx >= 8) continue;
				tmap[wx][wy] = true;
				wall.push(make_pair(wx, wy));
			}
			memcpy(map, tmap, sizeof(tmap));
		}

	}

	cout << 0;
	return 0;
}