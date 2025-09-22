#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Single Linked List 생성
// pHead : 가장 앞단 노드 주소를 가짐
// pTail : 가장 뒷단 노드 주소를 가짐
SLL* sll() {
	SLL* sll = (SLL*)calloc(1, sizeof(SLL));
	sll->totalCount = 0;
	sll->pHead = NULL;
	sll->pTail = NULL;
	return sll;
}

// Single Linked List 노드 생성
SLL_NODE* sll_node(void* data) {
	SLL_NODE* pSll_node = (SLL_NODE*)calloc(1, sizeof(SLL_NODE));
	pSll_node->data = data;
	pSll_node->pNext = NULL;
	return pSll_node;
}

// Single Linked List에 노드 추가
// 인자로 데이터 받으면 내부에서 노드 생성해서 추가
void sll_add(SLL* pSll, void* data) {
	SLL_NODE* pNewNode = sll_node(data);

	if (sll_isEmpty(pSll)) {
		pSll->pHead = pNewNode;
		pSll->pTail = pNewNode;
		pSll->totalCount++;
		return;
	}
	pSll->pTail->pNext = pNewNode;
	pSll->pTail = pNewNode;
	pSll->totalCount++;
}

// Single Linked List 첫 번쨰 노드 추출
SLL_NODE* sll_getFirstOrNull(SLL* pSll) {
	if (sll_isEmpty(pSll)) return NULL;

	SLL_NODE* pTemp = NULL;
	if (pSll->pHead == pSll->pTail) {  // 노드 1개만 존재할 때
		pTemp = pSll->pHead;
		pSll->pHead = NULL;
		pSll->pTail = NULL;
		pSll->totalCount--;
		return pTemp;
	}
	pTemp = pSll->pHead;
	pSll->pHead = pTemp->pNext;
	pSll->totalCount--;
	return pTemp;
}

void sll_print(SLL* sll) {
	SLL_NODE* pTemp = sll->pHead;

	if (pTemp == NULL) {
		printf("sll is empty !\n");
		return;
	}
	for (size_t i = 0; i < sll->totalCount; i++) {
		printf("%d  ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

// Single Linked List empty 여부
int sll_isEmpty(SLL* pSll) {
	return pSll->pHead == NULL && pSll->pTail == NULL;
}

// Single Linked List 메모리 해제
void sll_destroy(SLL* pSll) {
	if (pSll->totalCount == 0) return;

	SLL_NODE* pTemp = NULL;
	for (size_t i = 0; i < pSll->totalCount; i++) {
		pTemp = sll_getFirstOrNull(pSll);
		free(pTemp);
	}
}