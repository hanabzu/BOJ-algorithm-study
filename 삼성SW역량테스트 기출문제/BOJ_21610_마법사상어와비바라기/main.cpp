/* BOJ_21610 마법사 상어와 비바라기 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN = 50;
const int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };

struct Cloud {
	int r, c;
	Cloud() : r(0), c(0) {}
	Cloud(int r, int c) : r(r), c(c) {}
};

int N, M, A[MAXN][MAXN], d, s, ans = 0;
vector<Cloud> v;
bool visit[MAXN][MAXN];

void move();
void duplicate();
void make_cloud();
void init();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	init();
	while (M--) {
		cin >> d >> s;
		d--;
		move();
		v.clear();
		duplicate();
		make_cloud();
		memset(visit, 0, sizeof visit);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += A[i][j];
		}
	}

	cout << ans;
	return 0;
}

void move() {
	for (int i = 0; i < v.size(); i++) {
		Cloud& cloud = v[i];

		cloud.r = (cloud.r + (dx[d] * s) % N + N) % N;
		cloud.c = (cloud.c + (dy[d] * s) % N + N) % N;
		A[cloud.r][cloud.c]++;
		visit[cloud.r][cloud.c] = true;
	}
}

void duplicate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) continue;

			int cnt = 0;

			for (int k = 1; k < 8; k += 2) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (ni < 0 || ni >= N || nj < 0 || nj >= N || A[ni][nj] == 0) continue;

				cnt++;
			}

			A[i][j] += cnt;
		}
	}
}

void make_cloud() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] || A[i][j] < 2) continue;

			A[i][j] -= 2;
			v.push_back(Cloud(i, j));
		}
	}
}

void init() {
	int r[4] = { N - 1, N - 1, N - 2, N - 2 };
	int c[4] = { 0, 1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		v.push_back(Cloud(r[i], c[i]));
	}
}