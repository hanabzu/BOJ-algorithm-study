/* BOJ_2056 작업 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10000;

int N, M, P, A[MAXN + 1], indegree[MAXN + 1], dp[MAXN + 1], ans, cnt;
vector<int> v[MAXN+1];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> M;
		dp[i] = A[i];
		for (int j = 0; j < M; j++) {
			cin >> P;
			v[P].push_back(i);
			indegree[i]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	int q_size = q.size();
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < v[u].size(); i++) {
			int& w = v[u][i];
			dp[w] = max(dp[w], dp[u] + A[w]);
			if (--indegree[w] == 0) {
				q.push(w);
			}
		}
	}

	cout << *max_element(dp + 1, dp + N + 1);
	return 0;
}