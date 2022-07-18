/* BOJ_17281 야구 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 50;

int N, order[9], A[9][MAXN], ans;
bool visit[9], base[3];
void game();
void dfs(int p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> A[j][i];
		}
	}

	order[3] = 0;
	visit[0] = true;
	
	dfs(0);

	cout << ans;
	return 0;
}
void game() {
	int out_cnt, p = 0, player, score = 0, cnt;

	for (int inning = 0; inning < N; inning++) {
		memset(base, false, 3);
		out_cnt = 0;
		while (out_cnt < 3) {
			player = order[p];
			switch (A[player][inning]) {
			case 1:
			case 2:
			case 3:
				cnt = A[player][inning];
				for (int i = 2; i >= 0; i--) {
					if (base[i]) {
						base[i] = false;
						if (i + cnt < 3) {
							base[i + cnt] = true;
						}
						else {
							score++;
						}
					}
				}
				base[cnt - 1] = true;
				break;
			case 4:
				for (int i = 0; i < 3; i++) {
					if (base[i]) {
						base[i] = false;
						score++;
					}
				}
				score++;
				break;
			default: // out
				out_cnt++;
			}
			p = (p + 1) % 9;
		}
	}

	ans = max(ans, score);
}

void dfs(int p) {
	if (p == 9) {
		game();
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (visit[i]) continue;

		visit[i] = true;
		order[p] = i;
		dfs(p + (p == 2 ? 2 : 1));
		visit[i] = false;
	}
}
