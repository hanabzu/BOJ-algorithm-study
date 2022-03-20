/* BOJ_3055 탈출 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

enum Area {
	ROCK, BLANK, WATER, CAVE, BEAVER
};

bool visit[52][52];
int woods[52][52];
int R, C, t = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string s;

queue<pair<int, int>> fq, mq;

void flood();
int move();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> s;
		for (int j = 1; j <= C; j++) {
			switch (s[j-1]) {
			case '.':
				woods[i][j] = BLANK;
				break;
			case '*':
				woods[i][j] = WATER;
				fq.push(make_pair(i, j));
				break;
			case 'D':
				woods[i][j] = CAVE;
				break;
			case 'S':
				woods[i][j] = BEAVER;
				mq.push(make_pair(i, j));
			}
		}
	}

	while (1) {
		t++;
		flood();
		int flag = move();
		if (flag == -1) {
			cout << "KAKTUS";
			break;
		}
		else if (flag == 1) {
			cout << t;
			break;
		}
	}

	return 0;
}


void flood() {
	int q_size = fq.size();
	for (int n = 0; n < q_size; n++) {
		pair<int, int> u = fq.front();
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = u.first + dx[i];
			int new_y = u.second + dy[i];

			if (woods[new_x][new_y] == BLANK) {
				woods[new_x][new_y] = WATER;
				fq.push(make_pair(new_x, new_y));
			}
		}
	}
}
int move() {
	int q_size = mq.size();
	for (int n = 0; n < q_size; n++) {
		pair<int, int> u = mq.front();
		mq.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = u.first + dx[i];
			int new_y = u.second + dy[i];

			if (woods[new_x][new_y] == BLANK) {
				woods[new_x][new_y] = BEAVER;
				mq.push(make_pair(new_x, new_y));
			}
			else if (woods[new_x][new_y] == CAVE) {
				return 1; // success
			}
		}
	}

	q_size = mq.size();
	if (mq.size() == 0) { // KAKTUS
		return -1;
	}
	else { // keep going
		return 0;
	}
}