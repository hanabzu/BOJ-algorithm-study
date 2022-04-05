/* BOJ_16235 나무 재테크 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

const int MAXN = 10;
const int INF = 987654321;
const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int N, M, K, A[MAXN][MAXN], x, y, z;
int food[MAXN][MAXN];
deque<int> trees[MAXN][MAXN];

void year();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			food[i][j] = 5;
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
	}

	while (K--) {
		year();
	}

	cout << M;
	return 0;
}

void year() {
	int dead[MAXN][MAXN] = { 0, };
	vector<pair<int, int>> breed;

	// spring
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] == INF) break;

				if (food[i][j] < trees[i][j][k]) { // die
					M--;
					dead[i][j] += (trees[i][j][k] >> 1);
					trees[i][j][k] = INF;
				}
				else { // grow
					food[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
					if (trees[i][j][k] % 5 == 0) {
						breed.push_back(make_pair(i, j));
					}
				}
			}
		}
	}

	// summer
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			food[i][j] += dead[i][j];
		}
	}

	// fall
	int r, c, nr, nc;
	for (int i = 0; i < breed.size(); i++) {
		r = breed[i].first;
		c = breed[i].second;
		for (int d = 0; d < 8; d++) {
			nr = r + dx[d];
			nc = c + dy[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			M++;
			trees[nr][nc].push_front(1);
		}
	}

	// winter
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			food[i][j] += A[i][j];
		}
	}
}

