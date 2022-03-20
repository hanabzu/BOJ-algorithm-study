### BOJ_14476 최대공약수 하나 빼기

left부터 gcd 저장, right부터 gcd 저장 후 i 번째 숫자를 뺀 경우엔 `gcd(left[i-1], right[i+1])`가 나머지의 gcd.
