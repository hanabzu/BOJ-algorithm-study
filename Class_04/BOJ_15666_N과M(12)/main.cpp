/* hanabzu */
/* BOJ_15666 N과 M (12) */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;

void perm(vector<int> v, set<int> s, int num, int left);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	set<int> s;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> num;
		s.insert(num);
	}

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		num = *it;
		perm(v, s, num, M);
	}

	return 0;
}


void perm(vector<int> v, set<int> s, int num, int left) {
	v.push_back(num);
	--left;

	if (left == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (set<int>::iterator it = s.find(num); it != s.end(); it++) {
		num = *it;
		perm(v, s, num, left);
	}
}