/* hanabzu */
/* BOJ_1462 1로 만들기 */

#include <iostream>
#include <algorithm>

using namespace std;
int operation(int N);
int memo[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cout << operation(N);
}

int operation(int N) {
	int A=100, B=100, C=100; // over value of max
	if (N == 1) {
		return 0;
	}
	if (memo[N]!=0) {
		return memo[N];
	}
	else {
		memo[N] = 1;
		if (N % 3 == 0) {
			A = operation(N / 3);
		}
		if (N % 2 == 0) {
			B = operation(N >> 1);
		}
		C = operation(N - 1);
		memo[N] += min({ A,B,C }); // minimum of 3 cases
		return memo[N];
	}
}

