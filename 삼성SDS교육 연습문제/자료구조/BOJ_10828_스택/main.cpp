/* BOJ_10828 스택 */
/* hanabzu */

#include <iostream>
#define MAXN 100000

using namespace std;

string s;
int N, num, top = -1;
int stack[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> s;
		if (s == "push") {
			cin >> stack[++top];
		}
		else if (s == "pop") {
			if (top < 0) {
				cout << -1 << '\n';
			}
			else {
				cout << stack[top--] << '\n';
			}
		}
		else if (s == "size") {
			cout << top + 1 << '\n';
		}
		else if (s == "empty") {
			if (top < 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else { // s == "top"
			if (top < 0) {
				cout << -1 << '\n';
			}
			else {
				cout << stack[top] << '\n';
			}
		}
	}


	return 0;
}