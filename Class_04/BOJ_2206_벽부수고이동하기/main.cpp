/* BOJ_2206 벽 부수고 이동하기 */
/* hanabzu */

#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1000;

struct Pos {
	int x, y, c; // c is whether broke the wall or not
	Pos(int x, int y, int c) :x(x), y(y), c(c) {}
};

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int m[MAXN][MAXN];
int dp[MAXN][MAXN][2];
int N, M;
string s;
queue<Pos> q;

void bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			m[i][j] = s[j] - '0';
		}
	}

	bfs();

	if (dp[N - 1][M - 1][0] == 0 && dp[N - 1][M - 1][1] == 0) {
		cout << -1;
	}
	else if (dp[N - 1][M - 1][1] == 0){
		cout << dp[N - 1][M - 1][0];
	}
	else {
		cout << dp[N - 1][M - 1][1];
	}
	return 0;
}

void bfs() {
	int q_size;
	q.push(Pos(0, 0, 0));
	dp[0][0][0] = 1;
	while (!q.empty()) {
		q_size = q.size();
		for (int k = 0; k < q_size; k++) {
			Pos u = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = u.x + dx[i];
				int ny = u.y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

				if (m[nx][ny] == 0 && dp[nx][ny][u.c] == 0) {
					dp[nx][ny][u.c] = dp[u.x][u.y][u.c] + 1;
					q.push(Pos(nx, ny, u.c));
				}

				if (u.c == 0) {
					if (m[nx][ny] == 1 && dp[nx][ny][1] == 0) {
						dp[nx][ny][1] = dp[u.x][u.y][0] + 1;
						q.push(Pos(nx, ny, 1));
					}
				}

			}
		}

	}
}