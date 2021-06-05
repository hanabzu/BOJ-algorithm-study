/* hanabzu */
/* BOJ_11723 С§Че */ 

#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int M, num, bnum, set = 0;
	string operation;

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> operation;
		if (operation == "all") {
			set = 1048575; // 00000000 00001111 11111111 11111111
		}
		else if (operation == "empty") {
			set = 0;
		}
		else { // add, remove, check, toggle
			cin >> num;
			bnum = 1 << (num - 1);

			if (operation == "add") {
				set |= bnum;
			}
			else if (operation == "remove") {
				set &= ~bnum;
			}
			else if (operation == "check") {
				if (set & bnum) {
					cout << 1 << '\n';
				}
				else {
					cout << 0 << '\n';
				}

			}
			else { // toggle
				set ^= bnum;
			}
		}

	}

}