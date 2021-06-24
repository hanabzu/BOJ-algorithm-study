/* hanabzu */
/* BOJ_1931 회의실 배정 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> table;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, s, e, p, result = 1;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		table.push_back(pair<int, int>(e, s));
	}
	sort(table.begin(), table.end());

	p = table.begin()->first;

	for (vector<pair<int, int>>::iterator iter = ++table.begin(); iter != table.end(); iter++) {
		if (iter->second >= p) {
			result++;
			p = iter->first;
		}
	}

	cout << result;
	return 0;
}