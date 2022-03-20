/* BOJ_5719 거의 최단 경로 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
#include <algorithm>

#define MAXN 500

using namespace std;

int N, M, S, D, U, V, P, min_d;
int d[MAXN];
vector<pair<int, int>> e[MAXN];
vector<int> parent[MAXN];
bool isPath[MAXN][MAXN];
void dijkstra(int flag);
void remove(int start, int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N >> M;
		if (!N) break;
		cin >> S >> D;

		for (int i = 0; i < N; i++) {
			d[i] = INT_MAX;
			e[i].clear();
			for (int j = 0; j < N; j++) {
				isPath[i][j] = false;
			}
		}

		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			e[U].push_back(make_pair(P, V));
		}
		dijkstra(1);
		if (d[D] == INT_MAX) {
			cout << "-1\n";
			continue;
		}

		remove(S, D);
		for (int i = 0; i < N; i++) {
			d[i] = INT_MAX;
		}

		dijkstra(2);

		if (d[D] == INT_MAX) {
			cout << "-1\n";
		}
		else {
			cout << d[D] << '\n';
		}
	}

	return 0;
}

void remove(int start, int node) {
	if (node == start) return;
	for (int i = 0; i < parent[node].size(); i++) {
		if (isPath[parent[node][i]][node]) continue;
		isPath[parent[node][i]][node] = true;
		remove(start, parent[node][i]);
	}

}
void dijkstra(int flag) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	d[S] = 0;
	q.push(make_pair(0, S));

	while (!q.empty()) {
		pair<int, int> u = q.top();
		q.pop();
		int node = u.second;

		for (vector<pair<int, int>>::iterator it = e[node].begin(); it != e[node].end(); it++) {
			int next_node = (*it).second;
			int cost = (*it).first;

			if (isPath[node][next_node]) continue;
			if (d[next_node] > d[node] + cost) {
				d[next_node] = d[node] + cost;
				q.push(make_pair(d[next_node], next_node));
				if (flag == 1) {
					parent[next_node].clear();
					parent[next_node].push_back(node);
				}
			}
			else {
				if (flag == 1) {
					if (d[next_node] == d[node] + cost) {
						parent[next_node].push_back(node);
					}
				}
			}
		}
	}
}


