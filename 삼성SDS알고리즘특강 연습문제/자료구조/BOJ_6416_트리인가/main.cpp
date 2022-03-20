/* BOJ_ 6416 트리인가? */
/* hanabzu */

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define MAXN 100
using namespace std;

queue<int> q;
set<int> s;
vector<int> e[MAXN];
int isChild[MAXN];
bool visit[MAXN];
int k = 1, u, v;

void initiate();
bool solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (solution());

	return 0;
}

void initiate() {
	q = queue<int>();
	s = set<int>();
	for (int i = 0; i < MAXN; i++) {
		e[i] = vector<int>();
		isChild[i] = 0;
		visit[i] = false;
	}
}

bool solution() {
	bool isTree = true;
	initiate();

	while (1) {
		cin >> u >> v;
		if (u == 0) break;
		if (u == -1) return false;

		s.insert(u);
		s.insert(v);
		e[u].push_back(v);
		isChild[v]++;
	}

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		if (isChild[*it] > 1) {
			isTree = false;
		}
		if (!isChild[*it]) {
			q.push(*it);
			visit[*it] = true;
		}
	}
	if (q.size() != 1) {
		isTree = false;
	}
	else {
		while (!q.empty()) { // bfs
			int u = q.front();
			q.pop();
			for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
				if (visit[*it]) {
					isTree = false;
				}
				else {
					visit[*it] = true;
					q.push(*it);
				}
			}
		}
		for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
			if (!visit[*it]) {
				isTree = false;
			}
		}
	}

	if (s.size() == 0) {
		isTree = true;
	}

	cout << "Case " << k++ << " is" << (isTree ? "" : " not") << " a tree.\n";
	return true;
}
