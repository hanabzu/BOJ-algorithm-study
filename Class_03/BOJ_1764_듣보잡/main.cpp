/* hanabzu */
/* BOJ_1764 Unknown */

#include <iostream>
#include <set>

using namespace std;
set<string> unheard;
set<string> unknown;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num = 0;
	string name;
	set<string>::iterator iter;
	cin >> N >> M;

	for (int i = 0; i < N; i++) { // read unheard
		cin >> name;
		unheard.insert(name);
	}
	for (int i = 0; i < M; i++) { // find unknown
		cin >> name;
		if (unheard.count(name)) {
			unknown.insert(name);
			num++;
		}
	}
	cout << num << '\n';
	for (iter = unknown.begin(); iter != unknown.end(); iter++) {
		cout << *iter << '\n';
	}
}



