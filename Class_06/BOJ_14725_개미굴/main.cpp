/* BOJ_14725 개미굴 */
/* hanabzu */

#include <iostream>
#include <set>
using namespace std;

const int MAXN = 1000;

class Word {
public:
	int depth = 0;
	string s = "";
	set<Word> childs;
	Word() {}
	Word(int depth, string s) : depth(depth), s(s) {}

	bool operator<(const Word& rhs) const {
		return this->s < rhs.s;
	}
};

int N, K;
string food;

Word root;
void print_childs(Word& p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> K;
		Word* p = &root;
		for (int i = 0; i < K; i++) {
			cin >> food;
			Word* tmp = p;
			for (set<Word>::iterator it = (*p).childs.begin(); it != (*p).childs.end(); it++) {
				if ((*it).s == food) {
					p = const_cast<Word*>(&(*it));
					break;
				}
			}

			if (p == tmp) { // new child
				(*p).childs.insert(Word((*p).depth + 1, food));
				for (set<Word>::iterator it = (*p).childs.begin(); it != (*p).childs.end(); it++) {
					if ((*it).s == food) {
						p = const_cast<Word*>(&(*it));
						break;
					}
				}
			}
		}
	}

	print_childs(root);


	return 0;
}


void print_childs(Word& p) {
	for (set<Word>::iterator it = p.childs.begin(); it != p.childs.end(); it++) {
		for (int i = 1; i < (*it).depth; i++) cout << "--";
		cout << (*it).s << '\n';
		print_childs(const_cast<Word&>(*it));
	}
}