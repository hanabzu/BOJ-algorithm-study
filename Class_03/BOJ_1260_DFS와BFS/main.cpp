/* hanabzu */
/* BOJ_1260 DFS와 BFS */

#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class node {
public:
	short color = 0; // white
};

void DFS(node* v, map<short, set<short>>& e, short s);
void BFS(node* v, map<short, set<short>> e, short s);
short n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, v, w;
	cin >> n >> m >> s;

	node* vertices = new node[n];
	map<short, set<short>> edge;

	for (int i = 0; i < m; i++) { // adjacent list
		cin >> v >> w;
		v--;
		w--;
		if(!edge.count(v)){
			edge[v] = set<short>();
		}
		edge[v].insert(w);
		if (!edge.count(w))
			edge[w] = set<short>();
		edge[w].insert(v);
	}
	map<short, set<short>> & ref_edge = edge;
	DFS(vertices, ref_edge, --s); // pass by reference
	cout << '\n';
	BFS(vertices, edge, s);

	delete[] vertices;
	return 0;
}

void DFS(node* v, map<short, set<short>> & e, short s) {
	v[s].color = 1; // gray
	cout << (s + 1) << ' ';
	for (set<short>::iterator iter = e[s].begin(); iter != e[s].end(); iter++) {
		if (v[*iter].color == 0) {
			DFS(v, e, *iter);
		}
	}
	v[s].color = 2; // black
}

void BFS(node* v, map<short, set<short>> e, short s) {
	for (int i = 0; i < n; i++) {
		v[i].color = 0;
	}
	cout << (s + 1) << ' ';
	v[s].color = 1;
	queue<short> q;
	q.push(s);
	while (!q.empty()) {
		short u = q.front();
		q.pop();
		for (set<short>::iterator iter = e[u].begin(); iter != e[u].end(); iter++) {
			if (v[*iter].color == 0) {
				cout << (*iter + 1) << ' ';
				v[*iter].color = 1;
				q.push(*iter);
			}
		}
		v[u].color = 2;
	}
}