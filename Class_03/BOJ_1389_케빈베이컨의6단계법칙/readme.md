### BOJ_1389 케빈 베이컨의 6단계 법칙

케빈 베이컨의 수는 BFS에서 구해진 각 vertex의 rank의 합으로 계산하였음.

이전 그래프 문제들을 풀때와는 다르게 N의 최대가 100이기 때문에 adjacent list를 사용하지 않고 matrix를 사용함. 

BFS 과정에서 각 vertex의 rank는 parent의 rank+1임.