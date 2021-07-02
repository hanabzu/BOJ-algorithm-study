/* hanabzu */
/* BOJ_15652 N과 M (4) */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void perm(vector<int> v, int num, int left);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> v;
	perm(v, 1, M);

	return 0;
}

void perm(vector<int> v, int num, int left) {
	if (left != M) {
		v.push_back(num); // ignore first call
	}

	if (left == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++) {
		perm(v, i, left - 1);
	}

}