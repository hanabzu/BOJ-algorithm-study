/* hanabzu */
/* BOJ_9375 패션왕 신해빈 */

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void dress_cases();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		dress_cases();
	}

	return 0;
}


void dress_cases() {
	map<string, int> clothes;
	int n, cases = 1;

	string input;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input >> input;
		clothes[input]++;
	}

	for (map<string, int>::iterator iter = clothes.begin(); iter != clothes.end(); iter++) {
		cases *= iter->second + 1; // +1 is undress counting
	}

	cout << --cases << '\n'; // except naked
}