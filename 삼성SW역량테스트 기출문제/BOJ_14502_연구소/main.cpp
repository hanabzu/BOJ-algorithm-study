/* BOJ_14502 연구소 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N, M, new_x, new_y, max_safe_zone = 0;
int lab[10][10];
void back_tracking(int d, int r, int c);
int bfs();
queue<pair<int, int>> virus;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// initialize walls
	for (int i = 0; i <= N+1; i++) {
		lab[i][0] = lab[i][M+1] = 1;
	}
	for (int i = 1; i <= M; i++) {
		lab[0][i] = lab[N+1][i] = 1;
	}

	// read map
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) {
				virus.push(make_pair(i, j));
			}
		}
	}

	back_tracking(0, 1, 1);

	cout << max_safe_zone;

	return 0;
}


void back_tracking(int d, int r, int c){
	// placed 3 walls
	if (d == 3) { 
		max_safe_zone = max(max_safe_zone, bfs());
		return;
	}

	// brute force
	for (int i = r; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if ((!(i == r && j < c)) && lab[i][j] == 0) {
				lab[i][j] = 1;

				back_tracking(d + 1, i, j);

				lab[i][j] = 0;
			}
		}
	}
}

int bfs() {
	queue<pair<int, int>> q = virus;

	// infection
	while (!q.empty()) {
		pair<int,int> u = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			new_x = u.first + dx[i];
			new_y = u.second + dy[i];
			if (!lab[new_x][new_y]) {
				lab[new_x][new_y] = 3;
				q.push(make_pair(new_x, new_y));
			}
		}
	}

	// count safe zones & reset lab
	int safe_zone = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (lab[i][j] == 0) {
				safe_zone++;
			}
			else if (lab[i][j] == 3) {
				lab[i][j] = 0;
			}
		}
	}

	return safe_zone;
}