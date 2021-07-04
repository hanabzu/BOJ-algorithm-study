/* hanabzu* /
/* BOJ_11725 트리의 부모 찾기 */

#include <iostream>
#include <vector>
using namespace std;

int N, u, v;
int parent[100001] = { 0, };
vector<int> e[100001];

void find_parent(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	parent[1] = -1;
	find_parent(1);
	
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}

void find_parent(int n) {
	for (vector<int>::iterator it = e[n].begin(); it != e[n].end(); it++) {
		if (parent[*it] == 0) {
			parent[*it] = n;
		}
		if (*it != parent[n]) {
			find_parent(*it);
		}
	}
}