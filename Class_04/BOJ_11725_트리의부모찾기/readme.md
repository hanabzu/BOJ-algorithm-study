### BOJ_11725 트리의 부모 찾기

DFS 활용해서 adjacent list의 각 child node들의 parent를 현재 node로 지정한 후 재귀적으로 child node들의 child node에 대해서 반복함.

root node는 제외해주기 위해서 `parent[1] = -1`로 두었음.

`parent[n] == 0`이라면 아직 search되지 않은 노드임.