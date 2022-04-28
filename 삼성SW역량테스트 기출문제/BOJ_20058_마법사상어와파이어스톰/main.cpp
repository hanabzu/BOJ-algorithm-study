/* BOJ_20058 마법사 상어와 파이어스톰 */
/* hanabzu */

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 6;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, Q, L, S, num, ans = 0, sum = 0;
int A[1 << MAXN][1 << MAXN], tmp[1 << MAXN][1 << MAXN], cnt[1 << MAXN][1 << MAXN];
bool visit[1 << MAXN][1 << MAXN];

void storm();
void rotate(int r, int c);
void melt();
void dfs(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			cin >> A[i][j];
		}
	}

	while (Q--) {
		cin >> L;
		if (L != 0) storm();
		melt();
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (visit[i][j] || A[i][j] == 0) continue;
			num = 1;
			visit[i][j] = true;
			dfs(i, j);
			ans = max(ans, num);
		}
	}

	cout << sum << '\n' << ans;
	return 0;
}

void storm() {
	memcpy(tmp, A, sizeof tmp);

	S = (1 << L);
	for (int i = 0; i < (1 << N); i += S) {
		for (int j = 0; j < (1 << N); j += S) {
			rotate(i, j);
		}
	}
}

void rotate(int r, int c) {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			A[r + i][c + j] = tmp[r + S - 1 - j][c + i];
		}
	}
}

void melt() {
	memset(cnt, 0, sizeof cnt);

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (A[i][j] > 0) {
				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];

					if (ni < 0 || ni >= (1 << N) || nj < 0 || nj >= (1 << N)) continue;
					cnt[ni][nj]++;
				}
			}	
		}
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (A[i][j] > 0 && cnt[i][j] < 3) {
				A[i][j]--;
			}
		}
	}
}

void dfs(int r, int c) {
	sum += A[r][c];

	for (int d = 0; d < 4; d++) {
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (nr < 0 || nr >= (1 << N) || nc < 0 || nc >= (1 << N) 
			|| visit[nr][nc] || A[nr][nc] == 0) continue;
		
		visit[nr][nc] = true;
		num++;
		dfs(nr, nc);
	}
}
