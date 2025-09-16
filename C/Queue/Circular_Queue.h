#pragma once

typedef struct QUEUE {
	int capacity;
	int totalCount;
	void** pArray;

	int front;
	int rear;
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