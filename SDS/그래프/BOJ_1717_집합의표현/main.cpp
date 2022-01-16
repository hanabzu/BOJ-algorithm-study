/* BOJ_1717 집합의 표현 */
/* hanabzu */

#include <iostream>
#define MAXV 1000000

using namespace std;

int parent[MAXV+1];
int n, m, f, a, b;

void initialize();
void union_find(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	initialize();
	for (int i = 0; i < m; ++i) {
		cin >> f >> a >> b;
		if (f) {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			union_find(a, b);
		}
	}

	return 0;
}

void initialize() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
void union_find(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);
	parent[aRoot] = bRoot;
}
int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}