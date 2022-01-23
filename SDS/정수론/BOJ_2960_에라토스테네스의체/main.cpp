/* BOJ_2960 에라토스테네스의 체 */
/* hanabzu */

#include <iostream>
#define MAXN 1000

using namespace std;

int N, K;
bool visit[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	while (1) {
		int s = 2;
		while (visit[s]) s++;
		int i = s;
		while (s <= N) {
			if (!visit[s]) {
				visit[s] = true;
				if (!(--K)) {
					cout << s;
					exit(0);
				}
			}
			s += i;
		}
	}

	return 0;
}