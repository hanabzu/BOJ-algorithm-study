/* hanabzu */
/* BOJ_9251 LCS */

#include <iostream>
using namespace std;

string X, Y;
int m, n;
int c[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y;
	m = X.length();
	n = Y.length();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (X[i] == Y[j]) {
				c[i+1][j+1] = c[i][j] + 1;
			}
			else if (c[i][j + 1] >= c[i + 1][j]) {
				c[i+1][j+1] = c[i][j+1];
			}
			else {
				c[i+1][j+1] = c[i+1][j];
			}
		}
	}

	cout << c[m][n];
	return 0;
}