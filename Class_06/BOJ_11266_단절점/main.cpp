/* BOJ_11266 단절점 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int MAXV = 10000;

int V, E, A, B, n = 0;
vector<int> e[MAXV + 1];
bool visit[MAXV + 1];
int parent[MAXV + 1];
int order[MAXV + 1];
set<int> ans;

int dfs(int v, bool isRoot);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		e[A].push_back(B);
		e[B].push_back(A);
	}

	for (int i = 1; i <= V; i++) {
		if (!visit[i]) {
			n = 0;
			dfs(i, true);
		}
	}

	cout << ans.size() << '\n';
	for (set<int>::iterator it = ans.begin(); it != ans.end();it++) {
		cout << *it << ' ';
	}
	return 0;
}


int dfs(int v, bool isRoot) { // return low
	int num_child = 0;
	visit[v] = true;
	order[v] = ++n;
	int now_low = n;

	for (vector<int>::iterator it = e[v].begin(); it != e[v].end(); it++) {
		if (*it == parent[v]) continue;

		if (order[*it] == 0) { // undiscovered
			num_child++;
			parent[*it] = v;
			int low = dfs(*it, false);

			if (!isRoot && low >= order[v]) {
				ans.insert(v);
			}
			now_low = min(now_low, low);
		}
		else {
			now_low = min(now_low, order[*it]);
		}
	}


	if (isRoot && num_child >= 2) {
		ans.insert(v);
	}

	return now_low;
}