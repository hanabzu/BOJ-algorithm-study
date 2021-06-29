/* hanabzu */
/* BOJ_18870 좌표 압축 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, n;
vector<int> nums, sorted_nums;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		nums.push_back(n);
		s.insert(n);
	}

	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		sorted_nums.push_back(*iter);
	}

 	for (int i = 0; i < N; i++) {
		vector<int>::iterator iter = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]);
		cout << iter - sorted_nums.begin() << ' ';
	}

	return 0;
}
