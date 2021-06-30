/* hanabzu */
/* BOJ_11403 경로 찾기 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int i);

int vertex[100] = { 0, };
vector<bool> adjacent[100];
bool answer[100][100] = { 0, };

int N;
bool x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			adjacent[i].push_back(x);
		}
	}

	// bfs
	for (int i = 0; i < N; i++) {
		BFS(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

void BFS(int i) {
	queue<int> q;

	for (int i = 0; i < N; i++) {
		vertex[i] = 0;
	}
	
	q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int k = 0; k < N; k++) {
			if (vertex[k] == 0 && adjacent[u][k] == 1) {
				answer[i][k] = 1;
				vertex[k] = 1;
				q.push(k);
			}
		}
	}
}