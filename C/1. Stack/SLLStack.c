#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"

SLLSTACK* sllStack() {
	SLLSTACK* pSllStack = (SLLSTACK*)calloc(1, sizeof(SLLSTACK));

	pSllStack->top = NULL;
	pSllStack->total = 0;

	return pSllStack;
}

void push(SLLSTACK* pSllStack, NODE* pNewTop) {
	NODE* pOldTop = pSllStack->top;
	pSllStack->top = pNewTop;
	pNewTop->prev = pOldTop;

	pSllStack->total++;
}

NODE* pop(SLLSTACK* pSllStack) {
	if (pSllStack->top == NULL || pSllStack->total == 0) {
		printf("pop할 요소가 없습니다\n");
		return NULL;
	}
	NODE* pOldTop = pSllStack->top;
	NODE* pNewTop = pOldTop->prev;
	pSllStack->top = pNewTop;
	pSllStack->total--;

	return pOldTop;
}


NODE* node(void* data) {
	NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
	newNode->data = data;

	return newNode;
}

void destroyStack(SLLSTACK* pSllStack) {
	NODE* temp = NULL;
	while( pSllStack->top != NULL ) {
		temp = pop(pSllStack);
		free(temp);
	}
	free(pSllStack);
}

int main() {
	NODE* pNodes[3] = { 0 };
	STUDENT students[3] = {
		{"김꿀꿀", 3},
		{"박꽉꽉", 5},
		{"전어흥", 78}
	};

	for (size_t i = 0; i < 3; i++) {
		NODE* node1 = node(&students[i]);
		pNodes[i] = node1;
	}

	SLLSTACK* sllStack1 = sllStack();
	
	push(sllStack1, pNodes[0]);
	push(sllStack1, pNodes[1]);
	push(sllStack1, pNodes[2]);

	NODE* result1 = pop(sllStack1);
	STUDENT* student1 = (STUDENT*)result1->data;
	printf("노드 이름 : %s\n", student1->name);
	
	NODE* result2 = pop(sllStack1);
	STUDENT* student2 = (STUDENT*)result2->data;
	printf("노드 이름 : %s\n", student2->name);

	printf("total : %d\n", sllStack1->total);
	printf("top : %p\n", sllStack1->top);
	printf("top->prev : %p\n", sllStack1->top->prev);

	destroyStack(sllStack1);
}