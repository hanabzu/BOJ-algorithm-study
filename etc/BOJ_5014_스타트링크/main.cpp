/* BOJ_5014 스타트링크 */
/* hanabzu */

#include <iostream>
#include <queue>
using namespace std;

const int MAXF = 1000000;

int F, S, G, ans = 0, q_size;
int UD[2];
bool visit[MAXF + 1];
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> UD[0] >> UD[1];
	UD[1] = -UD[1];
	visit[S] = true;
	q.push(S);
	q_size = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == G) {
			cout << ans;
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			int nu = u + UD[i];

			if (nu<1 || nu>F || visit[nu]) continue;
			visit[nu] = true;
			q.push(nu);
		}

		if (--q_size == 0) {
			ans++;
			q_size = q.size();
		}

	}

	cout << "use the stairs";

	return 0;
}