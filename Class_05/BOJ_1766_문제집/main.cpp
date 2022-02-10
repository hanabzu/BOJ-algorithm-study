/* BOJ_1766 문제집 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 32000;

int N, M, A, B;
int indegree[MAXN + 1];
vector<int> e[MAXN + 1];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		e[A].push_back(B);
		indegree[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.top();
		q.pop();
		cout << u << ' ';

		for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
			if (--indegree[*it] == 0) {
				q.push(*it);
			}
		}
	}

	return 0;
}