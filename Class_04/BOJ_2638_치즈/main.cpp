/* BOJ_2638 치즈 */
/* hanabzu */

#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int MAXN = 100;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int N, M, cnt = 0, t = 0;

int d[MAXN][MAXN];
int air[MAXN][MAXN];

void melt();
void set_air();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> d[i][j];
			if (d[i][j] == 1) cnt++;
		}
	}

	
	while (cnt) {
		melt();
		t++;
	}

	cout << t;

	return 0;
}

void melt() {
	set_air();

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (d[r][c] == 0) continue;
			int num = 0;
			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];
				if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				if (air[nr][nc] == 1) {
					num++;
				}
			}

			if (num >= 2) {
				d[r][c] = 0;
				cnt--;
			}
		}
	}
}

void set_air() {
	memset(air, 0, sizeof(air));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (air[nr][nc] == 0 && d[nr][nc] == 0) {
				air[nr][nc] = 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
}