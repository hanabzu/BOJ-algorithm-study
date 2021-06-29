### BOJ_18870 좌표 압축

vector와 set 사용한 lower_bound로 풀이함.

처음엔 vector로만 풀이했으나 중복제거를 생각하지 못해서 오답.

이후 set으로 풀이했으나 `distance()`함수의 시간복잡도가 O(n)이어서 시간 초과로 오답.

결국 처음엔 set에 input을 집어넣고 iterator로 모든 원소를 다시 vector에 넣은 다음 풀이함.

다른 사람 코드를 보니 `unique()`를 사용했던데 다음에 활용해봐야겠음.