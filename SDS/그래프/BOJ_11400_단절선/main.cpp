/* BOJ_11400 단절선 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAXV = 100000;

int V, E, A, B, n = 0;
vector<int> e[MAXV + 1];
int parent[MAXV + 1];
int order[MAXV + 1];
vector<pair<int, int>> ans;

int dfs(int v);

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
	dfs(1);

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}


int dfs(int v) { // return low
	order[v] = ++n;
	int now_low = n;
	
	for (vector<int>::iterator it = e[v].begin(); it != e[v].end(); it++) {
		if (*it == parent[v]) continue;

		if (order[*it] == 0) { // undiscovered
			parent[*it] = v;
			int low = dfs(*it);
			
			if (low > order[v]) {
				int a = v;
				int b = *it;
				if (a > b) swap(a, b);
				ans.push_back(make_pair(a, b));
			}
			now_low = min(now_low, low);
		}
		else {
			now_low = min(now_low, order[*it]);
		}
	}
	return now_low;
}