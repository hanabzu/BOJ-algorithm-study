/* BOJ_23290 마법사 상어와 복제 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int sdx[4] = { -1,0,1,0 };
const int sdy[4] = { 0,-1,0,1 };

class Shark {
public:
	int r, c;
	Shark() {}

	void move();
	void step(int r, int c, int cnt, int depth);
};

struct ThreeMove {
	int d[3];
	ThreeMove() {}
	ThreeMove(int steps[]) {
		for (int i = 0; i < 3; i++) {
			d[i] = steps[i];
		}
	}

	bool operator<(const ThreeMove& rhs) const;
};

int M, S, fx, fy, d, sr, sc, page = 0, max_cnt = 0, ans = 0;
Shark shark;
vector<ThreeMove> tm;
int steps[3];
int stink[4][4];
vector<int> map[2][4][4], tmp[4][4];
bool visit[4][4];

void move();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		cin >> fx >> fy >> d;
		fx--; fy--; d--;
		map[page][fx][fy].push_back(d);
	}
	cin >> shark.r >> shark.c;
	shark.r--; shark.c--;

	while (S--) {
		// memorize
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tmp[i][j] = map[page][i][j];
			}
		}

		// fish move
		move();

		// page change
		page ^= 1;

		// shark move
		shark.move();

		// stink shrink
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (stink[i][j] > 0) stink[i][j]--;
			}
		}

		// duplicate
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < tmp[i][j].size(); k++) {
					map[page][i][j].push_back(tmp[i][j][k]);
				}
			}
		}
	}

	// count fish
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ans += map[page][i][j].size();
		}
	}
	cout << ans;

	return 0;
}

void Shark::move() {
	memset(visit, 0, sizeof visit);
	tm.clear();
	max_cnt = 0;

	step(shark.r, shark.c, 0, 0);

	sort(tm.begin(), tm.end());
	
	ThreeMove& way = *tm.begin();
	int nr = shark.r, nc = shark.c;
	for (int i = 0; i < 3; i++) {
		nr += sdx[way.d[i]];
		nc += sdy[way.d[i]];

		if(!map[page][nr][nc].empty()) stink[nr][nc] = 3;
		map[page][nr][nc].clear();
	}
	shark.r = nr;
	shark.c = nc;
}

void Shark::step(int r, int c, int cnt, int depth) {
	if (depth == 3) {
		if (cnt < max_cnt) return;

		if (cnt > max_cnt) {
			tm.clear();
			max_cnt = cnt;
		}
		tm.push_back(ThreeMove(steps));
		return;
	}
	int nr, nc;
	for (int i = 0; i < 4; i++) {
		nr = r + sdx[i];
		nc = c + sdy[i];

		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;

		steps[depth] = i;
		if (visit[nr][nc]) {
			step(nr, nc, cnt, depth + 1);
		}
		else {
			visit[nr][nc] = true;
			step(nr, nc, cnt + map[page][nr][nc].size(), depth + 1);
			visit[nr][nc] = false;
		}
	}
}

void move() {
	int nr, nc;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			for (int i = 0; i < map[page][r][c].size(); i++) {
				int d = map[page][r][c][i];
				for (int j = 8; j > 0; j--) {
					nr = r + dx[(d + j) % 8];
					nc = c + dy[(d + j) % 8];

					if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 ||
						((nr == shark.r) && (nc == shark.c)) || stink[nr][nc] != 0) {
						if (j == 1) { // can't move
							map[page ^ 1][r][c].push_back(d);
						}
						continue;
					}
					// can move
					map[page ^ 1][nr][nc].push_back((d + j) % 8);
					break;
				}
			}
			map[page][r][c].clear();
		}
	}
}

bool ThreeMove::operator<(const ThreeMove& rhs) const{
	if (d[0] == rhs.d[0]) {
		if (d[1] == rhs.d[1]) {
			return d[2] < rhs.d[2];
		}
		return d[1] < rhs.d[1];
	}
	return d[0] < rhs.d[0];
}