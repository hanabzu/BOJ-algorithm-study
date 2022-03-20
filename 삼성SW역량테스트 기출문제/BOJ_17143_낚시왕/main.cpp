/* BOJ_17143 낚시왕 */
/* hanabzu */

#include <iostream>
#include <string.h>
using namespace std;

const int MAXR = 100;
enum {
	UP, DOWN, RIGHT, LEFT
};

int R, C, M, r, c, s, d, z, ans = 0;
int water[MAXR][MAXR];

class Shark {
public:
	bool isAlive = true;
	int i, r, c, s, d, z;
	Shark(int i, int r, int c, int s, int d, int z) : i(i), r(r), c(c), s(s), d(d), z(z) {}
	Shark() {}
	void move();
};

Shark S[MAXR * MAXR + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		water[r - 1][c - 1] = i;
		S[i] = Shark(i, r - 1, c - 1, s, d - 1, z);
	}

	for (int i = 0; i < C; i++) {
		for (int depth = 0; depth < R; depth++) {
			if (water[depth][i] == 0) continue;

			S[water[depth][i]].isAlive = false; // catch
			ans += S[water[depth][i]].z;
			break;
		}

		memset(water, 0, sizeof(water));

		for (int j = 1; j <= M; j++) {
			if(S[j].isAlive) S[j].move();
		}
	}

	cout << ans;
	return 0;
}

void Shark::move() {
	int mod;
	int R_loop = (R - 1) << 1;
	int C_loop = (C - 1) << 1;
	if (d == UP || d == DOWN) {
		mod = s % R_loop;
		if (d == UP) {
			r -= mod;
			if (r < 0) {
				r = -r;
				d = DOWN;
			}
			if (r >= R) {
				r = R_loop - r;
				d = UP;
			}
		}
		else { // d == DOWN
			r += mod;
			if (r >= R) {
				r = R_loop - r;
				d = UP;
			}
			if (r < 0) {
				r = -r;
				d = DOWN;
			}
		}
	}
	else { // d == RIGHT or LEFT
		mod = s % C_loop;
		if (d == RIGHT) {
			c += mod;
			if (c >= C) {
				c = C_loop - c;
				d = LEFT;
			}
			if (c < 0) {
				c = -c;
				d = RIGHT;
			}
		}
		else { // d == LEFT
			c -= mod;
			if (c < 0) {
				c = -c;
				d = RIGHT;
			}
			if (c >= C) {
				c = C_loop - c;
				d = LEFT;
			}
		}
	}

	if (water[r][c] == 0) {
		water[r][c] = i;
	}
	else {
		if (S[water[r][c]].z < this->z) {
			S[water[r][c]].isAlive = false;
			water[r][c] = i;
		}
		else {
			isAlive = false;
		}
	}
}