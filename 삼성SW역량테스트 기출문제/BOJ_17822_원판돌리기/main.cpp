/* BOJ_17822 원판 돌리기 */
/* hanabzu */

#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 50;
const int MAXM = 50;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int N, M, T;
int num[MAXN][MAXM], x, d, k, ans = 0;

void turn();
void spin(int row);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num[i][j];
		}
	}

	while (T--) {
		turn();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += num[i][j];
		}
	}
	cout << (int)ans;

	return 0;
}


void turn() {
	cin >> x >> d >> k;
	if (d == 1) {
		k = M - k;
	}
	for (int row = x; row <= N; row += x) {
		row--;
		spin(row);
		row++;
	}

	bool check[MAXN][MAXM] = { 0, }, isDeleted = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (num[i][j] == 0) continue;
			for (int d = 0; d < 4; d++) {
				int ni = i + dx[d];
				int nj = (j + dy[d] + M) % M;
				if (ni < 0 || ni >= N) continue;

				if (num[i][j] == num[ni][nj]) {
					check[i][j] = true;
					isDeleted = true;
				}
			}
		}
	}
	if (isDeleted) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == true) {
					num[i][j] = 0;
				}
			}
		}
	}
	else {
		double s = 0.0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (num[i][j] != 0) {
					s += num[i][j];
					cnt++;
				}
			}
		}

		s /= (double)cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (num[i][j] != 0) {
					if (num[i][j] - s > 0) {
						num[i][j]--;
					}
					else if (num[i][j] - s < 0) {
						num[i][j]++;
					}
				}
			}
		}
	}
}


void spin(int row) {
	int tmp[MAXM] = { 0, };
	for (int i = 0; i < M; i++) {
		tmp[(i + k + M) % M] = num[row][i];
	}
	memcpy(num[row], tmp, sizeof tmp);
}