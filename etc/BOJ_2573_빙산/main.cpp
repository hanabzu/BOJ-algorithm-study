/* BOJ_2573 빙산 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 300;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, M, ice[MAXN][MAXN], mice[MAXN][MAXN], ice_cnt = 0, ans = 0;
bool visit[MAXN][MAXN], flag = false;

void dfs(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ice[i][j];
			if (ice[i][j] > 0) ice_cnt++;
		}
	}

	while (ice_cnt > 0) {
		memset(visit, 0, sizeof visit);
		flag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] == 0 || visit[i][j]) continue;

				if (flag == true) {
					cout << ans;
					return 0;
				}
				flag = true;
				visit[i][j] = true;
				dfs(i, j);
			}
		}
		memcpy(ice, mice, sizeof(mice));
		ans++;
	}
	cout << 0;
	return 0;
}


void dfs(int r, int c) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

		if (ice[nr][nc] == 0) {
			cnt++;
		}
		else if (!visit[nr][nc]) {
			visit[nr][nc] = true;
			dfs(nr, nc);
		}
	}

	mice[r][c] = max(0, ice[r][c] - cnt);
	if (mice[r][c] == 0) ice_cnt--;
}