/* hanabzu */
/* BOJ_7576 토마토 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int M, N, H, num_tomatoes, ripe = 0, day = -1;
int box[1002][1002]; // box[M][N]
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int, int>> q; // {M,N}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	num_tomatoes = M * N;

	// padding
	for (int j = 1; j <= N; j++) {
		for (int k = 1; k <= M; k++) {
			cin >> box[k][j];
			if (box[k][j] == -1) {
				num_tomatoes--;
			}
			if (box[k][j] == 1) {
				q.push(pair<int, int>(k, j));
				ripe++;
			}
			box[k][j]++;
		}
	}

	// BFS
	int q_count = q.size(); // initialize queue size
	while (!q.empty()) {
		pair<int, int> t = q.front();
		for (int i = 0; i < 4; i++) {
			if (box[t.first - dir[i][0]][t.second - dir[i][1]] == 1) {
				box[t.first - dir[i][0]][t.second - dir[i][1]] = 2;
				q.push(pair<int, int>(t.first - dir[i][0], t.second - dir[i][1]));
				ripe++;
			}
		}
		q.pop();
		q_count--;
		if (q_count == 0) { // next day
			q_count = q.size();
			day++;
		}
	}


	if (num_tomatoes == ripe) {
		cout << day;
	}
	else {
		cout << -1;
	}
}
