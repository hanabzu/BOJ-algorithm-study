/* BOJ_2523 음악프로그램 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N, M, K, a, b;
int indegree[MAXN + 1];
vector<int> e[MAXN + 1];
vector<int> ans;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> K >> a;
		for (int j = 0; j < K - 1; j++) {
			cin >> b;
			e[a].push_back(b);
			indegree[b]++;
			a = b;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
			if (--indegree[*it] == 0) {
				q.push(*it);
			}
		}
	}

	if (ans.size() == N) {
		for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
			cout << *it << '\n';
		}
	}
	else {
		cout << 0;
	}

	return 0;
}