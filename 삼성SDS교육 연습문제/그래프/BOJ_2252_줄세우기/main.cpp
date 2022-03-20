/* BOJ_2252 줄 세우기 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <queue>
#define MAXV 32000

using namespace std;

int N, M, a, b;
vector<int> v[MAXV + 1];
queue<int> q;
int indegree[MAXV + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		++indegree[b];
	}

	for (int i = 1; i <= N; ++i) {
		if (!indegree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << ' ';

		for (vector<int>::iterator it = v[u].begin(); it != v[u].end(); ++it) {
			if (!(--indegree[*it])) {
				q.push(*it);
			}
		}

	}

	return 0;
}