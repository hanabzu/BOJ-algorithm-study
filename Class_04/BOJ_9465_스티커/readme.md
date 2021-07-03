### BOJ_9465 스티커

memoization 배열 활용해서 풀이.

두 라인의 n번째 스티커를 떼는 최대값을 `memo[line][n]`에저장해가면서 최종 결과를 찾음.

value가 0일 수도 있는 점을 생각해서 bool 배열을 활용해서 매 test case마다 초기화하며 memoization을 체크해줌.

줄바꿈을 안해서 계속 틀렸었음. 제대로 확인할 것.

