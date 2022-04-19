/* BOJ_19238 스타트 택시 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
	int x, y;
	Pos() {}
	Pos(int x, int y) :x(x), y(y) {}
	bool operator<(const Pos& rhs) const {
		if (x == rhs.x) return y < rhs.y;
		return x < rhs.x;
	}
};

const int MAXN = 20;
const int dx[4] = { -1,0,0,1 };
const int dy[4] = { 0,-1,1,0 };
int N, M, F, x, y, cnt = 0;
int pmap[MAXN][MAXN], wmap[MAXN][MAXN];
bool visit[MAXN][MAXN];
Pos taxi;
Pos passenger[MAXN * MAXN + 1];
queue<Pos> q;
vector<Pos> candi;

bool find();
bool work(int sx, int sy);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> F;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> wmap[i][j];
			if (wmap[i][j] == 1) wmap[i][j] = -1;
		}
	}

	memcpy(pmap, wmap, sizeof(pmap));

	cin >> taxi.x >> taxi.y;
	taxi.x--; taxi.y--;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> passenger[i].x >> passenger[i].y;
		pmap[x-1][y-1] = i;
		passenger[i].x--; passenger[i].y--;
	}

	while (find());
	cout << F;
	return 0;
}

bool find() {
	if (cnt == M) return false;

	memset(visit, false, sizeof(visit));
	q = queue<Pos>();
	candi = vector<Pos>();
	q.push(taxi);
	visit[taxi.x][taxi.y] = true;
	if (pmap[taxi.x][taxi.y] > 0) {
		return work(taxi.x, taxi.y);
	}
	int cost = 0, q_size = 1;
	while (!q.empty()) {
		Pos u = q.front();
		q.pop();
		q_size--;

		// move
		for (int i = 0; i < 4; i++) {
			int nx = u.x + dx[i];
			int ny = u.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || 
				pmap[nx][ny] == -1 || visit[nx][ny]) continue;
			
			// meet passenger
			if (pmap[nx][ny] > 0) {
				candi.push_back(Pos(nx,ny));
			}

			visit[nx][ny] = true;
			q.push(Pos(nx, ny));
		}

		if (q_size != 0) continue;

		q_size = q.size();
		cost++;
		if (!candi.empty()) {
			sort(candi.begin(), candi.end());
			F -= cost;
			if (F < 0) {
				F = -1;
				return false;
			}
			
			return work(candi[0].x, candi[0].y);
		}
	}

	F = -1;
	return false;
}

bool work(int sx, int sy) {
	memset(visit, false, sizeof(visit));
	q = queue<Pos>();
	Pos e = passenger[pmap[sx][sy]];
	wmap[e.x][e.y] = 1; // end point
	pmap[sx][sy] = 0;
	q.push(Pos(sx, sy));
	int cost = 0, q_size = 1;
	while (!q.empty()) {
		Pos u = q.front();
		q.pop();
		q_size--;

		if (wmap[u.x][u.y] == 1) {
			F -= cost;
			if (F < 0) {
				F = -1;
				return false;
			}
			F += (cost << 1);
			taxi = Pos(u.x, u.y);
			wmap[u.x][u.y] = 0;
			cnt++;
			return true;
		}

		// move
		for (int i = 0; i < 4; i++) {
			int nx = u.x + dx[i];
			int ny = u.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N ||
				wmap[nx][ny] == -1 || visit[nx][ny]) continue;

			visit[nx][ny] = true;
			q.push(Pos(nx, ny));
		}

		if (q_size != 0) continue;

		q_size = q.size();
		cost++;
	}

	F = -1;
	return false;
}