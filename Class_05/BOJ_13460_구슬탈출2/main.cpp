/* BOJ_13460 구슬 탈출 2 */
/* hanabzu */

#include <iostream>
#include <queue>

using namespace std;
enum {
	WALL, BLANK, HOLE
};
const int MAXN = 10;

struct Pos {
	int Rr = 0, Rc = 0, Br = 0, Bc = 0;
	Pos(int Rr, int Rc, int Br, int Bc):Rr(Rr), Rc(Rc), Br(Br), Bc(Bc){}
	Pos() {}
};
int N, M, q_size, ans = 0;
int map[MAXN][MAXN];
bool visit[MAXN][MAXN][MAXN][MAXN]; // Rr, Rc, Br, Bc
string s;
queue<Pos> q;

Pos move(Pos& p, int dir); // if (-1,-1) returns -> fell into hole
void moveBall(int* pr, int* pc, int dir);
bool isVisit(Pos& p);
void visitPos(Pos& p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Pos startPos;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') map[i][j] = BLANK;
			else if (s[j] == 'R') {
				startPos.Rr = i;
				startPos.Rc = j;
			}
			else if (s[j] == 'B') {
				startPos.Br = i;
				startPos.Bc = j;
			}
			else if (s[j] == 'O') map[i][j] = HOLE;
		}
	}

	q.push(startPos);
	visitPos(startPos);
	while (ans < 10) {
		ans++;
		q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			Pos p = q.front(), newp;
			q.pop();
			for (int d = 0; d < 4; d++) {
				newp = move(p, d);
				if (newp.Br == -1) { // fail
					continue; 
				}
				else if (newp.Rr == -1) { // success
					cout << ans;
					return 0;
				}
				
				if (!isVisit(newp)) {
					visitPos(newp);
					q.push(newp);
				}
			}
		}
		
	}

	cout << -1;
	return 0;
}

Pos move(Pos& p, int dir) {
	int Rr, Rc, Br, Bc;
	Rr = p.Rr;
	Rc = p.Rc;
	Br = p.Br;
	Bc = p.Bc;

	if (dir == 0) { // Left
		if (Rc < Bc) {
			moveBall(&Rr, &Rc, 0);
			moveBall(&Br, &Bc, 0);
		}
		else {
			moveBall(&Br, &Bc, 0);
			moveBall(&Rr, &Rc, 0);
		}
	}
	else if (dir == 1) { // Right
		if (Rc > Bc) {
			moveBall(&Rr, &Rc, 1);
			moveBall(&Br, &Bc, 1);
		}
		else {
			moveBall(&Br, &Bc, 1);
			moveBall(&Rr, &Rc, 1);
		}
	}
	else if (dir == 2) { // Up
		if (Rr < Br) {
			moveBall(&Rr, &Rc, 2);
			moveBall(&Br, &Bc, 2);
		}
		else {
			moveBall(&Br, &Bc, 2);
			moveBall(&Rr, &Rc, 2);
		}
	}
	else if (dir == 3) { // Down
		if (Rr > Br) {
			moveBall(&Rr, &Rc, 3);
			moveBall(&Br, &Bc, 3);
		}
		else {
			moveBall(&Br, &Bc, 3);
			moveBall(&Rr, &Rc, 3);
		}
	}
	map[Rr][Rc] = map[Br][Bc] = BLANK;
	return Pos(Rr, Rc, Br, Bc);
}

void moveBall(int* pr, int* pc, int dir) {
	int r = *pr, c = *pc;
	int newp;
	map[r][c] = BLANK;

	if (dir == 0) { // Left
		newp = c;
		while (map[r][newp - 1] == BLANK) {
			newp--;
		}
		if (map[r][newp - 1] == HOLE) { // fell
			*pr = -1;
			*pc = -1;
		}
		else { // stuck
			*pc = newp;
			map[r][newp] = WALL;
		}
	}
	else if (dir == 1) { // Right
		newp = c;
		while (map[r][newp + 1] == BLANK) {
			newp++;
		}
		if (map[r][newp + 1] == HOLE) { // fell
			*pr = -1;
			*pc = -1;
		}
		else { // stuck
			*pc = newp;
			map[r][newp] = WALL;
		}

	}
	else if (dir == 2) { // Up
		newp = r;
		while (map[newp - 1][c] == BLANK) {
			newp--;
		}
		if (map[newp - 1][c] == HOLE) { // fell
			*pr = -1;
			*pc = -1;
		}
		else { // stuck
			*pr = newp;
			map[newp][c] = WALL;
		}

	}
	else if (dir == 3) { // Down
		newp = r;
		while (map[newp + 1][c] == BLANK) {
			newp++;
		}
		if (map[newp + 1][c] == HOLE) { // fell
			*pr = -1;
			*pc = -1;
		}
		else { // stuck
			*pr = newp;
			map[newp][c] = WALL;
		}
	}
}


bool isVisit(Pos& p) {
	return visit[p.Rr][p.Rc][p.Br][p.Bc];
}

void visitPos(Pos& p) {
	visit[p.Rr][p.Rc][p.Br][p.Bc] = true;
}

