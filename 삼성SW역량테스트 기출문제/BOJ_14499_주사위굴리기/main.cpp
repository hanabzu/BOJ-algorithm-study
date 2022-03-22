/* BOJ_14499 주사위 굴리기 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 20;
const int dx[5] = { 0, 0, 0, -1, 1 };
const int dy[5] = { 0, 1, -1, 0, 0 };

class Dice {
public:
	int top = 0, north = 0, east = 0, west = 0, south = 0, bot = 0;
	int xpos = 0, ypos = 0;
	Dice() {}
	bool rotate(int dir);
};

int N, M, K, d;
int map[MAXN][MAXN];
Dice dice;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> dice.xpos >> dice.ypos >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (K--) {
		cin >> d;
		if (dice.rotate(d)) {
			cout << dice.top << '\n';
		}
	}

	return 0;
}

bool Dice::rotate(int d) {
	int nx = xpos + dx[d];
	int ny = ypos + dy[d];

	if (nx < 0 || nx >= N || ny < 0 || ny >= M) return false;

	Dice prev = dice;
	if (d == 1) { // east
		top = prev.west;
		west = prev.bot;
		bot = prev.east;
		east = prev.top;
	}
	else if (d == 2) { // west
		top = prev.east;
		east = prev.bot;
		bot = prev.west;
		west = prev.top;
	}
	else if (d == 3) { // north
		top = prev.south;
		south = prev.bot;
		bot = prev.north;
		north = prev.top;
	}
	else if (d == 4) { // south
		top = prev.north;
		north = prev.bot;
		bot = prev.south;
		south = prev.top;
	}

	// change number
	if (map[nx][ny] == 0) {
		map[nx][ny] = bot;
	}
	else {
		bot = map[nx][ny];
		map[nx][ny] = 0;
	}
	xpos = nx;
	ypos = ny;

	return true;
}