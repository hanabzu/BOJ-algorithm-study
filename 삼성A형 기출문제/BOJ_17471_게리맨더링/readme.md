### BOJ_17471 게리맨더링

dfs를 활용해 조합을 적절히 사용.

단순히 dfs를 한 번 돌려서는 팀의 모든 경우를 구할 수 없어서 매우 당황한 문제.

`vector<int> e[MAXN+1]` : 그래프

`bool team[MAXN+1]` : true-> A팀, false -> B팀

`bool uni[MAXN+1]` : 처음에 dfs로 연결될 수 있는 지역을 모두 구해둠.

`combi()` 함수로 `uni[]`가 true인 지역에 한해 모든 가능한 조합을 구한 뒤 각 팀 조합이 하나로 연결될 수 있는 지 구함.
