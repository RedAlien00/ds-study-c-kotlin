#pragma once

typedef struct SLL_NODE {
	void* data;
	struct SLL_NODE* pNext;
} SLL_NODE;

typedef struct SLL {
	int totalCount;

	SLL_NODE* pHead;
	SLL_NODE* pTail;
} SLL;

// Single Linked List 생성
SLL* sll();

// Single Linked List 노드 생성
SLL_NODE* sll_node(void*);

// Single Linked List에 노드 추가
// 인자로 데이터 받으면 내부에서 노드 생성해서 추가
void sll_add(SLL*, void*);

// Single Linked List 첫 번쨰 노드 추출
SLL_NODE* sll_getFirstOrNull(SLL*);

void sll_print(SLL*);

// Single Linked List empty 여부
int sll_isEmpty(SLL*);

// Single Linked List 메모리 해제
void sll_destroy(SLL*);