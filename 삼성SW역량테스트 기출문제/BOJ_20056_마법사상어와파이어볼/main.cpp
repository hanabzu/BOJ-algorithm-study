/* BOJ_20056 마법사 상어와 파이어볼 */
/* hanabzu */

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50;
const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

struct Fireball {
	int m, s, d;
	Fireball() : m(0), s(0), d(0) {}
	Fireball(int m, int s, int d) : m(m), s(s), d(d) {}
};

int N, M, K, r, c, m, s, d, page = 0;
vector<Fireball> map[2][MAXN][MAXN];

void move();
void div();
int sum();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		map[0][r - 1][c - 1].push_back(Fireball(m, s, d));
	}

	for (int i = 1; i <= K; i++) {
		move();
		page = (i & 1);
		div();
	}

	cout << sum();
	return 0;
}

void move() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[page][i][j].empty()) continue;

			for (int p = 0; p < map[page][i][j].size(); p++) {
				Fireball& fb = map[page][i][j][p];

				int ni = (i + dx[fb.d] * (fb.s % N) + N) % N;
				int nj = (j + dy[fb.d] * (fb.s % N) + N) % N;

				map[(page + 1) & 1][ni][nj].push_back(fb);
			}
			map[page][i][j].clear();
		}
	}
}

void div() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[page][i][j].size() < 2) continue;

			int m_sum = map[page][i][j][0].m;
			int s_sum = map[page][i][j][0].s;
			int d_flag = 0;

			for (int p = 1; p < map[page][i][j].size(); p++) {
				m_sum += map[page][i][j][p].m;
				s_sum += map[page][i][j][p].s;
				if ((map[page][i][j][p].d & 1) != (map[page][i][j][0].d & 1)) {
					d_flag = 1;
				}
			}

			m_sum /= 5;
			s_sum /= map[page][i][j].size();

			map[page][i][j].clear();

			if (m_sum == 0) continue;
			for (int c = 0; c < 4; c++) {
				map[page][i][j].push_back(Fireball(m_sum, s_sum, d_flag + (c << 1)));
			}
		}
	}
}

int sum() {
	int s = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[page][i][j].empty()) continue;

			for (int p = 0; p < map[page][i][j].size(); p++) {
				s += map[page][i][j][p].m;
			}
		}
	}
	return s;
}