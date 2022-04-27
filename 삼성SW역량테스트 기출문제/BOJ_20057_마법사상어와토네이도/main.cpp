/* BOJ_20057 마법사 상어와 토네이도 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 499;
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int N, r, c, nr, nc, d = 0, S = 1, turn = 0, cnt = 1, ans = 0;
int A[MAXN][MAXN];

void spread();
void sum(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	r = c = (N >> 1);

	while (!(r == 0 && c == 0)) {
		spread();

		if (++turn == cnt) {
			turn = 0;
			d = (d + 1) % 4;
			if ((d & 1) == 0) cnt++;
		}
	}

	cout << ans;
	return 0;
}

void spread() {
	r = r + dx[d];
	c = c + dy[d];

	int sand = A[r][c], s;

	// 1%
	s = static_cast<int>(sand * 1 / 100);
	A[r][c] -= (s << 1);

	nr = r - dx[d] + dx[(d + 1) % 4];
	nc = c - dy[d] + dy[(d + 1) % 4];

	sum(s);

	nr -= (dx[(d + 1) % 4] << 1);
	nc -= (dy[(d + 1) % 4] << 1);

	sum(s);

	// 2%
	s = static_cast<int>(sand * 1 / 50);
	A[r][c] -= (s << 1);

	nr = r + (dx[(d + 1) % 4] << 1);
	nc = c + (dy[(d + 1) % 4] << 1);

	sum(s);

	nr -= (dx[(d + 1) % 4] << 2);
	nc -= (dy[(d + 1) % 4] << 2);

	sum(s);

	// 7%
	s = static_cast<int>(sand * 7 / 100);
	A[r][c] -= (s << 1);

	nr = r + dx[(d + 1) % 4];
	nc = c + dy[(d + 1) % 4];

	sum(s);

	nr -= (dx[(d + 1) % 4] << 1);
	nc -= (dy[(d + 1) % 4] << 1);

	sum(s);

	// 10%
	s = static_cast<int>(sand * 1 / 10);
	A[r][c] -= (s << 1);

	nr = r + dx[d] + dx[(d + 1) % 4];
	nc = c + dy[d] + dy[(d + 1) % 4];

	sum(s);

	nr -= (dx[(d + 1) % 4] << 1);
	nc -= (dy[(d + 1) % 4] << 1);

	sum(s);

	// 5%
	s = static_cast<int>(sand * 1 / 20);
	A[r][c] -= s;

	nr = r + (dx[d] << 1);
	nc = c + (dy[d] << 1);

	sum(s);

	// rest

	nr = r + dx[d];
	nc = c + dy[d];

	sum(A[r][c]);
	A[r][c] = 0;
}

void sum(int s) {
	if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
		ans += s;
	}
	else {
		A[nr][nc] += s;
	}
}