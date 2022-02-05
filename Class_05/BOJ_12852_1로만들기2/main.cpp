/* hanabzu */
/* BOJ_12852 1로 만들기 2 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;

int N;
int operation(int N);
int memo[MAXN + 1], parent[MAXN + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << operation(N) << '\n';

	int next = N;
	while(next){
		cout << next << ' ';
		next = parent[next];
	}
}

int operation(int N) {
	if (N == 1) {
		return 0;
	}
	if (memo[N] == 0) {
		int minOp[3] = {MAXN, MAXN, MAXN};
		int nextN[3] = { N / 3, N >> 1, N - 1 };
		memo[N] = 1;
		if (N % 3 == 0) {
			minOp[0] = operation(nextN[0]);
		}
		if (N % 2 == 0) {
			minOp[1] = operation(nextN[1]);
		}
		minOp[2] = operation(nextN[2]);

		int* M = min_element(minOp, minOp + 3);
		parent[N] = nextN[M - minOp];
		memo[N] += *M; // minimum of 3 cases
	}
	return memo[N];
}