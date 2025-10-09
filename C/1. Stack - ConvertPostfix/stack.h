#pragma once

typedef struct NODE {
	void* data;
	struct NODE* prev;
} NODE;

typedef struct STACK {
	NODE* top;
	int totalCount;
} STACK;

STACK* Stack();

NODE* Node(void* data);

void push(STACK*, void*);

NODE* pop(STACK*);

int isEmpty(STACK*);