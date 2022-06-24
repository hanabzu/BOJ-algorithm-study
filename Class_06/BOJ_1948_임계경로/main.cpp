/* BOJ_1948 임계경로 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;
const int MAXN = 10000;

int N, M, a, b, c, S, E, u, nu, nw, cnt = 0;
vector<pii> e[MAXN + 1], re[MAXN+1];
int indegree[MAXN+1], d[MAXN + 1];
bool visit[MAXN + 1];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		indegree[b]++;
		e[a].push_back(make_pair(b, c));
		re[b].push_back(make_pair(a, c));
	}
	cin >> S >> E;

	fill(d, d + MAXN + 1, -1);
	d[S] = 0;
	q.push(S);

	while (!q.empty()) {
		u = q.front();
		q.pop();

		for (int i = 0; i < e[u].size(); i++) {
			nu = e[u][i].first;
			nw = e[u][i].second;

			if (d[nu] < d[u] + nw) {
				d[nu] = d[u] + nw;
			}

			if (--indegree[nu] == 0) {
				q.push(nu);
			}
		}
	}
	cout << d[E] << '\n';

	q.push(E);
	while (!q.empty()) {
		u = q.front();
		q.pop();

		for (int i = 0; i < re[u].size(); i++) {
			nu = re[u][i].first;
			nw = re[u][i].second;

			if (nw == d[u] - d[nu]) {
				cnt++;
				if (!visit[nu]) {
					q.push(nu);
					visit[nu] = true;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}