/* BOJ_12015 가장 긴 증가하는 부분 수열 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000000;

int N;
int n[MAXN + 1];
int d[MAXN + 1];
vector<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}

	x.push_back(0);
	for (int i = 1; i <= N; i++) {
		int idx = lower_bound(x.begin(), x.end(), n[i]) - x.begin();
		if (idx == x.size()) {
			x.push_back(n[i]);
		}
		else {
			x[idx] = n[i];
		}
		d[i] = x.size() - 1;
	}
	cout << d[N];

	return 0;
}