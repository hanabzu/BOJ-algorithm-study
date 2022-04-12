/* BOJ_17825 주사위 윷놀이 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	int score = 0;
	Node* next = nullptr;
	Node* bypass = nullptr;
};

Node node[22], innode[11];
Node* piece[4];
int n, order[10], ans = 0;

void backtrack(int p, int score);
bool move(int i, int step);
void init();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	for (int i = 0; i < 10; i++) {
		cin >> order[i];
	}

	for (int i = 0; i < 4; i++) {
		piece[i] = &node[0];
	}

	backtrack(0, 0);
	cout << ans;
	return 0;
}

void backtrack(int p, int score) {
	if (p == 10) {
		ans = max(ans, score);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!(piece[i]->next)) continue;

		Node* tmp = piece[i];

		if (!move(i, order[p])) continue;

		backtrack(p + 1, score + piece[i]->score);
		piece[i] = tmp;
		
	}
}

bool move(int i, int step) {
	Node* tmp = piece[i];

	for (int s = 0; s < step; s++) {
		if (s == 0 && tmp->bypass) {
			tmp = tmp->bypass;
		}
		else if (tmp->next) {
			tmp = tmp->next;
		}
		else { // reach end
			break;
		}
	}

	for (int j = 0; j < 4; j++) {
		if (i == j || !(piece[j]->next)) continue;
		
		if (piece[j] == tmp) {
			return false;
		}
	}

	piece[i] = tmp;
	return true;
}

void init() {
	for (int i = 0; i <= 20; i++) {
		node[i].next = &node[i + 1];
		node[i].score = (i << 1);
	}
	node[5].bypass = &innode[0];
	node[10].bypass = &innode[3];
	node[15].bypass = &innode[5];

	innode[0].next = &innode[1];
	innode[0].score = 13;
	innode[1].next = &innode[2];
	innode[1].score = 16;
	innode[2].next = &innode[8];
	innode[2].score = 19;

	innode[3].next = &innode[4];
	innode[3].score = 22;
	innode[4].next = &innode[8];
	innode[4].score = 24;

	innode[5].next = &innode[6];
	innode[5].score = 28;
	innode[6].next = &innode[7];
	innode[6].score = 27;
	innode[7].next = &innode[8];
	innode[7].score = 26;

	innode[8].next = &innode[9];
	innode[8].score = 25;
	innode[9].next = &innode[10];
	innode[9].score = 30;
	innode[10].next = &node[20];
	innode[10].score = 35;
}