/* hanabzu */
/* BOJ_15650 N과 M (2) */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> v, x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < N; i++) {
		if (i < M) {
			x.push_back(1);
		}
		else {
			x.push_back(0);
		}
	}

	do {
		for (int i = 0; i < N; i++) {
			if (x[i] == 1) {
				cout << v[i] << ' ';
			}
		}
		cout << '\n';

	} while (prev_permutation(x.begin(), x.end()));

	return 0;
}