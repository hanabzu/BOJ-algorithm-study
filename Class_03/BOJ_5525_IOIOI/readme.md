### BOJ_5525 IOIOI

finite automata로 해결함.

statement는 총 3개로, final statement 는 변수 `stmt = 1 or 2`일 때임.

간단하게 문자열을 모두 순회하며 문자를 하나씩 보고 statement를 if문으로 옮겨가며 IOI(OI)*의 길이를 len에 저장하고, 만약 reject가 나면 result에 `len - n  + 1`을 더한 뒤 statement를 옮기고 len을 0으로 초기화 한 후 이를 계속 반복함.

처음에 틀렸던 이유는 단순히 for문에서 조건을 `i < m`으로 했기 때문으로, `i < m + 1`로 바꾸어 해결함.