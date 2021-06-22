/* hanabzu */
/* BOJ_2606 바이러스 */

#include <iostream>
#include <limits.h>
#include <vector>
#include <map>
using namespace std;

class node {
public:
	int color = 0; // white
	int d = INT_MAX;
	int p = NULL;
};

void DFS(node* v, map<int, vector<int>> e, int s);

int result = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v, w;
	cin >> n >> m;

	node* vertices = new node[n];
	map<int, vector<int>> edge;

	for (int i = 0; i < m; i++) { // adjacent list
		cin >> v >> w;
		v--;
		w--;
		if (edge.count(v))
			edge[v].push_back(w);
			
		else {
			edge[v] = vector<int>(1,w);
		}
		if (edge.count(w))
			edge[w].push_back(v);
		else {
			edge[w] = vector<int>(1,v);
		}
	}

	DFS(vertices, edge, 0);

	cout << (result == -1 ? 0 : result);
	return 0;
}

void DFS(node* v, map<int, vector<int>> e, int s) {
	if (v[s].p == NULL) {
		v[s].d = 0;
	}
	else {
		v[s].d = v[v[s].p].d + 1;
	}
	v[s].color = 1; // gray
	for (int i = 0; i < e[s].size(); i++) {
		if (v[e[s][i]].color == 0){
			v[e[s][i]].p = s;
			DFS(v, e, e[s][i]);
		}
	}
	v[s].color = 2; // black
	result++;
}
