### BOJ_2667 단지번호붙이기

이중 배열을 동적할당하여 자료구조로 이용, 외곽을 padding하여 쉽게 구하도록 하였음.

`findBlock()`함수는 매트릭스의 인덱스를 인자로 받아 현재 인자를 지났음을 표기하고 상하좌우 네 방향에 대해 재귀적으로 실행하여 연결된 인덱스들을 모두 구해 return한다.

이 때 단지가 없음은 0, 단지 있음은 1, 탐색한 지점은 2로 할당한다. (padding에서도 2로 할당)

그래프 이론을 아직 제대로 구현해본적이없어서 미숙한 것 같다.