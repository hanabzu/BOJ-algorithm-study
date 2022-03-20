/* BOJ_1202 보석 도둑 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#define MAXN 300000
using namespace std;

struct Jewel {
	int m, v;
	Jewel(int m, int v) :m(m), v(v) {}
	bool operator<(const Jewel j) const {
		return v < j.v;
	}
};

priority_queue<Jewel> q;
int N, K, m, v, c;
multiset<int> bag;
long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		q.push(Jewel(m, v));
	}

	for (int i = 0; i < K; i++) {
		cin >> c;
		bag.insert(c);
	}

	while (!q.empty()) {
		Jewel u = q.top();
		q.pop();

		multiset<int>::iterator it = bag.lower_bound(u.m);
		if (it!=bag.end()) {
			bag.erase(it);
			ans += u.v;
		}
	}

	cout << ans;
	return 0;
}