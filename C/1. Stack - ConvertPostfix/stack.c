#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


STACK* Stack() {
	STACK* stack = (STACK*) calloc(1, sizeof(STACK));
	stack->top = NULL;
	stack->totalCount = 0;
	return stack;
}

NODE* Node(void* data) {
	NODE* node = (NODE*)calloc(1, sizeof(NODE));
	node->data = data;
	node->prev = NULL;
	return node;
}

void push(STACK* pStack, void* pData) {
	NODE* newNode = Node(pData);
	
	if ( isEmpty(pStack) ){
		pStack->top = newNode;
		pStack->totalCount++;
		return;
	}
	NODE* temp = pStack->top;
	pStack->top = newNode;
	newNode->prev = temp;
	pStack->totalCount++;
}

NODE* pop(STACK* pStack) {
	if (isEmpty(pStack) ) return NULL;

	NODE* outNode = pStack->top;
	pStack->top = outNode->prev;
	pStack->totalCount--;

	return outNode;
}

int isEmpty(STACK* pStack) {
	return pStack->totalCount == 0;
}