/* BOJ_15664 N과 M (10) */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#define MAXA 10000
using namespace std;

int N, M, a;
int v[MAXA + 1];
int table[8];
vector<int> n;
void dfs(int p, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		if (v[a]) {
			v[a]++;
		}
		else {
			n.push_back(a);
			v[a]++;
		}
	}
	sort(n.begin(), n.end());

	dfs(0, 0);
	return 0;
}

void dfs(int p, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << table[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = p; i < n.size(); i++) {
		if (v[n[i]] > 0) {
			v[n[i]]--;
			table[depth] = n[i];
			dfs(i, depth + 1);
			v[n[i]]++;
		}
	}
}