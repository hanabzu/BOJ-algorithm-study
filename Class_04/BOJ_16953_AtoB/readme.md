### BOJ_16954 A→B

queue를 사용해 BFS로 풀이. 처음에 int형으로 했을 때 틀렸는데 long long형으로 바꾸니 해결됨.

`v[1] = u * 10 +1`할때 overflow가 나서  `if (v[i] < B)`에 걸려 큐에 계속 들어갔기 때문으로 생각됨.