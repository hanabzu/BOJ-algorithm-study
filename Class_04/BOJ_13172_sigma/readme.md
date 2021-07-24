### BOJ_13172 Σ

divide and conquer 방식으로 거듭제곱을 구하는 함수 `power()`를 설계해 `bi = power(N, PRIME-2)` 로 b^-1을 구함. (여기서 PRIME = 1000000007)

그 후 `(S * bi) mod PRIME`을 result에 더해가며 최종 답을 구함.