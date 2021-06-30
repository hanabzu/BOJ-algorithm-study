/* hanabzu */
/* BOJ_2178 미로 탐색 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M, q_count = 1, t = 1;
string line;
vector<bool> maze[102];
queue<pair<int, int>> q;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M + 2; i++) {
		maze[0].push_back(0);
		maze[N+1].push_back(0);
	}

	for (int i = 1; i <= N; i++) {
		cin >> line;
		maze[i].push_back(0);
		for (int j = 0; j < M; j++) {
			maze[i].push_back(line[j] - '0');
		}
		maze[i].push_back(0);
	}

	q.push(pair<int, int>(1, 1));
	maze[1][1] = 0;
	while (!q.empty()) {
		pair<int, int> u = q.front();
		if (u.first == N && u.second == M) {
			break;
		}
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			if (maze[u.first + dir[i][0]][u.second + dir[i][1]] == 1) {
				maze[u.first + dir[i][0]][u.second + dir[i][1]] = 0; // visited
				q.push(pair<int, int>(u.first + dir[i][0], u.second + dir[i][1]));
			}
		}

		if (--q_count == 0) {
			q_count = q.size();
			t++;
		}
	}

	cout << t;

	return 0;
}