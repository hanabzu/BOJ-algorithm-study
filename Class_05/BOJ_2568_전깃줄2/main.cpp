/* BOJ_2568 전깃줄 - 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
const int MAXNUM = 500000;
const int MAXN = 100000;
const int POWN = 20;

int idt[1 << POWN];
int N, a, b, B, ans = 0;
pair<int, int> line[MAXN];
vector<int> v;

int get_max(int lhs, int rhs);
void update(int p, int lis);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	for (B = 1; B < MAXNUM; B <<= 1);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		line[i] = make_pair(b, a);
	}

	sort(line, line + N);

	for (int i = 0; i < N; i++) {
		int p = line[i].second;
		update(p, get_max(1, p) + 1);
	}

	ans = N - idt[1];

	int m = idt[1];
	for (int i = (B << 1) - 1; i >= B; i--) {
		if (idt[i] == 0) continue;

		if (idt[i] == m) {
			m--;
		}
		else {
			v.push_back(i - B + 1);
		}
	}
	sort(v.begin(), v.end());

	cout << ans << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}

int get_max(int lhs, int rhs) {
	lhs += (B - 1);
	rhs += (B - 1);
	int s = 0;
	while (lhs <= rhs) {
		if ((lhs & 1) == 1) {
			s = max(s, idt[lhs]);
		}
		if ((rhs & 1) == 0) {
			s = max(s, idt[rhs]);
		}
		lhs = (lhs + 1) >> 1;
		rhs = (rhs - 1) >> 1;
	}
	return s;
}

void update(int p, int lis) {
	p += (B - 1);
	idt[p] = lis;
	while (p >>= 1) {
		idt[p] = max(idt[p<<1], idt[(p<<1)|1]);
	}
}
