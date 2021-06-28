/* hanabzu */
/* BOJ_11279 최대 힙 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x;
	priority_queue<int, vector<int>> q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
	return 0;
}