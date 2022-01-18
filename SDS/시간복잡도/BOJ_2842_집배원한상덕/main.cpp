/* BOJ_2842 집배원 한상덕 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <string.h>
#include "limits.h"

#define MAXH 1000000
#define MAXN 50
using namespace std;

typedef pair<int, int> pii;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

string s;
int N, t[MAXN][MAXN], h[MAXN][MAXN];
int h_min = MAXH, h_max = 0;
vector<pii> k;
set<int> hs;
vector<int> hv;
pii p;

bool bfs(int lb, int ub);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			switch (s[j]) {
			case 'P':
				t[i][j] = 2; 
				p = make_pair(i, j); break;
			case 'K':
				t[i][j] = 1;
				k.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> h[i][j];
			if (t[i][j] == 1 || t[i][j] == 2) {
				h_max = max(h_max, h[i][j]);
				h_min = min(h_min, h[i][j]);
			}
			hs.insert(h[i][j]);
		}
	}
	hv = vector<int>(hs.begin(), hs.end());
	int ridx, lidx;

	for (int i = 0; i < (int)hv.size(); i++) {
		if (hv[i] == h_min) {
			lidx = i;
		}
		if (hv[i] == h_max) {
			ridx = i;
			break;
		}
	}

	int l = 0, r = ridx;
	int ans = INT_MAX;
	while (r < (int)hv.size()) {
		while (l <= lidx) {
			if (!bfs(hv[l], hv[r])) break;
			ans = min(ans, hv[r] - hv[l]);
			l++;
		}
		r++;
	}

	cout << ans;

	return 0;
}

bool bfs(int lb, int ub) {
	int k_num = 0;
	queue<pii> q;
	bool visit[MAXN][MAXN];
	memset(visit, 0, sizeof(visit));
	q.push(p);
	visit[p.first][p.second] = true;

	while (!q.empty()) {
		pii u = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int new_x = u.first + dx[i];
			int new_y = u.second + dy[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) { // boundary check
				if (!visit[new_x][new_y] && h[new_x][new_y] >=lb && h[new_x][new_y] <=ub) { // validity check
					q.push(make_pair(new_x, new_y));
					if (t[new_x][new_y] == 1) k_num++;
				}
				visit[new_x][new_y] = true;
			}
		}
		if (k_num == k.size()) return true;
	}
	return false;
}