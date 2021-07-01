### BOJ_5430 AC

이중 연결 리스트인 STL list 사용함.

오히려 어려웠던 부분은 문자열 파싱인데 npos와 size_t를 적절히 사용해서 `num_list`에 추가함.

R이 명령어로 들어올 때마다 `bool reverse`를 반전시켜 리스트를 뒤집는 것을 구현하였음.

최종 리스트를 출력할 때에도 `reverse`에 따라 출력함.

`rbegin()`, `rend()`를 처음 사용해봤는데 `iterator`도 `reverse_iterator`로 정의해야했음.

