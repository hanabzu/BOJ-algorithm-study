/* BOJ_1655 가운데를 말해요 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, n;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> n;
		if (maxq.size()>minq.size()) {
			minq.push(n);
		}
		else {
			maxq.push(n);
		}

		if (maxq.size() > 0 && minq.size() > 0) {
			if (maxq.top() > minq.top()) {
				int maxtop = maxq.top();
				int mintop = minq.top();
				maxq.pop();
				minq.pop();
				maxq.push(mintop);
				minq.push(maxtop);
			}
		}
		cout << maxq.top() << '\n';
	}

	return 0;
}