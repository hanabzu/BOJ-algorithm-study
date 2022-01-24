/* BOJ_1837 암호제작 */
/* hanabzu */

#include <iostream>

#define MAXN 1000000
using namespace std;

bool visit[MAXN + 1];
string P;
int K;

bool div(int i);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> P >> K;
	
	for (int i = 2; i < K; i++) {
		if (visit[i]) continue;

		if (div(i)) {
			cout << "BAD " << i;
			return 0;
		}

		for (int j = i; j < K; j += i){
			visit[j] = true;
		}
	}

	cout << "GOOD";
	return 0;
}


bool div(int n) {
	int r = 0;
	for (int i = 0; i < P.size(); i++) {
		r = (r * 10 + (P[i] - '0')) % n;
	}
	return (r == 0);
}