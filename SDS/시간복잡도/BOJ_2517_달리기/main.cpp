/* BOJ_2517 달리기 */
/* hanabzu */

#include <iostream>
#include <queue>
#define MAXN 500000
#define POWN 20
using namespace std;

struct Man {
	int index, speed;
	Man(int index, int speed) : index(index), speed(speed) {};
	bool operator<(const Man m) const {
		return this->speed < m.speed;
	}
};

int idt[1 << POWN];
int answer[MAXN + 1];
int N, B, a;
priority_queue<Man> q;
void update(int p);
int idtSum(int b, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (B = 1; B < N; B <<= 1);
	for (int i = 1; i <= N; i++) {
		cin >> a;
		q.push(Man(i, a));
	}

	while (!q.empty()) {
		Man m = q.top();
		q.pop();
		answer[m.index] = idtSum(1, m.index) + 1;
		update(m.index);
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}

void update(int p) {
	p += (B - 1);
	idt[p] = 1;
	while (p >>= 1) {
		idt[p] += 1;
	}

}

int idtSum(int b, int c) {
	b += (B - 1);
	c += (B - 1);
	int s = 0;
	while (b <= c) {
		if ((b & 1) == 1) {
			s += idt[b];
		}
		if ((c & 1) == 0) {
			s += idt[c];
		}
		b = (b + 1) >> 1;
		c = (c - 1) >> 1;
	}
	return s;
}