/* BOJ_14889 스타트와 링크 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;
enum {
	YET, A, B
};
const int MAXN = 20;
const int INF = 987654321;
int N, S[MAXN][MAXN];
int teamA = 0, teamB = 0, cntA = 0, cntB = 0, ans = INF;
int team[MAXN];

void dfs(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	dfs(0);

	cout << ans;

	return 0;
}

void dfs(int p) {
	if (cntA > (N >> 1) || cntB > (N >> 1)) {
		return;
	}

	if (p == N) {
		if (cntA == cntB) {
			teamA = teamB = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (team[i] == team[j]) {
						if (team[i] == A) {
							teamA += S[i][j];
						}
						if (team[i] == B) {
							teamB += S[i][j];
						}
					}
				}
			}
			ans = min(ans, abs(teamA - teamB));
		}
		return;
	}

	team[p] = A;
	cntA++;
	dfs(p + 1);
	cntA--;


	team[p] = B;
	cntB++;
	dfs(p + 1);
	cntB--;
}