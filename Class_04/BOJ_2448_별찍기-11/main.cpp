/* BOJ_2448 별 찍기 - 11 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

bool C[(3 << 10) + 1][((3 << 10) << 1) + 1];
int N;
void f(int r, int c, int size);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N;

	f(N, N, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= (N << 1); j++) {
			if (C[i][j]) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}

void f(int r, int c, int size) {
	if (size == 3) {
		C[r - 2][c] = true;
		C[r - 1][c - 1] = C[r - 1][c + 1] = true;
		C[r][c - 2] = C[r][c - 1] = C[r][c] = C[r][c + 1] = C[r][c + 2] = true;
		return;
	}
	size >>= 1;
	f(r - size, c, size);
	f(r, c - size, size);
	f(r, c + size, size);
}