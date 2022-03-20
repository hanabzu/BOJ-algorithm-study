/* BOJ_5568 카드 놓기 */
/* hanabzu */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define MAXN 10
using namespace std;
int n, k;
set<string> s;
string cards[MAXN];
bool visit[MAXN];

void dfs(string str, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	dfs("", 0);

	cout << s.size();

	return 0;
}

void dfs(string str, int depth) {
	if (depth == k) {
		s.insert(str);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(str + cards[i], depth + 1);
			visit[i] = false;
		}
	}
}