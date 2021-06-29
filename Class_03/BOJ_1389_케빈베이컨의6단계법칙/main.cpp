/* hanabzu */
/* BOJ_1389 케빈 베이컨의 6단계 법칙 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class user {
public:
	int color = 0;
	int rank = 0;
};

int N, M, a, b;
user* v;
bool e[100][100] = { 0, };
vector<int> kevin;

void BFS(int s);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	v = new user[N];

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	for (int i = 0; i < N; i++) {
		BFS(i);
	}

	cout << min_element(kevin.begin(), kevin.end()) - kevin.begin() + 1;

	return 0;
}

void BFS(int s) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		v[i].color = 0;
		v[i].rank = 0;
	}
	v[s].color = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (e[u][i] == 1) {
				if (v[i].color == 0) {
					v[i].color = 1;
					v[i].rank = v[u].rank + 1;
					q.push(i);
				}
			}
		}
		v[u].color = 2;
	}

	for (int i = 0; i < N; i++) {
		sum += v[i].rank;
	}

	kevin.push_back(sum);
}