/* hanabzu */
/* BOJ_5525 IOIOI */

#include <iostream>
using namespace std;

char t;
int len = 0, stmt = 0;
int n, m, result = 0;
string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> input;
	for (int i = 0; i < m + 1; i++) {
		t = input[i];
		if (stmt == 0) {
			if (t == 'I') {
				stmt = 1;
			}
		}
		else if (stmt == 1) {
			if (t == 'O') {
				stmt = 2;
			}
			else {
				if (len >= n) {
					result += len - n + 1;
				}
				len = 0;
				stmt = 1;
			}
		}
		else if (stmt == 2) {
			if (t == 'I') {
				len++;
				stmt = 1;
			}
			else {
				if (len >= n) {
					result += len - n + 1;
				}
				len = 0;
				stmt = 0;
			}
		}
	}

	cout << result;

	return 0;
}
