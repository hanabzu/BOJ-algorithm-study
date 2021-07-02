/* hanabzu */
/* BOJ_9019 DSLR */

#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <string>

using namespace std;

void DSLR();
pair<int, long long> D(pair<int, long long>&);
pair<int, long long> S(pair<int, long long>&);
pair<int, long long> L(pair<int, long long>&);
pair<int, long long> R(pair<int, long long>&);
pair<int, long long>(*fp_DSLR[4])(pair<int, long long>&) = { D,S,L,R };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		DSLR();
	}


	return 0;
}

void DSLR() {
	int A, B;
	cin >> A >> B;

	bool visit[10000] = { 0, };
	queue<pair<int, long long>> q;

	visit[A] = 1;
	q.push(pair<int, long long>(A, 0));

	while (!q.empty()) {
		pair<int, long long> v, u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			v = fp_DSLR[i](u);
			if (visit[v.first]) {
				continue;
			}
			if (v.first == B) {
				string str = to_string(v.second);
				for (int j = 0; j < str.size(); j++) {
					switch (str[j]) {
					case '1':
						cout << 'D';
						break;
					case '2':
						cout << 'S';
						break;
					case '3':
						cout << 'L';
						break;
					case '4':
						cout << 'R';
					}
				}
				cout << '\n';
				return;
			}
			q.push(v);
			visit[v.first] = 1;
		}
	}
}

pair<int, long long> D(pair<int, long long>& u) {
	pair<int, long long> v;
	v.first = (u.first << 1) % 10000;
	v.second = u.second * 10 + 1;
	return v;
}

pair<int, long long> S(pair<int, long long>& u) {
	pair<int, long long> v;
	if (u.first == 0) {
		v.first = 9999;
	}
	else {
		v.first = u.first - 1;
	}
	v.second = u.second * 10 + 2;
	return v;
}

pair<int, long long> L(pair<int, long long>& u) {
	pair<int, long long> v;
	v.first = (u.first / 1000) + (u.first * 10) % 10000;
	v.second = u.second * 10 + 3;
	return v;
}
pair<int, long long> R(pair<int, long long>& u) {
	pair<int, long long> v;
	v.first = (u.first % 10) * 1000 + (u.first / 10);
	v.second = u.second * 10 + 4;
	return v;
}