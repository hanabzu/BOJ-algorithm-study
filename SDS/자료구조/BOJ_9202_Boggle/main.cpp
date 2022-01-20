/* BOJ_9202 Boggle */
/* hanabzu */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Word {
	bool isWord = false;
	char c = ' ';
	string s ="";
	vector<Word*> child;
	Word() {}
	Word(bool isWord, char c, string s) :isWord(isWord),c(c), s(s) {}
};

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
Word root;
Word* p;
int w, b;
string s;
int max_size;
int num_word;
int score;
string boggle[4];
bool visit[4][4];
set<string> wset;
void game();
void dfs(int depth, int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w;
	for (int i = 0; i < w; i++) { // trie
		cin >> s;
		p = &root;
		for (int j = 0; j < s.size(); j++) {
			Word* t = p;
			for (vector<Word*>::iterator it = p->child.begin(); it != p->child.end(); it++) {
				if ((*it)->c == s[j]) {
					if (j == s.size() - 1) {
						(*it)->isWord = true;
					}
					p = *it;
					break;
				}
			}
			if (t == p) {
				Word* new_p;
				if (j == s.size() - 1) {
					new_p = new Word(true, s[j], (p->s) + s[j]);
				}
				else {
					new_p = new Word(false, s[j], (p->s) + s[j]);
				}
				p->child.push_back(new_p);
				p = new_p;
			}
		}
	}
	

	cin >> b;
	for (int i = 0; i < b; i++) {
		game();
	}
	return 0;
}

void game() {
	wset = set<string>();
	max_size = 0;
	num_word = 0;
	score = 0;

	for (int i = 0; i < 4; i++) {
		cin >> boggle[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			s = boggle[i][j];
			p = &root;
			visit[i][j] = true;
			dfs(1, i, j);
			visit[i][j] = false;
		}
	}
	cout << score << ' ';

	for (set<string>::iterator it = wset.begin(); it != wset.end(); it++) {
		if ((*it).size() == max_size) {
			cout << *it;
			break;
		}
	}
	cout << ' ' << num_word << '\n';

}

void dfs(int depth, int r, int c) {
	if (depth > 8) return;
	string ts = s;
	Word* tp = p;
	for (vector<Word*>::iterator it = p->child.begin(); it != p->child.end(); it++) {
		if ((*it)->c == boggle[r][c]) {
			if ((*it)->isWord) { // find word
				if (wset.count((*it)->s)==0) {
					max_size = max(max_size, (int)(*it)->s.size());
					wset.insert((*it)->s);
					num_word++;
					if ((*it)->s.size() == 3 || (*it)->s.size() == 4) score++;
					else if ((*it)->s.size() == 5) score += 2;
					else if ((*it)->s.size() == 6) score += 3;
					else if ((*it)->s.size() == 7) score += 5;
					else if ((*it)->s.size() == 8) score += 11;
				}
			}
			s = (*it)->s;
			p = *it;
			break;
		}
	}
	if (tp == p) {
		s = ts;
		return; // no word
	}


	for (int i = 0; i < 8; i++) {
		int new_r = r + dx[i];
		int new_c = c + dy[i];

		if (new_r < 4 && new_r >= 0 && new_c < 4 && new_c >= 0 && !visit[new_r][new_c]) {
			visit[new_r][new_c] = true;
			dfs(depth+1, new_r, new_c);
			visit[new_r][new_c] = false;
		}
	}
	s = ts;
	p = tp;
}