/* hanabzu */
/* BOJ_1074 Z */

#include <iostream>

using namespace std;

int N, r, c;

int Z(int N, int r, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	cout << Z(N, r, c);

	return 0;
}

int Z(int N, int r, int c) {
	if (N == 1) {
		return (r << 1) + c ;
	}

	int half = (1 << (N - 1));
	if (r < half && c < half) { // the second quadrant
		return Z(N - 1, r, c);
	}
	else if (r >= half && c < half) { // the third quadrant
		return Z(N - 1, r - half, c) + (half * half << 1);
	}
	else if (r < half && c >= half) { // the first quadrant
		return Z(N - 1, r, c - half) + half * half;
	}
	else { // the fourth quadrant
		return Z(N - 1 , r - half, c - half) + 3 * half * half;
	}
}