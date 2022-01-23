/* BOJ_6588 골드바흐의 추측 */
/* hanabzu */

#include <iostream>
#define MAXN 1000000

using namespace std;

int a;
bool visit[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int s = 2; s < MAXN; s++) {
		if (!visit[s]) {
			int i = s<<1;
			while (i <= MAXN) {
				if (!visit[i]) {
					visit[i] = true;
				}
				i += s;
			}
		}
	}


	while (1) {
		cin >> a;
		if (!a) break;
		for (int i = 3; i <= MAXN; i++) {
			if ((!visit[i]) && (!visit[a - i])) {
				cout << a << " = " << i << " + " << a - i << '\n';
				break;
			}
		}
	}

	return 0;
}