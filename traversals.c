#include "sys.h"
#include "node.h"

static int level = -1;

void preorder(node_t* node) {
	int i;
	level++;

	//Root
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->key);

	//Left
	if (node->left != NULL)
		preorder(node->left);

	//Right
	if (node->right != NULL)
		preorder(node->right);

	level--;
	return;
}

void inorder(node_t* node) {
	int i;
	level++;

	//Left
	if (node->left != NULL)
		inorder(node->left);

	//Root
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->key);

	//Right
	if (node->right != NULL)
		inorder(node->right);

	level--;
	return;
}

void postorder(node_t* node) {
	int i;
	level++;

	//Left
	if (node->left != NULL)
		postorder(node->left);

	//Right
	if (node->right != NULL)
		postorder(node->right);

	//Root
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->key);

	level--;
	return;
}
