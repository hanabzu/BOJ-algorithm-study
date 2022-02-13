/* BOJ_16946 벽 부수고 이동하기 4 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 1000;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

string s;
int N, M, ans[MAXN][MAXN], m[MAXN][MAXN];
bool visit[MAXN][MAXN];
void bfs(int i, int j);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s; 
		for (int j = 0; j < M; j++) {
			if (s[j] == '1') {
				m[i][j] = 1;
				ans[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 0 && visit[i][j] == false) {
				bfs(i, j);
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}

void bfs(int i, int j) {
	int num = 0;
	queue<pair<int, int>> q, dp;

	q.push(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit[x][y] = true;
		num++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (visit[nx][ny] == true) continue;

			if (m[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
			}
			else {
				dp.push(make_pair(nx, ny));
			}
	
			visit[nx][ny] = true;
		}
	}


	while (!dp.empty()) {
		int x = dp.front().first;
		int y = dp.front().second;
		dp.pop();

		ans[x][y] = (ans[x][y] + num) % 10;
		visit[x][y] = false;
	}

}