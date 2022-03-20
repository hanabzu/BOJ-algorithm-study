/* BOJ_2014 소수의 곱 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <vector>
#include "limits.h"

using namespace std;
int K, N;
long long v;
int p[100];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> p[i];
		q.push(p[i]);
	}

	while (--N) {
		int u = q.top();
		q.pop();
		for (int i = 0; i < K; i++) {
			v = (long long)u * p[i];
			if (v < INT_MAX) {
				q.push(v);
			}
			if (u % p[i] == 0) {
				break;
			}
		}
	}

	cout << q.top();
	
	return 0;
}