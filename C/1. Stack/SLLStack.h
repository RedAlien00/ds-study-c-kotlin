#pragma once

typedef struct STUDENT {
	char* name;
	int age;
} STUDENT;

typedef struct NODE {
	void* data;
	struct NODE* prev;
} NODE;

typedef struct SLLSTACK {
	int total;
	NODE* top;
} SLLSTACK;


SLLSTACK* sllStack();

void push(SLLSTACK*, NODE*);

NODE* pop(SLLSTACK*);

NODE* node(void*);

void destroyStack(SLLSTACK*);