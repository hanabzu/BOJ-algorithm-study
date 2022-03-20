### BOJ_7453 합이 0인 네 정수

binary search로 구현. STL의 upper_bound(), lower_bound() 사용.

ab 벡터와 cd 벡터로 나눈 후 계산하였는데 cd만 정렬했을 때보다 ab도 정렬했을때 시간이 약 1/3정도로 단축됨.

이는 memory cache hit에 관련된 것으로 보임.

ab도 정렬되었을 때 비슷한 숫자를 연속적으로 cd에서 search하기 때문에 page 교체가 덜 일어난다고 볼 수 있음.