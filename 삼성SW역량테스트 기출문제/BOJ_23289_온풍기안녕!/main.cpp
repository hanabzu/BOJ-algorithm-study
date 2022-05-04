/* BOJ_23289 온풍기 안녕! */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

enum {
	UP, RIGHT, DOWN, LEFT
};

const int MAXR = 20;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

class Machine {
public:
	int r, c, d;
	Machine() {}
	Machine(int r, int c, int d) :r(r), c(c), d(d) {}

	void heat();
};

int R, C, K, W, page = 0, ans = 0, x, y, t;
int map[2][MAXR][MAXR], wall[MAXR][MAXR];
bool visit[MAXR][MAXR];
queue<pii> q;
vector<Machine> M; // machines
vector<pii> CP; // check point

void regulate();
void cooling();
bool isHot();
bool isWall(int r, int c, int d);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> x;
			if (x == 0) continue;

			if (x == 5) { // check point
				CP.push_back(make_pair(i, j));
				continue;
			}

			// UP, RIGHT, DOWN, LEFT
			if (x == 1) x = RIGHT;
			else if (x == 2) x = LEFT;
			else if (x == 3) x = UP;
			else x = DOWN;
			
			M.push_back(Machine(i, j, x));
		}
	}

	cin >> W;
	for (int i = 0; i < W; i++) {
		cin >> x >> y >> t;
		wall[x - 1][y - 1] += (t + 1); // UP : 01, RIGHT : 10, BOTH : 11
	}

	do {
		for (int i = 0; i < M.size(); i++) {
			M[i].heat();// heating
		}
		regulate(); // regulation
		cooling(); // cooling
		ans++; // eat chocolate
	} while (ans <= 100 && !isHot());

	cout << ans;

	return 0;

}

void Machine::heat() {
	memset(visit, 0, sizeof(visit));
	int score = 5;
	int cnt = 1;
	int row, col, nr, nc;
	map[page][r + dx[d]][c + dy[d]] += score;
	q.push(make_pair(r + dx[d], c + dy[d]));
	score--;
	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();
		cnt--;

		// next block
		nr = row + dx[d];
		nc = col + dy[d];
		if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visit[nr][nc]) {
			if (!isWall(row, col, d)) {
				map[page][nr][nc] += score;
				if (score > 1) q.push(make_pair(nr, nc));
				visit[nr][nc] = true;
			}
		}

		// next right block
		nr += dx[(d + 1) % 4];
		nc += dy[(d + 1) % 4];
		if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visit[nr][nc]) {
			if (!isWall(row, col, (d + 1) % 4) && !isWall(row + dx[(d + 1) % 4], col + dy[(d + 1) % 4], d)) {
				map[page][nr][nc] += score;
				if (score > 1) q.push(make_pair(nr, nc));
				visit[nr][nc] = true;
			}
		}

		// next left block
		nr += (dx[(d + 3) % 4] << 1);
		nc += (dy[(d + 3) % 4] << 1);
		if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visit[nr][nc]) {
			if (!isWall(row, col, (d + 3) % 4) && !isWall(row + dx[(d + 3) % 4], col + dy[(d + 3) % 4], d)) {
				map[page][nr][nc] += score;
				if (score > 1) q.push(make_pair(nr, nc));
				visit[nr][nc] = true;
			}
		}

		if (cnt == 0) {
			cnt = q.size();
			score--;
		}
	}
}

void regulate() {
	int new_page = page ^ 1;
	int diff;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!(wall[i][j] & 1) && i > 0) { // no UP wall
				diff = map[page][i][j] - map[page][i - 1][j];
				if (diff > 0) {
					diff /= 4;
					map[new_page][i][j] -= diff;
					map[new_page][i - 1][j] += diff;
				}
				else if (diff < 0) {
					diff = (-diff) / 4;
					map[new_page][i][j] += diff;
					map[new_page][i - 1][j] -= diff;
				}

			}
			if (!(wall[i][j] & 2) && j < C - 1) { // no RIGHT wall
				diff = map[page][i][j] - map[page][i][j + 1];
				if (diff > 0) {
					diff /= 4;
					map[new_page][i][j] -= diff;
					map[new_page][i][j + 1] += diff;
				}
				else if (diff < 0) {
					diff = (-diff) / 4;
					map[new_page][i][j] += diff;
					map[new_page][i][j + 1] -= diff;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[new_page][i][j] += map[page][i][j];
		}
	}
	memset(map[page], 0, sizeof map[page]);
	page = new_page;
}

bool isWall(int r, int c, int d) {
	if (d == RIGHT) {
		return (wall[r][c] & 2);
	}
	else if (d == UP) {
		return (wall[r][c] & 1);
	}
	else if (d == LEFT) {
		return (wall[r][c - 1] & 2);
	}
	else { // d == DOWN
		return (wall[r + 1][c] & 1);
	}
}

void cooling() {
	for (int i = 0; i < R; i++) {
		if (map[page][i][0] > 0) map[page][i][0]--;
		if (map[page][i][C - 1] > 0) map[page][i][C - 1]--;
	}

	for (int i = 1; i < C - 1; i++) {
		if (map[page][0][i] > 0) map[page][0][i]--;
		if (map[page][R - 1][i] > 0) map[page][R - 1][i]--;
	}
}

bool isHot() {
	for (int i = 0; i < CP.size(); i++) {
		if (map[page][CP[i].first][CP[i].second] < K) {
			return false;
		}
	}
	return true;
}