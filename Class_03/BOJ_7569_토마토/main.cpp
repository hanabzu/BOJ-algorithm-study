/* hanabzu */
/* BOJ_7569 토마토 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int M, N, H, num_tomatoes, ripe = 0, day = 0;
int box[102][102][102]; // box[H][M][N]
int dir[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
queue<pair<int,pair<int,int>>> q; // {H,M,N}

void print_tomatoes(); // for debugging

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	num_tomatoes = M * N * H;

	// padding
	for (int i = 1; i <= H ; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> box[i][k][j];
				if (box[i][k][j] == -1) {
					num_tomatoes--;
				}
				if (box[i][k][j] == 1) {
					q.push(pair<int, pair<int, int>>(i,pair<int,int>(k,j)));
					ripe++;
				}
				box[i][k][j]++;
			}
		}
	}

	// BFS
	int q_count = q.size(); // initialize queue size
	while (!q.empty()) {
		pair<int, pair<int, int>> t = q.front();
		for (int i = 0; i < 6; i++) {
			if (box[t.first - dir[i][0]][t.second.first - dir[i][1]][t.second.second - dir[i][2]] == 1) {
				box[t.first - dir[i][0]][t.second.first - dir[i][1]][t.second.second - dir[i][2]] = 2;
				q.push(pair<int, pair<int, int>>(t.first - dir[i][0],
					pair<int, int>(t.second.first - dir[i][1], t.second.second - dir[i][2])));
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
		cout << --day; // minus last day
	}
	else {
		cout << -1;
	}
	
	//print_tomatoes(); 
}

void print_tomatoes() {
	for (int i = 0; i < H + 2; i++) {
		for (int j = 0; j <= N + 1; j++) {
			for (int k = 0; k <= M + 1; k++) {
				cout << box[i][k][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	cout << num_tomatoes << '\n' << ripe << '\n' << day;
}