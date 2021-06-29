/* hanabzu */
/* BOJ_11724 연결 요소의 개수 */

#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

class vertex {
public:
	int color = 0;
};

int N, M, a, b, result = 0;
vertex* v;
map<int, set<int>> e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v = new vertex[N];

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		if (!e.count(a)) {
			e[a] = set<int>();
		}
		e[a].insert(b);
		if (!e.count(b)) {
			e[b] = set<int>();
		}
		e[b].insert(a);
	}

	for (int i = 0; i < N; i++) {
		if (v[i].color == 0) {
			result++;
			v[i].color = 1;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (set<int>::iterator iter = e[u].begin(); iter != e[u].end(); iter++){
					if (v[*iter].color == 0) {
						v[*iter].color = 1;
						q.push(*iter);
					}
				}
				v[u].color = 2;
			}
		}
	}
	
	cout << result;

	return 0;
}