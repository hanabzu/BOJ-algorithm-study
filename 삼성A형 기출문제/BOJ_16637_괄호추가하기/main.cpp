/* BOJ_16637 괄호 추가하기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 21;
const int INF = 987654321;
int N, ans = -INF;
string S;
bool isParen[MAXN];

void dfs(int p);
void cal();
int inst(int lhs, char op, int rhs);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	dfs(1);

	cout << ans;
	return 0;
}

void dfs(int p) {
	if (p > N) {
		cal();
		return;
	}

	dfs(p + 2);

	if (p != 1 && !isParen[p - 2]) {
		isParen[p] = true;
		dfs(p + 2);
		isParen[p] = false;
	}
}

void cal() {
	int p = 1, res = S[0] - '0';

	while (p < N) {
		if (p + 2 < N &&isParen[p + 2] == true) {
			res = inst(res, S[p], inst(S[p + 1] - '0', S[p + 2], S[p + 3] - '0'));
			p += 4;
		}
		else {
			res = inst(res, S[p], S[p + 1] - '0');
			p += 2;
		}

	}
	ans = max(ans, res);
}

int inst(int lhs, char op, int rhs) {
	switch (op) {
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '*':
		return lhs * rhs;
	}
}