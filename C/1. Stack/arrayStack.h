#pragma once
typedef struct STUDENT {
	int age;
	char* name;
}STUDENT ;

typedef struct NODE {
	void* data;
} NODE;

typedef struct ARRAYSTACK {
	int capacity;  // 스텍 최대 용량
	int top;       // index
	NODE* nodes;   // NODE 배열 
} ARRAYSTACK;

// stack 생성 : 최대 용량을 인자로
ARRAYSTACK* arrayStack(int );

void push(ARRAYSTACK*, NODE*);

NODE pop(ARRAYSTACK*, NODE*);

void destroyStack(ARRAYSTACK*);
