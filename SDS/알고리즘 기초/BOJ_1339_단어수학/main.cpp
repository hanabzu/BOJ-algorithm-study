/* BOJ_1339 단어 수학 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

string s;
int N, d, ans = 0;
int v[26];
priority_queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		d = 0;
		for (int j = s.size() - 1; j >= 0; j--) {
			v[s[j] - 'A'] += pow(10, d++);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (v[i] != 0) {
			q.push(v[i]);
		}
	}

	int w = 9;
	while (!q.empty()) {
		ans += q.top() * w;
		q.pop();
		w--;
	}

	cout << ans;
	return 0;
}