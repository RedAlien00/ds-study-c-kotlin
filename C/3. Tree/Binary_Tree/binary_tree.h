#pragma once

#include "sll.h"

typedef enum ORDER {
	PREORDER,
	INORDER,
	POSTORDER
} ORDER;

// 이진 트리 노드
typedef struct BT_NODE {
	int pData;

	struct BT_NODE* pLeft;
	struct BT_NODE* pRight;
} BT_NODE;

// 이진 트리
typedef struct TREE {
	BT_NODE* pRoot;
} TREE;


// 트리 생성 : 인자로 루트로 쓸 int 받음
TREE* Tree(int);

// 노드 생성
BT_NODE* Node(int);

// 노드 소멸
void destroyNode(BT_NODE*);

// 트리 소멸
void destroyTree(TREE*);

// 트리에 노드 삽입
void insert(TREE*, int);


// 트리 출력
void printTree(TREE*, ORDER);

// 전위 순회하며 sll에 추가
void preorderTraversal(BT_NODE*, SLL*);

// 중위 순회하며 sll에 추가
void inorderTraversal(BT_NODE*, SLL*);

// 후위 순회하며 sll에 추가
void postorderTraversal(BT_NODE*, SLL*);