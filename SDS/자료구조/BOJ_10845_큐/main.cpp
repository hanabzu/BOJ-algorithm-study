/* BOJ_10845 큐 */
/* hanabzu */

#include <iostream>
#define MAXN 10000
using namespace std;

int q[MAXN];
int N, n;
int f = 0, b = 0;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> s;
		if (s == "push") {
			cin >> q[b++];
		}
		else if (s == "pop") {
			if (f == b) {
				cout << -1 << '\n';
			}
			else {
				cout << q[f++] << '\n';
			}
		}
		else if (s == "size") {
			cout << b - f << '\n';
		}
		else if (s == "empty") {
			if (f == b) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (s == "front") {
			if (f == b) {
				cout << -1 << '\n';
			}
			else {
				cout << q[f] << '\n';
			}
		}
		else { // s == "back"
			if (f == b) {
				cout << -1 << '\n';
			}
			else {
				cout << q[b-1] << '\n';
			}
		}
	}

	return 0;
}