## 🧪 ArrayStack 구현 과정에서 시도한 것
- 초기에는 `Stack - Array - Node - Data` 순으로 구현 시도
    - Array 요소로 동일한 타입이 오게끔 Node 클래스를 구현하였으나
    - Array<Any?>로 대체하여 Node 클래스 삭제
- 현재는 `Stack - Array - Data`로 구현 단순화

<br>

- 초기에는 totalNode: Int, top: Int 두 가지 속성 정의
- 현재는 top: Int 한 가지 속성만 남김
    - top + 1은 totalNode와 같기에 top 속성만 남기고 totalNode 삭제 
    - 정의된 top: Int 속성을 통해  myArray[top] 식으로 top에 접근

<br>

## 🧪 SLLStack 구현 과정에서 시도한 것
- 초기에는 `Stack - Node - Data` 순으로 구현 시도
    - Node 객체가 Data 객체를 갖게끔 시도
    - but 불필요한 계층이 1개 더 생기는 거 같아 Node 클래스 삭제
    - 또한 Node.Data가 갖는 데이터를 출력하는 함수 구현 과정에서 복잡성 증가
- 현재는 `Stack - Data: Node`으로 단순화
    - Stack에 넣을 Data는 Node 인터페이스만 구현하도록하여 설계 -> Stack에 Data 객체가 직접 들어감
    - Data 객체가 직접 들어가기에 계층 단순화
    - 이로 인해 Data가 갖는 데이터를 출력하는 함수 구현 복잡성 감소
    - Node 인터페이스는 prev 속성만 정의되어 있음
