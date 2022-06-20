/* BOJ_2628 종이자르기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K, d, n, rmax = 0, cmax = 0;
vector<int> v[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> d >> n;
		v[d].push_back(n);
	}
	v[0].push_back(0);
	v[1].push_back(0);
	v[0].push_back(M);
	v[1].push_back(N);
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	for (int i = 1; i < v[0].size(); i++) {
		rmax = max(rmax, v[0][i] - v[0][i - 1]);
	}

	for (int i = 1; i < v[1].size(); i++) {
		cmax = max(cmax, v[1][i] - v[1][i - 1]);
	}

	cout << rmax * cmax;
	return 0;
}