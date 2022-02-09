/* BOJ_1007 벡터 매칭 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN = 20;
const double INF = 987654321.0;

int T, N;
int x[MAXN], y[MAXN];
double sum_x = 0.0, sum_y = 0.0, ans;
void solution();
void dfs(int p, int num);

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
	sum_x = 0;
	sum_y = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		sum_x += x[i];
		sum_y += y[i];
		x[i] <<= 1;
		y[i] <<= 1;
	}
	ans = INF;
	dfs(0, 0);
	cout << fixed;
	cout.precision(7);
	cout << ans << '\n';
}

void dfs(int p, int num) {
	if (num == N>>1) {
		ans = min(ans, sqrt(sum_x * sum_x + sum_y * sum_y));
		return;
	}
	for (int i = p; i < N; i++) {
		sum_x -= x[i];
		sum_y -= y[i];
		dfs(i + 1, num + 1);
		sum_x += x[i];
		sum_y += y[i];
	}
}