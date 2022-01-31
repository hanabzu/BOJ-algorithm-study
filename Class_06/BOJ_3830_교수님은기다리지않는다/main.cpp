/* BOJ_3830 교수님은 기다리지 않는다 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
const int MAXW = 1000000;

char q;
int N, M, a, b, w;
int parent[MAXN + 1];
long long weight[MAXN + 1];

void question();
void uni();
int find(int a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> N >> M;
		if (N == 0) break;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			weight[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			cin >> q;
			if (q == '!') uni();
			else question();
		}
	}

	return 0;
}

void question() {
	cin >> a >> b;
	if (find(a) == find(b)) {
		cout << weight[b] - weight[a] << '\n';
	}
	else {
		cout << "UNKNOWN\n";
	}

}

void uni() {
	cin >> a >> b >> w;
	int pa = find(a);
	int pb = find(b);
	if (pa != pb) {
		parent[pb] = pa;
		weight[pb] = weight[a] - weight[b] + w;
	}
}

int find(int a) {
	if (parent[a] == a) return a;
	int p = find(parent[a]);
	weight[a] += weight[parent[a]];
	return parent[a] = p;
}