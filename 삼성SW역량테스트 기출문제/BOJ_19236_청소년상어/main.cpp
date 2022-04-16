/* BOJ_19236 청소년 상어 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

struct Fish {
	int d, r, c;
	Fish() {}
	Fish(int d, int r, int c) : d(d), r(r), c(c) {}
};

const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
const int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int matrix[4][4], ans = 0, a, b;
Fish fish[17];
pair<int, int> shark;
int d_shark;

void backtrack(int score);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			matrix[i][j] = a;
			fish[a] = Fish((b + 7) % 8, i, j);
		}
	}

	shark = make_pair(0, 0);
	d_shark = fish[matrix[0][0]].d;
	ans += matrix[0][0];
	matrix[0][0] = -1; // shark = -1, blank= 0
	backtrack(ans);

	cout << ans;
	return 0;
}

void backtrack(int score) {
	ans = max(ans, score);
	int t_matrix[4][4];
	Fish t_fish[17];
	memcpy(t_matrix, matrix, sizeof(matrix));
	memcpy(t_fish, fish, sizeof(fish));

	// fish move
	for (int i = 1; i < 17; i++) {
		if (matrix[fish[i].r][fish[i].c] != i) continue;

		for (int dir = 0; dir < 8; dir++) {
			int nd = (fish[i].d + dir) % 8;
			int nr = fish[i].r + dx[nd];
			int nc = fish[i].c + dy[nd];

			if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || matrix[nr][nc] == -1) continue;
			
			if (matrix[nr][nc] == 0) { // blank
				swap(matrix[nr][nc], matrix[fish[i].r][fish[i].c]);
				fish[i].r = nr;
				fish[i].c = nc;
				fish[i].d = nd;
			}
			else { // change two fish
				int p = matrix[nr][nc];
				fish[i].d = nd;
				swap(matrix[nr][nc], matrix[fish[i].r][fish[i].c]);
				swap(fish[i].r, fish[p].r);
				swap(fish[i].c, fish[p].c);
			}
	
			break;
		}
	}

	// shark move
	for (int i = 1; i <= 3; i++) {
		int nr = shark.first + dx[d_shark] * i;
		int nc = shark.second + dy[d_shark] * i;

		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || matrix[nr][nc] == 0) continue;

		// fish exists
		int tmp = matrix[nr][nc];
		int t_d_shark = d_shark;
		pair<int, int> t_shark = shark;
		matrix[shark.first][shark.second] = 0;

		shark = make_pair(nr, nc);
		d_shark = fish[matrix[nr][nc]].d;
		int t_score = score + matrix[nr][nc];
		matrix[nr][nc] = -1;

		backtrack(t_score);

		matrix[nr][nc] = tmp;
		shark = t_shark;
		d_shark = t_d_shark;
		matrix[shark.first][shark.second] = -1;
	}
	memcpy(matrix, t_matrix, sizeof(matrix));
	memcpy(fish, t_fish, sizeof(fish));
}