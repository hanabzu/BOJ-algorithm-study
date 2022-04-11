/* BOJ_21608 상어 초등학교 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

const int MAXN = 20;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };
int N, room[MAXN][MAXN], stu[MAXN * MAXN][5];
vector<pair<int, int>> p_like, p_blank;
void locate(int num);
int get_score();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> stu[i][j];
		}
		locate(i);
	}

	cout << get_score();

	return 0;
}

void locate(int num) {
	int like[MAXN][MAXN] = { 0, }, blank[MAXN][MAXN] = { 0, };
	int max_like = 0, max_blank = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (room[i][j] != 0) continue;

			for (int d = 0; d < 4; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];

				if (ni < 0 || ni >= N || nj < 0 || nj >= N)continue;

				if (room[ni][nj] == 0) {
					blank[i][j]++;
					continue;
				}

				for (int n = 1; n <= 4; n++) {
					if (stu[num][n] == room[ni][nj]) {
						like[i][j]++;
						break;
					}
				}
			}
			max_like = max(max_like, like[i][j]);
		}
	}

	p_like = vector<pair<int, int>>();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (room[i][j] != 0) continue;
			if (max_like == like[i][j]) {
				p_like.push_back(make_pair(i, j));
				max_blank = max(max_blank, blank[i][j]);
			}
		}
	}

	if (p_like.size() == 1) {
		room[p_like[0].first][p_like[0].second] = stu[num][0];
		return;
	}

	p_blank = vector<pair<int, int>>();
	for (int i = 0; i < p_like.size(); i++) {
		int r = p_like[i].first;
		int c = p_like[i].second;

		if (max_blank == blank[r][c]) {
			p_blank.push_back(make_pair(r, c));
		}
	}

	room[p_blank[0].first][p_blank[0].second] = stu[num][0];
}


int get_score() {
	int score = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int who = room[i][j];
			int num = 0;
			int num_like = 0;
			for (; num < N * N; num++) {
				if (who == stu[num][0]) {
					break;
				}
			}

			for (int d = 0; d < 4; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				if (ni < 0 || ni >= N || nj < 0 || nj >= N)continue;

				for (int n = 1; n <= 4; n++) {
					if (stu[num][n] == room[ni][nj]) {
						num_like++;
						break;
					}
				}
			}

			if (num_like != 0) {
				score += pow(10, num_like - 1);
			}
		}
	}

	return score;
}