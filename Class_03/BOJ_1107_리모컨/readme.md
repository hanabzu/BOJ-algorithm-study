### BOJ_1107 리모컨

brute force 방식으로 모든 가능한 채널 숫자를 찾음.

쓸 수 있는 버튼은 `set<string> deck`으로, 가능한 채널 조합까지 걸리는 클릭 수는 `set<int> candidate`에 저장함.

채널 조합은 `makeNum()`을 재귀적으로 활용해 구하며, 목표 채널의 자릿수-1 부터 자릿수+1까지 3가지 자릿수에 대해 모두 구함.

`int hard`는 채널 버튼 클릭 없이 +-버튼으로 이동하는 숫자이며, `candidate`가 비었거나 `candidate`의 최소값보다 `hard`가 작다면 `hard`를 출력함.

`makeNum()`은 string에 각 버튼을 붙여가면서 자리수를 줄여가며 재귀적으로 구하였는데 string 연산 때문인지 시간이 매우 오래걸림.

