/* hanabzu */
/* BOJ_5430 AC */

#include <iostream>
#include <list>
#include <string>

using namespace std;

void test_case();
void tokenize(const string& line, list<int>& num_list);
void print_list(list<int>& num_list, bool reverse);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		test_case();
	}

	return 0;
}

void test_case() {
	int n;
	string p, line;
	list<int> num_list;
	bool reverse = 0;

	cin >> p >> n >> line;

	tokenize(line, num_list);
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') {
			reverse = !reverse;
		}
		else { // D
			if (num_list.empty()) {
				cout << "error\n";
				return;
			}
			if (!reverse) { // delete front
				num_list.pop_front();
			}
			else { // delete last
				num_list.pop_back();
			}
		}
	}

	print_list(num_list, reverse);
}

void tokenize(const string& line, list<int>& num_list) {
	if (line.size() == 2) { // empty line
		return;
	}
	size_t front = 1;
	size_t end = line.find(',');

	while (end != string::npos) {
		num_list.push_back(stoi(line.substr(front, end - front)));
		front = end + 1;
		end = line.find(',', front);
		
	}
	num_list.push_back(stoi(line.substr(front, end - front -1)));
}

void print_list(list<int>& num_list, bool reverse) {
	if (num_list.empty()) {
		cout << "[]\n";
	}
	else {
		if (!reverse) {
			cout << '[' << *(num_list.begin());
			for (list<int>::iterator it = ++num_list.begin(); it != num_list.end(); it++) {
				cout << ',' << *it;
			}
		}
		else {
			cout << '[' << *(--num_list.end());
			for (list<int>::reverse_iterator it = ++num_list.rbegin(); it != num_list.rend(); it++) {
				cout << ',' << *it;
			}
		}
		
		cout << "]\n";
	}
}