/* hanabzu */
/* BOJ_1003 피보나치 함수 */

#include <iostream>
using namespace std;

void fibonacci(int n);

int memo[2][41] = { {0,}, {0,} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    memo[0][0] = 1;
    memo[1][1] = 1;

    int n, N;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> N;
        fibonacci(N);
        cout << memo[0][N] << ' ' << memo[1][N] << '\n';
    }
}

void fibonacci(int n) {
    if (n == 0 || n == 1 || memo[0][n] != 0) {
        return;
    }
    else {
        fibonacci(n - 1);
        fibonacci(n - 2);
        memo[0][n] = memo[0][n - 1] + memo[0][n - 2];
        memo[1][n] = memo[1][n - 1] + memo[1][n - 2];
    }
}