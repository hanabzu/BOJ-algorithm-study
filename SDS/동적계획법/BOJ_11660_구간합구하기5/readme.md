### BOJ_11660 구간 합 구하기 5

matrix의 0행과 0열은 0으로 padding한 후, NxN까지 각 원소에 누적합을 저장함.

즉, `matrix[i][j] = 입력값 - matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i][j - 1]`임.

(x1, y1) ~ (x2, y2) 까지의 값은 `matrix[x2][y2] + matrix[x1-1][y1-1] - matrix[x1-1][y2] - matrix[x2][y1-1]`임.