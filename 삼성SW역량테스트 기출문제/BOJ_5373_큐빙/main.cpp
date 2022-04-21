/* BOJ_5373 큐빙 */
/* hanabzu */

#include <iostream>
#include <string.h>
using namespace std;

enum {
	U, D, F, B, L, R
};
const char color[6] = { 'w','y','r','o','g','b' };
const int adj[6][4] = { {F,L,B,R}, {F,R,B,L},
						{U,R,D,L}, {U,L,D,R},
						{U,F,D,B}, {U,B,D,F} };

int T, n;
string c;
char cube[6][3][3];

void testcase();
void rotate(int side, int dir);
void init();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		testcase();
	}

	return 0;
}

void testcase() {
	init();
	cin >> n;

	while (n--) {
		int side, dir;
		cin >> c;
		switch (c[0]) {
		case 'U': side = U; break;
		case 'D': side = D; break;
		case 'F': side = F; break;
		case 'B': side = B; break;
		case 'L': side = L; break;
		default : side = R;
		}
		dir = (c[1] == '+') ? 1 : -1;
		rotate(side, dir);
	}

	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			cout << cube[0][j][k];
		}
		cout << '\n';
	}
}

void rotate(int side, int dir) {
	char t[3][3];
	char tmp[3];

	//side rotate
	memcpy(t, cube[side], sizeof t);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (dir == 1) {
				cube[side][i][j] = t[2 - j][i];
			}
			else {
				cube[side][i][j] = t[j][2 - i];
			}
		}
	}

	if (side == U  || side == D) {
		int row = ((side == U) ? 0 : 2);
		memcpy(tmp, cube[adj[side][0]][row], 3);
		int d = 0;
		for (int i = 0; i < 3; i++) {
			memcpy(cube[adj[side][d]][row], cube[adj[side][(d - dir + 4) % 4]][row], 3);
			d = (d - dir + 4) % 4;
		}
		memcpy(cube[adj[side][(dir + 4) % 4]][row], tmp, 3);
	}
	else if (side == F) {
		memcpy(tmp, cube[U][2], 3);
		if (dir == 1) {
			for (int i = 0; i < 3; i++) {
				cube[U][2][i] = cube[L][2 - i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[L][i][2] = cube[D][0][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][0][i] = cube[R][2 - i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[R][i][0] = tmp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][2][i] = cube[R][i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[R][i][0] = cube[D][0][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][0][i] = cube[L][i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[L][i][2] = tmp[2 - i];
			}
		}
	}
	
	else if (side == B) {
		memcpy(tmp, cube[U][0], 3);
		if (dir == 1) {
			for (int i = 0; i < 3; i++) {
				cube[U][0][i] = cube[R][i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[R][i][2] = cube[D][2][2 - i];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][2][i] = cube[L][i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[L][i][0] = tmp[2 - i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][0][i] = cube[L][2 - i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[L][i][0] = cube[D][2][i];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][2][i] = cube[R][2 - i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[R][i][2] = tmp[i];
			}
		}
	}
	else if (side == L) {
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[U][i][0];
		}
		if (dir == 1) {
			for (int i = 0; i < 3; i++) {
				cube[U][i][0] = cube[B][2 - i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[B][2 - i][2] = cube[D][i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][i][0] = cube[F][i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[F][i][0] = tmp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][i][0] = cube[F][i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[F][i][0] = cube[D][i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][i][0] = cube[B][2 - i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[B][2 - i][2] = tmp[i];
			}
		}
	}
	else { // side == R
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[U][i][2];
		}
		if (dir == 1) {
			for (int i = 0; i < 3; i++) {
				cube[U][i][2] = cube[F][i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[F][i][2] = cube[D][i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][i][2] = cube[B][2 - i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[B][2 - i][0] = tmp[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				cube[U][i][2] = cube[B][2 - i][0];
			}
			for (int i = 0; i < 3; i++) {
				cube[B][2 - i][0] = cube[D][i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[D][i][2] = cube[F][i][2];
			}
			for (int i = 0; i < 3; i++) {
				cube[F][i][2] = tmp[i];
			}
		}
	}
}

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = color[i];
			}
		}
	}
}