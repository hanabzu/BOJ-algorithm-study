/* BOJ_9328 열쇠 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

const int MAXH = 100;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

long long keys;
int T, H, W, ans;
string map[MAXH], k;
bool visit[MAXH][MAXH];
vector<pair<int, int>> v[26];
queue<pair<int, int>> q;

void solution();
void look_up(int r, int c);
void unlock(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		solution();
	}

	return 0;
}

void solution() {
	// init
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < 26; i++) {
		v[i].clear();
	}
	keys = 0;
	ans = 0;


	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}
	cin >> k;
	if (k[0] != '0') {
		for (int i = 0; i < k.size(); i++) {
			keys = keys | (1ll << (k[i] - 'a'));
		}
	}

	for (int i = 0; i < H; i++) {
		look_up(i, 0);
		look_up(i, W - 1);
	}
	for (int i = 1; i < W - 1; i++) {
		look_up(0, i);
		look_up(H - 1, i);
	}


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			look_up(nx, ny);
		}
	}

	cout << ans << '\n';
}

void look_up(int r, int c) {
	if (r < 0 || r >= H || c < 0 || c >= W) return;

	if (visit[r][c]) return;

	visit[r][c] = true;

	if (map[r][c] == '*') {
		return;
	}
	else if (map[r][c] == '$') {
		ans++;
	}
	else if (map[r][c] >= 'a' && map[r][c] <= 'z') {
		long long b = (1ll << (map[r][c] - 'a'));
		if ((keys & b) == 0) { // new key
			keys |= b;
			unlock(map[r][c] - 'a');
		}
	}
	else if (map[r][c] >= 'A' && map[r][c] <= 'Z') { // + 32 to small
		long long b = (1ll << (map[r][c] - 'A'));
		if ((keys & b) == 0) { // no key
			v[map[r][c] - 'A'].push_back(make_pair(r, c));
			return;
		}
	}
	q.push(make_pair(r, c));
}

void unlock(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		q.push(v[idx][i]);
	}
}