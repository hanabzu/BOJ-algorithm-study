### BOJ_7569 토마토

padding 한 3차원 배열을 정적할당하여 자료구조로 이용함.

BFS에 필요한 방향 정보는 dir배열에 xyz coordinate system으로 표현함.

queue의 element는 이중 pair로 지정하여, 3개의 좌표 정보를 저장할 수 있도록 함.

원소를 읽는 과정에서 padding된 외곽 부분을 0으로 하기 위해 각 input에 +1하여 2가 익은 토마토, 1이 아직 익지 않은 토마토로 표현함.

`num_tomatoes`는 박스의 전체 토마토 개수이며, `ripe`는 현재 익은 토마토의 개수로, BFS가 끝난 후 두 변수를 비교해 다르다면 모두 익지 못했으므로 -1을 출력함.

`day`는 모두 익는 데에 필요한 시간으로 initialize된 queue의 원소 개수를 `q_count`에 저장하여 한번 `pop()`을 시행할 때마다 `q_count--`하며, `q_count == 0`이 되면 `day++`한 후 현재 queue 상황에서 새로 `q_count`를 구함.

이렇게 하면 마지막에 하루가 더 추가되기 때문에 최종에는 `--day`로 출력함.

