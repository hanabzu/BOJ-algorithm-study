/* BOJ_1781 컵라면 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Ramen {
	int deadline, cnt;
	
	bool operator<(const Ramen& rhs)const {
		if (deadline == rhs.deadline) {
			return cnt < rhs.cnt;
		}
		return deadline > rhs.deadline;
	}
};

const int MAXN = 200000;

int N, ans = 0, t = 0;
Ramen ramen;
priority_queue<Ramen> pq;
priority_queue<int, vector<int>, greater<int>> ans_pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> ramen.deadline >> ramen.cnt;
		pq.push(ramen);
	}

	while (!pq.empty()) {
		if (pq.top().deadline > t) {
			ans_pq.push(pq.top().cnt);
			t++;
		} 
		else if (!ans_pq.empty() && pq.top().cnt > ans_pq.top()) {
			ans_pq.pop();
			ans_pq.push(pq.top().cnt);
		}

		pq.pop();
	}

	while (!ans_pq.empty()) {
		ans += ans_pq.top();
		ans_pq.pop();
	}

	cout << ans;
	return 0;
}