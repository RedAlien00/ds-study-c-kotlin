#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"

ARRAYSTACK* arrayStack(int capacity) {
	if (0 >= capacity) return NULL;
	
	NODE* nodes = (NODE*)calloc(capacity, sizeof(NODE));
	ARRAYSTACK* as = (ARRAYSTACK*)calloc(1, sizeof(ARRAYSTACK));

	as->capacity = capacity;
	as->nodes = nodes;
	as->top = -1;
	return as;
}

void push(ARRAYSTACK* as, NODE node) {
	if (as->capacity == as->top + 1) {
		printf("용량 초과\n");
		return;
	}
	as->top++;
	as->nodes[as->top] = node;
}

NODE pop(ARRAYSTACK* as) {
	if (as->top == -1) {
		printf("더 이상 pop할 요소가 없습니다\n");
		return;
	}
	NODE node = as->nodes[as->top];
	as->top--;
	return node;
}

void destroyStack(ARRAYSTACK* as) {
	free(as->nodes);
	free(as);
	return;
}

int main() {
	STUDENT students[] = {
		{ 3, "정왕왕" },
		{ 43, "김꽊꽊" },
		{ 29, "박멍멍" }
	};
	
	NODE nodes[3] = { 0 };
	for (size_t i = 0; i < 3; i++) {
		NODE node = { &(students[i]) };
		nodes[i] = node;
	}
	ARRAYSTACK* as = arrayStack(3);

	push(as, nodes[0]);
	push(as, nodes[1]);
	push(as, nodes[2]);

	NODE test1 = pop(as);
	STUDENT* a1 = (STUDENT*)test1.data;
	printf("%s\n", a1->name);

	destroyStack(as);
}	


