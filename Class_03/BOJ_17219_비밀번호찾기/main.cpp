/* hanabzu */
/* BOJ_17219 finding password */

#include <iostream>
#include <map>

using namespace std;

map<string, string> dict;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string address, password;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> address >> password;
		dict[address] = password;
	}

	for (int i = 0; i < M; i++) {
		cin >> address;
		cout << dict[address] << '\n';
	}

}