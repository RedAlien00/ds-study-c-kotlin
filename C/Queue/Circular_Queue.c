
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

QUEUE* Queue(int capacity) {
	QUEUE* q = (QUEUE*)calloc(1, sizeof(QUEUE));

	q->capacity = capacity;
	q->totalCount = 0;
	q->pArray =  calloc(capacity, sizeof(void*)); // 6이라면 6칸 배열 생성
	q->front = 0;
	q->rear = 0;
	return q;
}

void enque(QUEUE* q, void* data) {
	if (q->capacity == q->totalCount) {
		printf("용량 초과입니다\n");
		return;
	}
	q->pArray[q->rear] = data;
	printf("enque : array[%d] = %p\n", q->rear, data);
	q->totalCount++;
	if (++q->rear == q->capacity) {  // idx값 초과 시, 0으로 초기화
		q->rear = 0;
	}
}

void* deque(QUEUE* q) {
	if (q->totalCount == 0) {
		printf("추출할 요소가 없습니다\n");
		return;
	}

	void* out = q->pArray[q->front];
	printf("deque : array[%d] = %p\n", q->front, out);

	q->totalCount--;
	if (++q->front == q->capacity) {  // 더미 노드에 도달 시, 0으로 초기화
		q->front = 0;
	}
	return out;
}

int getCount(QUEUE* q) {
	return q->totalCount;
}

void destroyQueue(QUEUE* q) {
	free(q->pArray);
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
	deque(q);

	printf("total : %d\n", q->totalCount);
	destroyQueue(q);
}