/* BOJ_1725 히스토그램 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100000;
const int POWN = 18;
const int INF = 1987654321;
int N, B;
long long ans = 0;
pii idt[1 << POWN];

long long query(int lhs, int rhs);
pii get_min_idx(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (B = 1; B < N; B <<= 1);
	for (int i = 0; i <= (B << 1); i++) {
		idt[i] = make_pair(INF, 0);
	}
	for (int i = B; i < B + N; i++) {
		cin >> idt[i].first;
		idt[i].second = i;
	}
	for (int i = B - 1; i > 0; i--) {
		idt[i] = min(idt[i << 1], idt[(i << 1) | 1]);
	}

	cout << query(B, B + N - 1);

	

	return 0;
}

long long query(int lhs, int rhs) {
	pii min_v = get_min_idx(lhs, rhs);
	long long max_s = static_cast<long long>(rhs - lhs + 1) * (idt[min_v.second]).first;

	if (lhs <= min_v.second - 1) {
		max_s = max(max_s, query(lhs, min_v.second - 1));
	}
	if (min_v.second + 1 <= rhs) {
		max_s = max(max_s, query(min_v.second + 1, rhs));
	}
	return max_s;
}

pii get_min_idx(int lhs, int rhs) {
	pii min_v = make_pair(INF, 0);
	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			min_v = min(min_v, idt[lhs]);
		}
		if ((rhs & 1) == 0) {
			min_v = min(min_v, idt[rhs]);
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return min_v;
}