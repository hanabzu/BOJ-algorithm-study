/* hanabzu */
/* BOJ_7662 이중 우선순위 큐 */

#include <iostream>
#include <set>

using namespace std;

int T, k, n;
char c;

void dpq();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		dpq();
	}

}

void dpq() {
	multiset<int> q;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c >> n;
		if (c == 'I') {
			q.insert(n);
		}
		else { // c == 'D'
			if (q.empty())
				continue;

			if (n == -1) {
				q.erase(q.begin());
			}
			else { // n == 1
				q.erase(--q.end());
			}
		}
	}

	if (q.empty()) {
		cout << "EMPTY" << '\n';
	}
	else {
		cout << *(--q.end()) << ' ' << *q.begin() << '\n';
	}
}