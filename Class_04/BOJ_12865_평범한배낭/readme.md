### BOJ_12865 평범한 배낭

dynamic programming table 사용해서 구현.

1~i 번째 물품들에서 특정한 weight w 이내의 최대 value = max(1~i-1 번째 물품들에서 w 이내의 최대 value,  i물품 value + 1~i-1번째 물품들에서 w - i번째 물품 weight 이내의 최대 value)