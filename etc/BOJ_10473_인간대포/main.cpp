/* BOJ_10473 인간 대포 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

const int MAXN = 100;
const float INF = 987654321.0;

int N;
float X[MAXN + 2], Y[MAXN + 2];
float s[MAXN + 2][MAXN + 2], cost[MAXN+2];

void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> N;
	for (int i = 2; i < N + 2; i++) {
		cin >> X[i] >> Y[i];
	}

	N += 2;

	fill(&s[0][0], &s[MAXN + 1][MAXN + 2], INF);
	fill(cost, cost + MAXN + 2, INF);

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			float d = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
			float walk = d / 5.0;
			float cannon = abs(d - 50) / 5.0 + 2.0;
			if (i == 0) {
				s[i][j] = walk;
			}
			else if (j == 1) {
				s[i][j] = min(walk, cannon);
			}
			else {
				s[i][j] = s[j][i] = min(walk, cannon);
			}
		}
	}

	dijkstra();

	cout << cost[1];

	return 0;
}

void dijkstra() {
	queue<int> q;

	q.push(0);
	cost[0] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < N; i++) {
			if (i == u) continue;

			if (cost[u] + s[u][i] < cost[i]) {
				cost[i] = cost[u] + s[u][i];
				q.push(i);
			}
		}
	}
}