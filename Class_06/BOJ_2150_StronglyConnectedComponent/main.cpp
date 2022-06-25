/* BOJ_2150 Strongly Connected Component */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 10000;

int V, E, a, b, idx, par[MAXV + 1], stack[MAXV + 1], top = -1;
vector<int> e[MAXV + 1];
vector<vector<int>> scc;
bool visit[MAXV + 1];

int dfs(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		e[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (par[i] == 0) {
			dfs(i);
		}
	}
	sort(scc.begin(), scc.end());
	cout << scc.size() << '\n';
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			cout << scc[i][j] << ' ';
		}
		cout << "-1\n";
	}

	return 0;
}

int dfs(int v) {
	par[v] = ++idx;
	stack[++top] = v;

	int parent = par[v];

	for (int i = 0; i < e[v].size(); i++) {
		if (par[e[v][i]] == 0) {
			parent = min(parent, dfs(e[v][i]));
		}
		else if (!visit[e[v][i]]) {
			parent = min(parent, par[e[v][i]]);
		}
	}

	if (parent == par[v]) {
		vector<int> tmp;
		while (true) {
			tmp.push_back(stack[top]);
			visit[stack[top--]] = true;
			if (tmp[tmp.size()-1] == v) break;
		}
		sort(tmp.begin(), tmp.end());
		scc.push_back(tmp);
	}
	
	return parent;
}