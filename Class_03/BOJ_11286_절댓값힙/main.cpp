/* hanabzu */
/* BOJ_11286 절댓값 힙 */

#include <iostream>
#include <set>

using namespace std;

int N, x;
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	s.insert(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			multiset<int>::iterator zero = s.find(0), m = --s.find(0), p = ++s.find(0);

			if (s.size() == 1) {
				cout << 0 << '\n';
			}

			else if (zero == s.begin()) {
				cout << *p << '\n';
				s.erase(s.find(*p));
			}
			else if (zero == --s.end() || abs(*m) <= abs(*p)) {
				cout << *m << '\n';
				s.erase(s.find(*m));
			}
			else {
				cout << *p << '\n';
				s.erase(s.find(*p));
			}
		}
		else {
			s.insert(x);
		}

	}

	return 0;
}