### BOJ_1764 듣보잡

STL set을 사용하여 듣도 못한 사람들을 먼저 읽어 저장한 후,  듣도 보도 못한 사람을 읽으면서 듣도 못한 사람들의 set `unheard`에서 `unheard.count(name)`을 통해 찾고, 있다면 듣도 보도 못한 사람들의 set `unknown`에 저장한다.

최종적으로 `unknown`의 모든 원소들을 출력한다. 

set을 사용해 자동으로 sort된 결과를 얻을 수 있었으며, 아예 `set<string>`의 이터레이터 자료형의 set (`set<set<string>::iterator>::iterator`)을 사용해 보려고 시도하였으나 참조의 문제인지 컴파일 에러로 실패했다. (C2676)

