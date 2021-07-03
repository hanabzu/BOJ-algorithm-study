### BOJ_2407 조합

조합 공식으로 풀이하면 C++에서는 `unsigned long long`자료형으로도 표현이 불가능함. (100C50과 같은 경우 매우 큰 수임)

대신 파이썬은 integer의 범위제한이 없으므로 조합 공식으로도 간단하게 풀이가 가능하였음.

C++로 풀이하기 위해서 `BigInt class`를 설계하여 **string으로 범위 제한 없는 integer**를 표현함.

string 으로 값을 저장하는 특성 상 곱하기와 나눗셈 계산이 매우 어려우므로 조합 공식으로는 풀이가 힘듬.

그렇기 때문에 간단한 더하기 연산만 설계하고, **하단의 파스칼의 삼각형**을 사용해서 recursive한 `combination()`함수를 설계하였으며, 

중복된 계산을 막기 위해 `BigInt` 객체의 memoization 2차원 배열을 사용해 dynamic programming 하였음.

![image](https://user-images.githubusercontent.com/76643387/124358706-77350f00-dc5c-11eb-90d6-cf6efe0898f0.png)