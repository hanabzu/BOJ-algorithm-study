/* BOJ_1799 비숍 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 10;

int N, a_ans = 0, b_ans = 0;
bool n, l_diag[MAXN << 1], r_diag[MAXN << 1];
vector<pair<int, int>> a, b;
void backtrack(int p, int num, vector<pair<int,int>>& v, bool flag);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (!n) continue;

			if (((i + j) & 1) == 0) {
				a.push_back(make_pair(i, j));
			}
			else {
				b.push_back(make_pair(i, j));
			}
		}
	}

	backtrack(0, 0, a, true);
	backtrack(0, 0, b, false);
	cout << a_ans + b_ans;

	return 0;
}

void backtrack(int p, int num, vector<pair<int, int>>& v, bool flag){
	if (p == v.size()) {
		if (flag) {
			a_ans = max(a_ans, num);
		}
		else {
			b_ans = max(b_ans, num);
		}
		return;
	}


	int i = v[p].first;
	int j = v[p].second;

	if (!l_diag[i - j + N] && !r_diag[i + j]) {
		l_diag[i - j + N] = r_diag[i + j] = true;
		backtrack(p + 1, num + 1, v, flag);
		l_diag[i - j + N] = r_diag[i + j] = false;
	}

	backtrack(p + 1, num, v, flag);
	
}