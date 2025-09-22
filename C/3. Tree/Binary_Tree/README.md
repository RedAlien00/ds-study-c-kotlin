## 🧪 이진 트리 구조도
<img width="470" height="299" alt="스크린샷 2025-09-18 오후 2 06 10" src="https://github.com/user-attachments/assets/9d4c1b37-b796-40b6-812b-7a5a9ce6edf4" />

<br>

## 🧪 Binary Tree 구현 과정에서 시도한 것
```C
void printTree(TREE* tree, ORDER order) {
	switch (order) {
		case PREORDER: 
			preorderPrint(tree->pRoot);		
			break;
		case INORDER: 
			inorderPrint(tree->pRoot);
			break;
		case POSTORDER: 
			postorderPrint(tree->pRoot);	
			break;
	}
    printf("\n");
}
```
- 초기에는 위의 코드와 같이 전위, 중위, 후위 순회하면서 바로 출력하도록 구현

<br>

```c
void printTree(TREE* tree, ORDER order) {
	SLL* pSll = sll();
		
	switch (order) {
		case PREORDER: 
			preorderTraversal(tree->pRoot, pSll);		
			break;
		case INORDER: 
			inorderTraversal(tree->pRoot, pSll);
			break;
		case POSTORDER: 
			postorderTraversal(tree->pRoot, pSll);	
			break;
	}
    sll_print(pSll);
	sll_destroy(pSll);
}
```

- 현재는 위의 코드와 같이 전위, 중위, 후위 순회 결과를 SLL 자료 구조에 저장하여 리턴 하도록 수정
    - 덕분에 후위 순회 함수를 `destroyTree()` 내부에서 재사용 할 수 있었음

<br>

## ⚠️ 주의 사항

```c
typedef struct SLL_NODE {
	void* data;
	struct SLL_NODE* pNext;
} SLL_NODE;

typedef struct BT_NODE {
	int pData;

	struct BT_NODE* pLeft;
	struct BT_NODE* pRight;
} BT_NODE;

void sll_print(SLL* sll) {
	SLL_NODE* pTemp = sll->pHead;

	for (size_t i = 0; i < sll->totalCount; i++) {
		printf("%d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}
```

- 본문에 사용된 `sll_print()`는 내부에서 `printf("%d  ", pTemp->data);`로 데이터를 출력하고 있다
- 하지만 `pTemp->data`는 `BT_NODE` 타입인데도 정상 출력되는 이유는 `BT_NODE` 타입의 시작이 int이기 때문이다
- 때문에 `printf("%d  ", pTemp->data);`에서 int 크기인 4byte 만큼만 읽기에 정상 출력되는 것이다
- 위험한 방식이나, 의도한 대로 동작하기에 더 수정하지 않았다


