/* BOJ_4485 녹색 옷 입은 애가 젤다지? */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 125;
const int INF = 987654321;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

struct Node {
	int r, c, w;
	Node() {}
	Node(int r, int c, int cost) : r(r), c(c), w(cost) {}
	bool operator<(const Node& rhs) const {
		return w > rhs.w;
	}
};

int N, tc = 1;
int cave[MAXN][MAXN], cost[MAXN][MAXN];

void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cave[i][j];
			}
		}

		dijkstra();

		cout << "Problem " << tc++ << ": " << cost[N - 1][N - 1] << '\n';
	}

	return 0;
}

void dijkstra() {
	priority_queue<Node> q;
	for (int i = 0; i < N; i++) {
		fill(cost[i], cost[i] + N, INF);
	}
	cost[0][0] = cave[0][0];
	q.push(Node(0, 0, cost[0][0]));

	while (!q.empty()) {
		int r = q.top().r;
		int c = q.top().c;
		int w = q.top().w;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			if (cost[nr][nc] > cost[r][c] + cave[nr][nc]) {
				cost[nr][nc] = cost[r][c] + cave[nr][nc];
				q.push(Node(nr, nc, cost[nr][nc]));
			}
		}
	}
}