### BOJ_9375 패션왕 신해빈

STL `map` 자료형을 사용하여 구현하였음.

옷의 이름은 중요하지 않고 종류만 중요하므로 <옷 종류, 옷 개수> 를 저장함

처음엔 algorithm 헤더의 `next_permutation()`과 vector를 사용해 모든 조합을 계산하는 것으로 구현하였으나 시간초과.

대신 각 옷 종류마다 옷 개수에 옷을 입지 않은 경우의 수인 1을 더하여 모든 옷 종류의 개수를 곱해주는 것으로 계산하여 통과하였음.

이 과정에서는 iterator 사용하였음.

옷을 하나도 입지않은 경우는 제외해줘야 하므로 얻어낸 값에서 -1을 해주어야 함.

조합에 대한 수학적인 센스가 필요한 문제였음.