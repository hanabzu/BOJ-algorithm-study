/* BOJ_3176 도로 네트워크 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MAXW = 1000001;
const int MAXN = 100000;
const int MAXP = 18;

vector<pair<int,int>> e[MAXN + 1];
bool visit[MAXN + 1];
int depth[MAXN + 1];
int parent[MAXP][MAXN + 1];
int minw[MAXP][MAXN + 1];
int maxw[MAXP][MAXN + 1];

int N, K, A, B, C, D, E;
void dfs(int p);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> A >> B >> C;
		e[A].push_back(make_pair(B, C));
		e[B].push_back(make_pair(A, C));
	}

	dfs(1); // make tree


	for (int i = 0; i < MAXP - 1; i++) { // fill 2^i parent array
		for (int j = 1; j <= N; j++) {
			if (parent[i][j] != 0) {
				parent[i + 1][j] = parent[i][parent[i][j]];
				maxw[i + 1][j] = max(maxw[i][j], maxw[i][parent[i][j]]);
				minw[i + 1][j] = min(minw[i][j], minw[i][parent[i][j]]);
			}
		}
	}


	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> D >> E;
		if (depth[D] < depth[E]) swap(D, E);
		
		int diff_depth = depth[D] - depth[E];
		int mn = MAXW, mx = 0;

		for (int j = 0; diff_depth; j++) { // move a to same depth with E
			if (diff_depth & 1) {
				mn = min(minw[j][D], mn);
				mx = max(maxw[j][D], mx);
				D = parent[j][D];
			}
			diff_depth >>= 1;
		}
		if (D != E) {
			for (int j = MAXP - 1; j >= 0; j--) {
				if (parent[j][D] != 0 && parent[j][D] != parent[j][E]) {
					mn = min(minw[j][D], mn);
					mx = max(maxw[j][D], mx);
					D = parent[j][D];
					mn = min(minw[j][E], mn);
					mx = max(maxw[j][E], mx);
					E = parent[j][E];
				}
			}
			mn = min(minw[0][D], mn);
			mx = max(maxw[0][D], mx);
			mn = min(minw[0][E], mn);
			mx = max(maxw[0][E], mx);
		}
	
		cout << mn << ' ' << mx << '\n';
	}


	return 0;
}

void dfs(int p) {
	visit[p] = true;
	for (vector<pair<int,int>>::iterator it = e[p].begin(); it != e[p].end(); it++) {
		if (!visit[(*it).first]) {
			parent[0][(*it).first] = p;
			maxw[0][(*it).first] = minw[0][(*it).first] = (*it).second;
			depth[(*it).first] = depth[p] + 1;
			dfs((*it).first);
		}
	}
}