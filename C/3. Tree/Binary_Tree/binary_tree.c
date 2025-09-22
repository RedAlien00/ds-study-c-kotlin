#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"
#include "sll.h"

#define lenof(a) ( (sizeof(a)) / (sizeof(a[0])) )

// 트리 생성 : 인자로 루트로 쓸 int 받음
TREE* Tree(int rootInt) {
	TREE* pNewTree = (TREE*)calloc(1, sizeof(TREE));
	BT_NODE* pRoot = Node(rootInt);

	pNewTree->pRoot = pRoot;
	return pNewTree;
}

// 노드 생성
BT_NODE* Node(int pData) {
	BT_NODE* pNewNode = (BT_NODE*)calloc(1, sizeof(BT_NODE));
	pNewNode->pData = pData;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	return pNewNode;
}

// 노드 소멸
void destroyNode(BT_NODE* pNode) {
	free(pNode);
}

// 트리 소멸 
// 1. 후위 순회 결과를 sll 자료구조로 리턴
// 2. 반복하여 free
void destroyTree(TREE* tree) {
	SLL* pSll = sll();
	postorderTraversal(tree->pRoot, pSll);
	
	SLL_NODE* pNode = sll_getFirstOrNull(pSll);

	while (pNode != NULL) {
		free(pNode);
		pNode = sll_getFirstOrNull(pSll);
	}
}

// 트리에 노드 삽입
void insert(TREE* pTree, int pData) {
	BT_NODE* pNewNode = Node(pData);
	BT_NODE* pRoot = pTree->pRoot;

	while (1) {
		// 작으면 왼쪽
		if (pRoot->pData > pData) {
			if (pRoot->pLeft != NULL) {
				pRoot = pRoot->pLeft;
				continue;
			}
			else {
				pRoot->pLeft = pNewNode;
				break;
			}  
		}
		// 크면 오른쪽
		else {
			if (pRoot->pRight != NULL) {
				pRoot = pRoot->pRight;
				continue;
			}
			else {
				pRoot->pRight = pNewNode;
				break;
			}
		}
		break;
	}
}

// 원하는 순회 방식으로 트리 출력
void printTree(TREE* tree, ORDER order) {
	SLL* pSll = sll();
		
	switch (order) {
		case PREORDER: 
			preorderTraversal(tree->pRoot, pSll);		
			sll_print(pSll);
			break;
		case INORDER: 
			inorderTraversal(tree->pRoot, pSll);
			sll_print(pSll);
			break;
		case POSTORDER: 
			postorderTraversal(tree->pRoot, pSll);	
			sll_print(pSll);
			break;
	}
	sll_destroy(pSll);
}

// 전위 순회하며 sll에 추가
// 인자로 트리 루트와 저장할 sll 주소를 넘겨주면
// 트리 순회 결과를 sll 자료 구조에 저장하여 리턴
void preorderTraversal(BT_NODE* pRoot, SLL* pSll) {
	sll_add(pSll, pRoot->pData);

	if (pRoot->pLeft != NULL) {
		preorderTraversal(pRoot->pLeft, pSll);
	}
	if (pRoot->pRight != NULL) {
		preorderTraversal(pRoot->pRight, pSll);
	}
}

// 중위 순회하며 sll에 추가
void inorderTraversal(BT_NODE* pRoot, SLL* pSll) {
	if (pRoot->pLeft != NULL) {
		inorderTraversal(pRoot->pLeft, pSll);
	}
	sll_add(pSll, pRoot->pData);


	if (pRoot->pRight != NULL) {
		inorderTraversal(pRoot->pRight, pSll);
	}
	return;
}

// 후위 순회하며 sll에 추가
void postorderTraversal(BT_NODE* pRoot, SLL* pSll) {
	if (pRoot->pLeft != NULL) {
		postorderTraversal(pRoot->pLeft, pSll);
	}
	if (pRoot->pRight != NULL) {
		postorderTraversal(pRoot->pRight, pSll);
	}
	sll_add(pSll, pRoot->pData);
}