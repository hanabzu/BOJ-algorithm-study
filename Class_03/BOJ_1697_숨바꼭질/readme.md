### BOJ_1697 숨바꼭질

<img src="https://user-images.githubusercontent.com/76643387/123835814-f4ead900-d943-11eb-9a82-1da300f57647.png" alt="image" style="zoom: 80%;" />

문제의 조건에 맞는 그래프는 이런 형태이므로, queue를 사용해 BFS로 풀이하였음.

처음엔 set으로 found된 수들을 저장했으나 메모리 초과가 일어났고, bool 형 배열로 found 정보를 저장함.

이 경우 boundary check를 잘 해주어야 했음. q에서 pop된 수 u에 대해서 그래프에서 연결된 수들인 u-1, u+1, u<<1 를 체크하므로, 각 숫자가 0 이상이며 100,000 이하인 것을 체크해야 함.

결과인 시간은 `q.size()`를 저장하면서 체크함. (BOJ_7569 토마토와 같은 방법)