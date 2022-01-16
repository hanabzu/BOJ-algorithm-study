/* hanabzu */
/* BOJ_9663 N-Queen */

#include <iostream>

using namespace std;

int N, result = 0;

// expressing as 1-d array
bool columns[14];
bool l_diag[28];
bool r_diag[28];

void solve(int n);
bool check(int r, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solve(0);

	cout << result;

	return 0;
}

void solve(int r) {
	if (r == N) {
		result++;
		return;
	}

	for (int c = 0; c < N; c++) { // find all possible positions
		if (check(r, c)) {// can place queen
			columns[c] = true;
			l_diag[r - c + N] = true;
			r_diag[r + c] = true;

			// next line
			solve(r + 1);

			// backtrack
			columns[c] = false;
			l_diag[r - c + N] = false;
			r_diag[r + c] = false;
		}
	}
}

bool check(int r, int c) {
	if (columns[c] == true || l_diag[r - c + N] == true || r_diag[r + c] == true) {
		return false;
	}
	return true;
}





