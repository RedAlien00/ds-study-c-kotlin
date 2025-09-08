
#pragma once

typedef struct {
	char* name;
	int age;
	float height;
} STUDENT;

typedef struct {
	void* data;
	struct NODE* pNext;
	struct NODE* pPrev;
} NODE;

typedef struct {
	NODE* pHead;
	NODE* pTail;
	int totalCount;
	char* (*getKey)(NODE*);
} LIST;

// Student 객체 생성
STUDENT* Student(const char*, const int, const float);

// Student 객체 Key 가져오기
const char* getStudentKey(const STUDENT*);

// 0. initList 
void DLL_initList(LIST*, const char* (*)(NODE*) );
// 1. 리스트 비었는지 여부 체크
int DLL_isEmpty(LIST*);
// 2. 노드 생성
NODE* DLL_createNode(void*);
// 3. 노드 소멸 ( Destroy )
void DLL_destroyNode(NODE*);
// 4. 노드 헤드 뒤에 추가
void DLL_appendAfterHead(LIST*, NODE*);
// 5. 노드 테일 앞에 추가 
void DLL_appendBeforeTail(LIST*, NODE*);
// 6. 노드 삽입 ( 특정 노드 뒤에 )
void DLL_insertAfterAt(LIST*, NODE*, NODE*);
// 7. 노드 제거 ( remove )
void DLL_removeNode(NODE*);
// 8. 노드 가져오기 
NODE* DLL_getNodeAt(LIST*, int);
// 9. 노드 개수 세기
int DLL_getNodeTotalCount(LIST*);
// 10. 출력
void DLL_print(LIST*);