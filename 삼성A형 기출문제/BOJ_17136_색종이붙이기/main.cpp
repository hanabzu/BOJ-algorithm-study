/* BOJ_17136 색종이 붙이기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 10;

int map[MAXN][MAXN], paper[6], ans = 30, paper_cnt = 0, one_cnt = 0;
bool visit[MAXN][MAXN];

void dfs(int p);
bool cover(int r, int c, int paper_size);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) one_cnt++;
		}
	}

	if (one_cnt == 0) {
		cout << 0;
		return 0;
	}

	dfs(0);

	cout << (ans == 30 ? -1 : ans);

	return 0;
}


void dfs(int p) {
	if (p >= MAXN * MAXN) return;

	int r = p / MAXN;
	int c = p % MAXN;

	bool mem_visit[MAXN][MAXN];
	int mem_one_cnt = one_cnt;
	memcpy(mem_visit, visit, sizeof visit);

	if (map[r][c] == 1 && !visit[r][c]) {
		for (int i = 5; i > 0; i--) {
			if (cover(r, c, i)) {
				if (one_cnt == 0) {
					ans = min(ans, paper_cnt);
				}
				else {
					dfs(p + 1);
				}
				paper_cnt--;
				one_cnt = mem_one_cnt;
				memcpy(visit, mem_visit, sizeof visit);
				paper[i]--;
			}
		}
	}
	else {
		dfs(p + 1);
	}

}

bool cover(int r, int c, int paper_size) {
	if (paper[paper_size] >= 5) return false;

	for (int i = r; i < r + paper_size; i++) {
		for (int j = c; j < c + paper_size; j++) {
			if (i < 0 || i >= MAXN || j < 0 || j >= MAXN || visit[i][j] || map[i][j] == 0) {
				return false; // cannot cover
			}
		}
	}

	// coverable
	paper[paper_size]++;
	one_cnt -= paper_size * paper_size;
	paper_cnt++;
	for (int i = r; i < r + paper_size; i++) {
		for (int j = c; j < c + paper_size; j++) {
			visit[i][j] = true;
		}
	}
	return true;
}