/* BOJ_23288 주사위 굴리기 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 20;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { 1, 0, -1, 0 };

class Dice {
public:
	int top = 1, north = 2, east = 3, west = 4, south = 5, bot = 6;
	int d = 0, xpos = 0, ypos = 0;
	Dice() {}
	void rotate();
};

int N, M, K, num, cnt, ans = 0;
int map[MAXN][MAXN], score[MAXN][MAXN];
bool visit[MAXN][MAXN];
Dice dice;
vector<pair<int, int>> v;

void init_score();
void dfs_score(pair<int, int> p);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	init_score();

	while (K--) {
		dice.rotate();
	}

	cout << ans;

	return 0;
}


void Dice::rotate() {
	int nx = xpos + dx[d];
	int ny = ypos + dy[d];

	if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
		d = (d + 2) % 4;
		nx = xpos + dx[d];
		ny = ypos + dy[d];
	}

	Dice prev = dice;
	if (d == 0) { // east
		top = prev.west;
		west = prev.bot;
		bot = prev.east;
		east = prev.top;
	}
	else if (d == 1) { // north
		top = prev.south;
		south = prev.bot;
		bot = prev.north;
		north = prev.top;
	}
	else if (d == 2) { // west
		top = prev.east;
		east = prev.bot;
		bot = prev.west;
		west = prev.top;
	}
	else if (d == 3) { // south
		top = prev.north;
		north = prev.bot;
		bot = prev.south;
		south = prev.top;
	}

	xpos = nx;
	ypos = ny;

	ans += score[xpos][ypos];
	if (map[xpos][ypos] < bot) {
		d = (d + 3) % 4;
	}
	else if (map[xpos][ypos] > bot) {
		d = (d + 1) % 4;
	}
}

void init_score() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;

			visit[i][j] = true;
			num = map[i][j];
			cnt = 1;
			v.push_back(make_pair(i, j));
			dfs_score(v[0]);

			int s = cnt * num;
			for (int e = 0; e < v.size(); e++) {
				score[v[e].first][v[e].second] = s;
			}
			v.clear();
		}
	}

}

void dfs_score(pair<int,int> p) {
	for (int i = 0; i < 4; i++) {
		int ni = p.first + dx[i];
		int nj = p.second + dy[i];

		if (ni < 0 || ni >= N || nj < 0 || nj >= M || visit[ni][nj]) continue;

		if (map[ni][nj] == num) {
			visit[ni][nj] = true;
			cnt++;
			v.push_back(make_pair(ni, nj));
			dfs_score(*v.rbegin());
		}
	}
}