/* BOJ_15685 드래곤 커브 */
/* hanabzu */

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 101;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { 1, 0, -1, 0 };

int map[MAXN + 1][MAXN + 1];
int N, x, y, d, g;

void draw();
int count();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		draw();
	}

	cout << count();

	return 0;
}

void draw() {
	cin >> y >> x >> d >> g;
	vector<int> v;

	map[x][y] = 1;
	x = x + dx[d];
	y = y + dy[d];
	map[x][y] = 1;
	v.push_back(d);

	for (int i = 1; i <= g; i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			int nd = ((v[j]) + 1) % 4;
			x = x + dx[nd];
			y = y + dy[nd];
			map[x][y] = 1;
			v.push_back(nd);
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) cnt++;
		}
	}
	return cnt;
}