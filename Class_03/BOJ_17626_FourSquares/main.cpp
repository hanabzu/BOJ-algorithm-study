﻿/* BOJ_17626_FourSquares */
/* hanabzu */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSolo();
bool isDuo();
bool isTrio();

vector<int> squares;
int n, m = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i * i <= n; i++) {
		squares.push_back(i * i);
	}

	if (isSolo()) {
		m = 1;
	}
	else if (isDuo()) {
		m = 2;
	}
	else if (isTrio()) {
		m = 3;
	}
	else {
		m = 4;
	}

	cout << m;
	return 0;
}

bool isSolo() {
	for (int i = 0; i < squares.size(); i++) {
		if (squares[i] == n) {
			return true;
		}
	}
	return false;
}

bool isDuo() {
	for (int i = squares.size() - 1; i >= 0; i--) {
		for (int j = 0; j < squares.size(); j++) {
			if (squares[i] + squares[j] == n) {
				return true;
			}
		}
	}
	return false;
}

bool isTrio() {
	for (int i = 0; i < squares.size(); i++) {
		for (int j = 0; j < squares.size(); j++) {
			for (int k = 0; k < squares.size(); k++) {
				if (squares[i] + squares[j] + squares[k] == n) {
					return true;
				}
			}
		}
	}
	return false;
}