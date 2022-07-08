/* BOJ_17471 게리맨더링 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 10;
const int INF = 987654321;
int N, city[MAXN + 1], Acnt = 0, Bcnt, A, B, Apop, total, ans = INF;
vector<int> e[MAXN + 1];
bool team[MAXN + 1], uni[MAXN + 1], visit[MAXN + 1];

void dfs(int p);
void combi(int p);
void gerry();
void get_team(int p, bool flag, int& T);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> city[i];
		total += city[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> A;
		for (int j = 0; j < A; j++) {
			cin >> B;
			e[i].push_back(B);
		}
	}

	uni[1] = true;
	dfs(1);

	combi(1);

	cout << ((ans == INF) ? -1 : ans);

	return 0;
}

void dfs(int p) {
	for (int i = 0; i < e[p].size(); i++) {
		int& np = e[p][i];

		if (uni[np]) continue;
		uni[np] = true;
		dfs(np);
	}
}

void combi(int p) {
	if (p > N) {
		if(Acnt > 0) gerry();
		return;
	}

	combi(p + 1);

	if (uni[p]) {
		team[p] = true;
		Acnt++;
		Apop += city[p];
		combi(p + 1);
		team[p] = false;
		Acnt--;
		Apop -= city[p];
	}
}

void gerry() {
	memset(visit, false, sizeof visit);
	Bcnt = N - Acnt;
	A = B = 0;
	for (int i = 1; i <= N; i++) {
		if (team[i] == true) {
			get_team(i, true, A);
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (team[i] == false) {
			get_team(i, false, B);
			break;
		}
	}

	if (A != Acnt || B != Bcnt) return;

	ans = min(ans, abs(total - (Apop << 1)));
}

void get_team(int p, bool flag, int& T) {
	visit[p] = true;
	T++;

	for (int i = 0; i < e[p].size(); i++) {
		int& np = e[p][i];

		if (team[np] != flag || visit[np]) continue;

		get_team(np, flag, T);
	}
}