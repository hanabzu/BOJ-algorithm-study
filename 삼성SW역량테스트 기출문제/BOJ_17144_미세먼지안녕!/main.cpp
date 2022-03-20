/* BOJ_17144 미세먼지 안녕! */
/* hanabzu */

#include <iostream>
#include <queue>
using namespace std;

struct Dust {
	int r, c, amount; // spread amount
	Dust(int r, int c, int amount) :r(r), c(c), amount(amount) {}
};

const int MAXR = 50;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };
int R, C, T, ans = 2, aPos;
int room[MAXR][MAXR];

void spread();
void clean();
bool boundary_check(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				aPos = i;// air washer position
			}
		}
	}

	while (T--) {
		spread();
		clean();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += room[i][j];
		}
	}

	cout << ans;
	return 0;
}

void spread() {
	queue<Dust> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] >= 5) {
				q.push(Dust(i, j, room[i][j] / 5));
			}
		}
	}

	while (!q.empty()) {
		Dust u = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nr = u.r + dx[i];
			int nc = u.c + dy[i];
			if (room[nr][nc] != -1 && boundary_check(nr, nc)) {
				room[nr][nc] += u.amount;
				room[u.r][u.c] -= u.amount;
			}
		}
	}
}

void clean() {
	// down side
	int c, pos = aPos + 1;
	for (; pos < R - 1; pos++) {
		room[pos][0] = room[pos + 1][0];
	}
	for (c = 0; c < C - 1; c++) {
		room[pos][c] = room[pos][c + 1];
	}
	for (; pos > aPos; pos--) {
		room[pos][c] = room[pos - 1][c];
	}
	for (; c > 1; c--) {
		room[pos][c] = room[pos][c - 1];
	}
	room[pos][c] = 0;

	// top side
	pos = aPos - 2;
	for (; pos > 0; pos--) {
		room[pos][0] = room[pos - 1][0];
	}
	for (c = 0; c < C - 1; c++) {
		room[pos][c] = room[pos][c + 1];
	}
	for (; pos < aPos - 1; pos++) {
		room[pos][c] = room[pos + 1][c];
	}
	for (; c > 1; c--) {
		room[pos][c] = room[pos][c - 1];
	}
	room[pos][c] = 0;
}

bool boundary_check(int r, int c) {
	if (r >= 0 && r < R && c >= 0 && c < C) 
		return true;
	else 
		return false;
}