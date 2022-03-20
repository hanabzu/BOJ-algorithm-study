/* BOJ_15686 치킨 배달 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;

int a, N, M, min_dis = INT_MAX;

vector<pair<int, int>> chick, house;
vector<bool> combi;

int cal_sum_dis();
int cal_dis(pair<int,int> house_pos);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// read map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (a == 2) {
				chick.push_back(make_pair(i, j));
				combi.push_back(false);
			}
		}
	}

	// set for combination
	for (int i = 0; i < M; i++) {
		combi[combi.size() - 1 - i] = true;
	}

	do {
		min_dis = min(min_dis, cal_sum_dis());
	} while (next_permutation(combi.begin(), combi.end()));

	cout << min_dis;
	return 0;
}

int cal_sum_dis() {
	int dis = 0;
	for (int i = 0; i < house.size(); i++) {
		dis += cal_dis(house[i]);
	}
	return dis;
}

int cal_dis(pair<int, int> house_pos) {
	int d, dis = INT_MAX;
	for (int i = 0; i < combi.size(); i++) {
		if (combi[i]) {
			d = abs(chick[i].first - house_pos.first) + abs(chick[i].second - house_pos.second);
			dis = min(dis, d);
		}
	}
	return dis;
}

