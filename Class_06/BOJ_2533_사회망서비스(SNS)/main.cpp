/* hanabzu */
/* BOJ_2533 사회망 서비스 (SNS) */

#include <iostream>
#include <vector>
using namespace std;

int N, u, v;
int parent[1000001] = { 0, };
bool white[1000001] = { 0, };
vector<int> e[1000001];

int find_min(int n);

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
	cout << find_min(1);

	return 0;
}

int find_min(int n) {
	int cost = 0;

	white[n] = 1; // it has a chance to be white

	for (vector<int>::iterator it = e[n].begin(); it != e[n].end(); it++) {
		if (parent[*it] == 0) { // first found
			parent[*it] = n;
		}
		if (*it != parent[n]) {
			cost += find_min(*it); // DFS
			if (white[n]) {
				if (white[*it]) { // any white child exists, it turns to black
					white[n] = 0;
					cost++;
				}
			}
		}
	}

	return cost;
}