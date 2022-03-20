### BOJ_1202 보석 도둑

priority queue 사용한 greedy algorithm으로 구현.

처음에 multiset 대신 단순 array를 사용했는데 시간초과.

이유는 bool visit 배열로 사용한 가방을 제외해줬을 때 사용한 가방을 제외한 lower bound를 찾는 데에 시간이 오래 걸렸기 때문.
