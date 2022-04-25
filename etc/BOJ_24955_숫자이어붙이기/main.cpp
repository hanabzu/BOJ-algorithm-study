/* BOJ_24955 숫자 이어 붙이기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1001;
const int MOD = 1000000007;

int N, Q, a, b;
string A[MAXN];
vector<int> e[MAXN];
bool visit[MAXN];
int depth[MAXN];
int parent[MAXN];

long long mod(string& num);
void dfs(int p);
void LCA();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1);
	for (int i = 0; i < Q; i++) {
		LCA();
	}

	return 0;
}


void LCA() {
	string sx = "", sy = "";
	int x, y;
	int diff_depth = 0;
	cin >> x >> y;

	if (depth[x] > depth[y]) {
		diff_depth = depth[x] - depth[y];
		while (diff_depth--) {
			sx = sx + A[x];
			x = parent[x];
		}
	}
	else {
		diff_depth = depth[y] - depth[x];
		while (diff_depth--) {
			sy = A[y] + sy;
			y = parent[y];
		}
	}

	while (x != y) {
		sx = sx + A[x];
		x = parent[x];

		sy = A[y] + sy;
		y = parent[y];
	}
	sx = sx + A[x] + sy;

	cout << mod(sx) << '\n';
}

long long mod(string& n) {
	long long res = 0;
	for (int i = 0; i < n.size(); i++) {
		res = (res * 10 + (n[i] - '0')) % MOD;
	}
	return res;
}

void dfs(int p) {
	visit[p] = true;
	for (vector<int>::iterator it = e[p].begin(); it != e[p].end(); it++) {
		if (!visit[*it]) {
			parent[*it] = p;
			depth[*it] = depth[p] + 1;
			dfs(*it);
		}
	}
}