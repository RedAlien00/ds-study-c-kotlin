#pragma once
typedef struct NODE {
	void* data;
	struct NODE* pPrev;
} NODE;

typedef struct QUEUE {
	int totalCount;
	NODE* pFront;
	NODE* pRear;
} QUEUE;

typedef struct ORDER {
	int number;
	char* str;
} ORDER;


QUEUE* Queue(int);

void enque(QUEUE*, void*);

void* deque(QUEUE*);

int getCount(QUEUE*);

void destroyQueue(QUEUE*);