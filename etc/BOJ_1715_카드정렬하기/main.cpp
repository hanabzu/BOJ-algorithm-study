/* BOJ_1715 카드 정렬하기 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int N;
long long A, B, ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q;

	while (N--) {
		cin >> A;
		q.push(A);
	}

	while (q.size() >= 2) {
		A = q.top();
		q.pop();
		B = q.top();
		q.pop();
		ans += A + B;
		q.push(A + B);
	}
	cout << ans;
	return 0;
}