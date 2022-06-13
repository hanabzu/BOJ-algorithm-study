/* BOJ_1802 종이 접기 */
/* hanabzu */

#include <iostream>

using namespace std;

int T;
string s;

bool isOkay(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> s;
		if (isOkay(0, s.size() - 1)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}

bool isOkay(int lhs, int rhs) {
	if (lhs >= rhs) return true;
	int l = lhs, r = rhs, half = (lhs + rhs) >> 1;

	while (l < r) {
		if (s[l++] == s[r--]) return false;
	}
	
	return isOkay(lhs, half - 1) && isOkay(half + 1, rhs);
}