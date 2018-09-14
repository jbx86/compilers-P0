#include "sys.h"
#include "node.h"

static int level = -1;

void preorder(node_t* node, const char fout[]) {
	int i;
	level++;

	//Root
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->key);

	//Left
	if (node->left != NULL)
		preorder(node->left, fout);

	//Right
	if (node->right != NULL)
		preorder(node->right, fout);

	level--;
	return;
}

void inorder(node_t* node, const char fout[]) {
	int i;
	level++;

	//Left
	if (node->left != NULL)
		inorder(node->left, fout);

	//Root
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->key);

	//Right
	if (node->right != NULL)
		inorder(node->right, fout);

	level--;
	return;
}

void postorder(node_t* node, const char fout[]) {
	int i;
	level++;

	//Left
	if (node->left != NULL)
		postorder(node->left, fout);

	//Right
	if (node->right != NULL)
		postorder(node->right, fout);

	//Root
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->key);

	level--;
	return;
}
