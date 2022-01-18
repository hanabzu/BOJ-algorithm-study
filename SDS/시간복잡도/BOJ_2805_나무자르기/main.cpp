/* BOJ_2805 나무 자르기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#define MAXN 1000000
using namespace std;

int w[MAXN];
int N, M, l = 0, r = 0, m;

bool w_sum(int m);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> w[i];
		r = max(r, w[i]);
	}


	while (l + 1 < r) {
		m = l + ((r - l) >> 1);
		if (w_sum(m)) {
			l = m;
		}
		else {
			r = m;
		}
	}

	cout << l;

	return 0;
}

bool w_sum(int m) {
	long long s = 0;
	for (int i = 0; i < N; i++){
		s += max(0, w[i] - m);
	}
	if (s >= M) {
		return true;
	}
	return false;
}