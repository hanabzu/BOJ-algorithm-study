/* BOJ_7453 합이 0인 네 정수 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 4000
using namespace std;

int N;
long long n[4][MAXN], cnt = 0;
vector<long long> ab, cd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> n[j][i];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ab.push_back(n[0][i] + n[1][j]);
			cd.push_back(n[2][i] + n[3][j]);
		}
	}

	sort(ab.begin(), ab.end()); // cache hit
	sort(cd.begin(), cd.end());

	for (vector<long long>::iterator it = ab.begin(); it != ab.end(); it++) {
		cnt += upper_bound(cd.begin(), cd.end(), -(*it)) - lower_bound(cd.begin(), cd.end(), -(*it));
	}

	cout << cnt;
	return 0;
}