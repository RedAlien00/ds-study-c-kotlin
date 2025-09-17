#include <stdio.h>
#include <stdlib.h>
#include "test.h"

// 노드 생성
NODE* Node(void* pData) {
	NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
	newNode->data = pData;
	newNode->pLeftChild = NULL;
	newNode->pRightSibiling = NULL;
	return newNode;
}
// 노드 소멸
void destroyNode(NODE* pNode) {
	free(pNode);
}
// 트리 소멸
void destroyTree(NODE* root) {
	if (root->pLeftChild != NULL) {
		destroyTree(root->pLeftChild);
	}
	NODE* temp1 = root;
	NODE* temp2 = NULL;
	while (temp1->pRightSibiling != NULL) {
		temp2 = temp1->pRightSibiling;
		if (temp2->pLeftChild != NULL) {
			destroyTree(temp2->pLeftChild);
		}
		free(temp1);
		temp1 = temp2;
	}
	free(temp1);
}
// 자식 노드 추가( 부모, 자식 )
void addChildNode(NODE* pParent, NODE* pNewNode) {
	if (pParent->pLeftChild == NULL) {
		pParent->pLeftChild = pNewNode;
		return;
	} else {
		NODE* pTemp = pParent->pLeftChild;
		while (pTemp->pRightSibiling != NULL) {
			pTemp = pTemp->pRightSibiling;
		}
		pTemp->pRightSibiling = pNewNode;
	}
}
// 트리 출력
void printTree(NODE* root, int depth) {
	for (size_t i = 0; i < depth; i++) {
		if (i == depth - 1) {
			printf("└-");
		}
		else {
			printf("  ");
		}
	}
	printf("%s\n", root->data);

	if (root->pLeftChild != NULL) printTree(root->pLeftChild, depth + 1);
	if (root->pRightSibiling != NULL) printTree(root->pRightSibiling, depth);
	return;
}

int main() {
	NODE* root = Node("A");
	NODE* node2 = Node("B");
	NODE* node3 = Node("C");
	NODE* node4 = Node("D");
	NODE* node5 = Node("E");
	NODE* node6 = Node("F");
	NODE* node7 = Node("G");
	NODE* node8 = Node("H");
	NODE* node9 = Node("I");
	NODE* node10 = Node("J");
	NODE* node11 = Node("K");

	addChildNode(root, node2);
	addChildNode(root, node7);
	addChildNode(root, node9);

	addChildNode(node2, node3);
	addChildNode(node2, node4);
	addChildNode(node3, node5);
	addChildNode(node4, node6);

	addChildNode(node7, node8);

	addChildNode(node9, node10);
	addChildNode(node10, node11);

	printTree(root, 0);
	destroyTree(root);
}