/* BOJ_16234 인구 이동 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

const int MAXN = 50;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int N, L, R, ans = -1;
int A[MAXN][MAXN];
bool visit[MAXN][MAXN], isMoved = true;

void bfs(int i, int j);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	while (isMoved) {
		ans++;
		isMoved = false;
		memset(visit, 0, sizeof visit);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					bfs(i, j);
				}
			}
		}
	}

	cout << ans;
	return 0;
}


void bfs(int i, int j) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;

	int num = A[i][j];
	q.push(make_pair(i, j));
	v.push_back(make_pair(i, j));
	visit[i][j] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visit[nr][nc]) continue;

			int diff = abs(A[r][c] - A[nr][nc]);

			if (diff < L || diff> R) continue;

			num += A[nr][nc];
			q.push(make_pair(nr, nc));
			v.push_back(make_pair(nr, nc));
			visit[nr][nc] = true;
		}
	}

	if (v.size() == 1) return;

	isMoved = true;
	int aver = num / v.size();
	for (int i = 0; i < v.size(); i++) {
		A[v[i].first][v[i].second] = aver;
	}
}