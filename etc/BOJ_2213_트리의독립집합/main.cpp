/* BOJ_2213 트리의 독립집합 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10000;
int N, a, b, W[MAXN + 1], dp[MAXN + 1][2];
vector<int> e[MAXN + 1], v;
bool isIn[MAXN + 1];

int get_max(int n, int parent, int isSet);
void dfs(int n, int parent);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	fill(&dp[0][0], &dp[MAXN][2], -1);

	for (int i = 1; i <= N; i++) {
		cin >> W[i];
	}

	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	cout << max(get_max(1, 0, 0), get_max(1, 0, 1)) << '\n';

	dfs(1, 0);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}


	return 0;
}

void dfs(int n, int parent) {
	if (dp[n][1] > dp[n][0] && isIn[parent] == false) {
		v.push_back(n);
		isIn[n] = true;
	}

	for (int i = 0; i < e[n].size(); i++) {
		if (e[n][i] == parent) continue;
		
		dfs(e[n][i], n);
	}
}

int get_max(int n, int parent, int isSet) {
	if (dp[n][isSet] >= 0) return dp[n][isSet];

	if (isSet == 0) { // not in set
		dp[n][isSet] = 0;
	}
	else { // in set
		dp[n][isSet] = W[n];
	}
	
	for (int i = 0; i < e[n].size(); i++) {
		if (e[n][i] == parent) continue;
		if (isSet == 0) { // not in set
			dp[n][isSet] += max(get_max(e[n][i], n, 0), get_max(e[n][i], n, 1));
		}
		else { // in set
			dp[n][isSet] += get_max(e[n][i], n, 0);
		}
	}
	return dp[n][isSet];
}