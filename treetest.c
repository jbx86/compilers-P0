#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "tree.h"


int main () {
	node_t *root = newNode(8);
	//insertNode(root, 8);
	insertNode(root, 4);
	insertNode(root, 12);
	insertNode(root, 2);
	insertNode(root, 6);
	insertNode(root, 10);
	insertNode(root, 14);
	preorder(root, 0);
	printf("---\n");
	inorder(root, 0);
	printf("---\n");
	postorder(root, 0);
	return 0;
}
