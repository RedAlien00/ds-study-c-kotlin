
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C_test.h"

#define NULLCHECK1(x) if(x == NULL) return;
#define NULLCHECK2(x, y) if(x == NULL || y == NULL) return;

int main()
{
    LIST list = { 0 };
    DLL_initList(&list, getStudentKey);

    STUDENT studentsData[4] = {
        {"김현수", 13, 178.6},
        {"박갑갑", 50, 160.5},
        {"송태훈", 66, 171.1},
        {"함태훈", 70, 169.7}
    };

    STUDENT* students[4];
    NODE* nodes[4];

    for (size_t i = 0; i < 4; i++) {
        students[i] = Student(studentsData[i].name, studentsData[i].age, studentsData[i].height);
        nodes[i] = DLL_createNode(students[i]);
    }

    // 박갑갑, 송태훈, 김현수, 함태훈
    DLL_appendAfterHead(&list, nodes[0]);
    DLL_appendAfterHead(&list, nodes[1]);
    DLL_insertAfterAt(&list, nodes[1], nodes[2]);
    DLL_appendBeforeTail(&list, nodes[3]);

    printf("Node TotalCount: %d\n", DLL_getNodeTotalCount(&list));
    DLL_print(&list);
}

// STUDENT 객체 생성
STUDENT* Student(const char* name, const int age, const float height) {
    STUDENT* student = (STUDENT*) calloc(1, sizeof(STUDENT));
    NULLCHECK1(student);  // 동적 할당 실패 시, return
   
    student->name = name;
    student->age = age;
    student->height = height;
    return student;
}

// 설계 의도 : 리스트 순회하며, 각 노드들이 list->getKey(NODE* node)
// node->data로 node가 갖고있는 데이터 접근
// getStudentKey는 STUDENT 데이터 전용 
const char* getStudentKey(const NODE* node) {
    // Node의 다른 타입 data가 들어갈 경우, 타입만 변경하면 됨
    // Ex) PRODUCT* product = (PRODUCT*)node->data;
    STUDENT* student = (STUDENT*)node->data;
    return student->name;
}

// 0. LIST 초기화
void DLL_initList(LIST* list, const char* (*getKey)(NODE*) ) {
    NODE* pHead = (NODE*)calloc(1, sizeof(NODE));
    NODE* pTail = (NODE*)calloc(1, sizeof(NODE));
    NULLCHECK2(pHead, pTail);  // 동적 할당 실패 시, return

    pHead->pNext = pTail;
    pTail->pPrev = pHead;

    list->pHead = pHead;
    list->pTail = pTail;
    list->totalCount = 0;
    list->getKey = getKey;
}

// 1. LIST 비었는지 여부 체크 
int DLL_isEmpty(LIST* list) {
    return list->pHead->pNext == list->pTail || list->totalCount == 0;
}

// 2. 노드 생성
NODE* DLL_createNode(void* data) {
    NODE* node = (NODE*) calloc(1, sizeof(NODE));
    NULLCHECK1(node);

    node->data = data;
    return node;
}

// 3. 노드 제거 ( 리스트에서 노드 제거 )
void DLL_removeNode(NODE*);

// 4. 노드 소멸 ( 동적 할당 해제 )
void DLL_destroyNode(NODE* node) {
    free(node);
}

// 5. 노드 헤드 뒤에 추가
void DLL_appendAfterHead(LIST* list,  NODE* node) {
    NODE* pTemp = NULL;
    NODE* pHead = list->pHead;
    pTemp = pHead->pNext;

    pHead->pNext = node;
    node->pPrev = pHead;

    node->pNext = pTemp;
    pTemp->pPrev = node;

    list->totalCount++;
}

// 6. 노드 테일 앞에 추가
void DLL_appendBeforeTail(LIST* list, NODE* node) {
    if (DLL_isEmpty(list)) {
        DLL_appendAfterHead(list, node);
        return;
    }
    NODE* pTemp = NULL;
    NODE* pTail = list->pTail;
    pTemp = pTail->pPrev;

    pTail->pPrev = node;
    node->pNext = pTail;

    node->pPrev = pTemp;
    pTemp->pNext = node;
    
    list->totalCount++;
}

// 7. 노드 삽입 ( 특정 노드 뒤에 )
void DLL_insertAfterAt(LIST* list, NODE* pTargetNode, NODE* pNewNode) {
    NODE* pTemp = NULL;
    pTemp = pTargetNode->pNext;

    pTargetNode->pNext = pNewNode;
    pNewNode->pPrev = pTargetNode;

    pNewNode->pNext = pTemp;
    pTemp->pPrev = pNewNode;

    list->totalCount++;
}

// 8. 노드 가져오기
NODE* DLL_getNodeAt(LIST* list,  int position) {
    if (DLL_isEmpty(list)) {
        printf("빈 List입니다");
        return;
    }
    if (position > list->totalCount) {
        printf("[ Error ] TotalNode : %d, position : %d\n",
            list->totalCount, position
        );
        return;
    }
    NODE* pTemp = list->pHead;
    int max = list->totalCount;
    
    while (pTemp->pNext != NULL && --position >= 0) {
        pTemp = pTemp->pNext;
    }
    return pTemp;
}

// 9. 총 노드 개수 세기
int DLL_getNodeTotalCount(LIST* list) {
    return list->totalCount;
}

// 10. List 순회하며 각 노드들의 Key 출력
void DLL_print(LIST* list) {
    if (DLL_isEmpty(list)) {
        printf("빈 List입니다");
        return;
    }
    int count = list->totalCount;
    NODE* pTemp = list->pHead;

    for (size_t i = 0; i < count; i++) {
        pTemp = pTemp->pNext;
        char* key = list->getKey(pTemp);
        printf("NODE %zu %s\n",i+1, key);
    }
}