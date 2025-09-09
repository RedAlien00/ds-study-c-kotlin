



## 🧪 SLLStack 구현 과정에서 시도한 것
- 초기에는 DLL로 Stack 구현 시도 ( `DLLStack - DLL - NODE` )
    - `NODE->prev`는 사용하나 `NODE->next`는 사용할 일이 없었음
    - `DLLStack->Top`에만 접근하면 되기에 `DLL->Head`, `DLL->Tail` 노드 또한 불필요해짐 
- 현재는 SLL로 Stack 구현 단순화 ( `SLLStack - NODE` )
    - 중간에 위치하던 DLL 계층을 없애고 `SLLStack - NODE` 구조로 단순화 
    - `DLL->Head`, `DLL->Tail`을 없애고 남아있던 `DLL->Total`을 SLLStack으로 옮겨 DLL 제거
	- 단순화 덕분에 메모리 해제 코드도 간결해짐

<br>


## SLLStack 구조
1. `SLLStack - NODE`
    - SLLStack은 속성으로 가진 top에만 접근, 속성으로 노드의 total 값을 가지고 있음
    - NODE는 속성으로 `void*` 타입의 데이터를 가짐, 이전 `NODE*`를 가리키는 prev를 가짐 
