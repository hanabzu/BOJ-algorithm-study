/* hanabzu* /
/* BOJ_15663 N과 M (9) */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M, num;

void perm(vector<int> v, map<int, int> m, int num, int left);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	map<int,int> m;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (!m.count(num)) {
			m[num] = 0;
		}
		m[num]++;
	}

	for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
		num = (*it).first;
		perm(v, m, num, M);
	}

	return 0;
}


void perm(vector<int> v, map<int, int> m, int num, int left) {
	v.push_back(num);
	m[num]--;

	if (--left == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (m[(*it).first] > 0) {
			num = (*it).first;
			perm(v, m, num, left);
		}
	}
}