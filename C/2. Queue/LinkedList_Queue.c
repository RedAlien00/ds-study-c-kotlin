
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

QUEUE* Queue(int capacity) {
	QUEUE* q = (QUEUE*) calloc(1, sizeof(QUEUE));

	q->totalCount = 0;
	q->pFront = NULL;
	q->pRear = NULL;
	return q;
}

void enque(QUEUE* q, void* pData) {
	NODE* pNode = (NODE*) calloc(1, sizeof(NODE));
	pNode->data = pData;
	pNode->pPrev = NULL;

	if (q->pFront == NULL) {
		q->pFront = pNode;
		q->pRear = pNode;
	}
	else {
		NODE* pTemp = q->pRear;
		pTemp->pPrev = pNode;
		q->pRear = pNode;
	}
	q->totalCount++;
}

void* deque(QUEUE* q) {
	if (q->totalCount == 0) {
		printf("추출할 요소가 없습니다\n");
		return NULL;
	}
	NODE* pTemp = q->pFront;
	q->pFront = pTemp->pPrev;
	q->totalCount--;
	return pTemp;
}

int getCount(QUEUE* q) {
	return q->totalCount;
}

void destroyQueue(QUEUE* q) {
	NODE* pTemp = q->pFront;
	NODE* pPrev = NULL;

	for (size_t i = 0; i < q->totalCount; i++) {
		NODE* pPrev = pTemp->pPrev;
		free(pTemp);
		pTemp = pPrev;
	}
	free(q);
	return;
}

int main() {
	ORDER orders[] = {
		1, "새우버거",
		2, "불고기버거",
		3, "감자버거",
		4, "더블버거",
		5, "치즈버거",
	};

	QUEUE* q = Queue(5);

	enque(q, &orders[0]);
	enque(q, &orders[1]);
	enque(q, &orders[1]);
	deque(q);
	deque(q);
	deque(q);
	deque(q);
	enque(q, &orders[1]);


	printf("total : %d\n", q->totalCount);
	destroyQueue(q);
}