/* BOJ_20040 사이클 게임 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 500000;

int n, m, a, b;
int parent[MAXN];

void uni(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i;
			return 0;
		}
		uni(a, b);
	}
	cout << 0;
	return 0;
}

void uni(int a, int b) {
	parent[find(a)] = find(b);
}

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}