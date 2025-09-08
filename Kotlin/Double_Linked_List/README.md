## 🧪 구현 과정에서 시도한 것
- Node를 상위 타입으로 정의, 데이터를 담는 객체들을 하위 타입으로 정의 시도
    - 이처럼 구현할 경우 -> List 인터페이스의 `val head: Node`, `val tail: Node`는 SOLID의 DIP 원칙 위반
    - 때문에 Node를 interface로 변경하였음 = 구현체가 아닌 추상체에 의존하도록 변경
    - 또한 상속으로 구현할경우, 객체들끼리의 불필요한 의존성 + 복잡성이 야기됨

<br>

- 초기에는 `List → Node → Data` 구조로 구현을 시도
    - C에서 구현했던 방식과 동일하게 접근했으나 실패함
    - `List → Node → Data` 구조에서는 `Node.Data.속성` 형태의 직접 접근이 불가능했음
- 현재는 `List → Node` 구조로 단순화
    - Node는 인터페이스 형태로 정의해 둔 상태   
    - Node를 상위 타입, 데이터를 하위 타입으로 정의하였다면 캐스팅을 통해 속성 접근에 가능하였을 것임


## 구조
1. `List` 인터페이스 ( ADT )
    - C의 DDL과 동일하게 더미 헤드/테일 구현
    - C의 경우, Data 주소를 갖고 있는 Node 구조체가 List에 담겼다
       - List - Node - Data
    - Kotlin은 Data를 갖는 Node 구현 객체가 바로 List에 담기는 형태
       - List - Data   
2. `Node` 인터페이스
    - 이전/다음 객체를 가리키는 next, prev
    - Node의 Key를 가져오는 getKey()
    - 상속 관계를 고민하였으나 인터페이스로 구현

<br>

## 특징
  - 더미 노드(head, tail)를 사용하여 구현 단순화
  - 다양한 데이터 타입을 수용할 수 있도록 key 추출 함수 지원
