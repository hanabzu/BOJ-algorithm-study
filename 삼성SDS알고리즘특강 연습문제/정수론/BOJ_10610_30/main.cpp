/* BOJ_10610 30 */
/* hanabzu */

#include <iostream>
#include <set>
using namespace std;

string n;
multiset<char> s;

int main() {
	cin >> n;

	int m = 0;
	for (int i = 0; i < n.size(); i++) {
		m += n[i] - '0';
		s.insert(n[i]);
	}
	if (*s.begin() != '0' || m % 3 != 0) cout << -1;
	else {
		for (multiset<char>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
			cout << *it;
		}
	}

}