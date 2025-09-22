#include <stdio.h>

#include "sll.h"
#include "binary_tree.h"

#define lenof(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main() {
	TREE* pTree1 = Tree(10);

	int numbers[] = { 5, 3, 7, 2, 6, 8, 15, 20, 18 };

	for (size_t i = 0; i < lenof(numbers); i++) {
		insert(pTree1, numbers[i]);
	}
	printTree(pTree1, PREORDER);
	destroyTree(pTree1);

}