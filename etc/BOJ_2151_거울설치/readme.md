### BOJ_2151 거울 설치

bfs로 풀이.

`visit`배열을 4방향에 대해 만들고, `queue`가 아닌 `priority_queue`를 사용하여 `cnt`가 작은 노드부터 꺼내주어야 함.
