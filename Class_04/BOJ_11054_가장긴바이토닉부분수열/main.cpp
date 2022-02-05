/* BOJ_1104 가장 긴 바이토닉 부분 수열 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000;

int N;
int n[MAXN + 1], rn[MAXN + 1];
int d[MAXN + 1], rd[MAXN + 1];
vector<int> x, rx;
int ans[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
		rn[N + 1 - i] = n[i];
	}

	x.push_back(0);
	rx.push_back(0);
	for (int i = 1; i <= N; i++) {
		int idx = lower_bound(x.begin(), x.end(), n[i]) - x.begin();
		int ridx = lower_bound(rx.begin(), rx.end(), rn[i]) - rx.begin();
		if (idx == x.size()) {
			x.push_back(n[i]);
		}
		else {
			x[idx] = n[i];
		}
		if (ridx == rx.size()) {
			rx.push_back(rn[i]);
		}
		else {
			rx[ridx] = rn[i];
		}
		d[i] = x.size() - 1;
		rd[i] = rx.size() - 1;
	}
	for (int i = 1; i <= N; i++) {
		ans[i] = d[i] + rd[N + 1 - i];
	}

	cout << *max_element(ans + 1, ans + N + 1) - 1;
	
	return 0;
}