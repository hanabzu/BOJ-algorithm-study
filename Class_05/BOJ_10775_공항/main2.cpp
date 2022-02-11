/* BOJ_10775 공항 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXG = 100000;

int parent[MAXG + 1];
int G, P, g;

int find(int a);
void uni(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G >> P;
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	int i;
	for (i = 0; i < P; i++) {
		cin >> g;
		int u = find(g);
		if (u == 0) {
			break;
		}
		uni(u, u - 1);
	}

	cout << i;
	return 0;
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void uni(int a, int b) {
	parent[find(a)] = find(b);
}