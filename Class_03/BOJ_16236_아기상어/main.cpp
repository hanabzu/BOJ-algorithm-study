/* hanabzu */
/* BOJ_16236 아기 상어 */

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, shark = 2, stomach = 2, total_time = 0;
pair<int,int> pos;
int pool[22][22];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool BFS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> pool[i][j];
			if (pool[i][j] == 9) {
				pos.first = i;
				pos.second = j;
				pool[i][j] = 0;
			}
		}
	}

	//padding
	for (int i = 0; i < N+2; i++) {
		pool[0][i] = 1000;
		pool[N+1][i] = 1000;
		pool[i][0] = 1000;
		pool[i][N+1] = 1000;
	}

	while (BFS());

	cout << total_time;

	return 0;
}

bool BFS() {
	bool visit[22][22] = { 0, };
	queue<pair<int, int>> q;
	vector<pair<int, int>> preys;
	q.push(pos);
	visit[pos.first][pos.second] = 1;
	int q_count = 1, t = 0;

	while (!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> nextpos(u.first + dx[i], u.second + dy[i]);
			if (pool[nextpos.first][nextpos.second] <= shark) {
				if (!visit[nextpos.first][nextpos.second]) {
					if (pool[nextpos.first][nextpos.second] < shark &&
						pool[nextpos.first][nextpos.second] > 0) {
						preys.push_back(nextpos); // candidates of eating
					}
					else { // move to zero
						q.push(nextpos);
						visit[nextpos.first][nextpos.second] = 1;
					}
				}
			}
		}

		if (--q_count == 0) { // find all preys in cycle
			if (!preys.empty()) { // eat prey
				sort(preys.begin(), preys.end());
				pair<int, int> nextpos = *preys.begin(); // top left
				pool[nextpos.first][nextpos.second] = 0;
				if (--stomach == 0) { // full -> grow up
					stomach = shark += 1;
				}

				pos = nextpos;
				total_time += ++t;
				return true;
			}
			q_count = q.size();
			t++;
		}
	}

	return false; // call mommy
}