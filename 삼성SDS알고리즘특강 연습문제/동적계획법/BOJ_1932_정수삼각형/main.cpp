/* hanabzu */
/* BOJ_1932 Á¤¼ö »ï°¢Çü */

#include <iostream>
#include <algorithm>

using namespace std;

int triangle[501][500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	cin >> triangle[1][0];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			cin >> triangle[i][j];
		}

		for (int j = 0; j < i; j++) {
			if (j == 0) {
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i - 1) {
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else {
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}
	}
	cout << *max_element(triangle[N], triangle[N] + N);
}