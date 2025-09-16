## 🧪 Circular Queue 구현 과정에서 시도한 것
- 기존 : Dummy 노드를 사용하여 순환 큐 구현 시도
    - `Head와 == Tail`일 경우, 공백 상태 판별
    - Head와 Tail이 Dummy 노드를 만날 시, 0으로 초기화( 배열의 첫 번째 index )
- 현재 : Dummy 노드 대신 TotalCount로 대체
    - Dummy 노드를 위한 `Array 크기 = Capacity( 총 용량 ) + 1` 하던 비효율 삭제
    - 기존 TotalCount를 가져오던 복잡한 코드 단순화
    - 기존 TotalCount 방식 : Rear와 Tail 연산 조합 -> 코드 증가
    - 현재 TotalCount 방식 : TotalCount 값만 가져오는 방식 
