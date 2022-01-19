/* BOJ_2504 괄호의 값 */
/* hanabzu */

#include <iostream>

using namespace std;

string s;
int p = -1, ans = 0;

int br();
int pa();

int main() {
	cin >> s;
	while (p < (int)s.size()-1) {
		p++;
		if (s[p] == '(') {
			ans += pa();
		}
		else if (s[p] == '[') {
			ans += br();
		}
		else {
			cout << 0;
			exit(0);
		}
	}
	cout << ans;
	return 0;
}

int br() {
	int t = 0;
	while (1) {
		p++;
		if (s[p] == '(') {
			t += pa();
		}
		else if (s[p] == '[') {
			t += br();
		}
		else if (s[p] == ']') {
			return (t == 0) ? 3 : (t * 3);
		}
		else {
			cout << 0;
			exit(0);
		}
	}
}
int pa() {
	int t = 0;
	while (1) {
		p++;
		if (s[p] == '(') {
			t += pa();
		}
		else if (s[p] == '[') {
			t += br();
		}
		else if (s[p] == ')') {
			return (t == 0) ? 2 : (t << 1);
		}
		else {
			cout << 0;
			exit(0);
		}
	}
}