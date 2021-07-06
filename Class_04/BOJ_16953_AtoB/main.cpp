/* hanabzu */
/* BOJ_16954 A→B */

#include <iostream>
#include <queue>

using namespace std;

long long A, B, u, v[2], t = 2, q_count = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	queue<int> q;
	q.push(A);

	while (!q.empty()) {
		u = q.front();
		q.pop();
		v[0] = u << 1;
		v[1] = u * 10 + 1;
		for (int i = 0; i < 2; i++) {
			if (v[i] == B) {
				cout << t;
				return 0;
			}
			else if (v[i] < B) {
				q.push(v[i]);
		
			}
		}

		if (--q_count == 0) {
			q_count = q.size();
			t++;
		}
	}

	cout << -1;

	return 0;
}