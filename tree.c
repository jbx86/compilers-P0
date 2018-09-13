#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// Create a new node with this key value
node_t* newNode(int key) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	printf("New node %d\n", key);
	return node;
}

// Insert data into the tree
void insertNode(node_t* node, int key) {
	if (key == node->key) {
		// If the right node has been found, insert the data
		printf("%d is alread in the tree\n", key);
	}
	else if (key <= node->key) {
		// If the key value is smaller, continue to the left child
		printf("%d < %d, left\n", key, node->key);
		if (node->left == NULL)
			node->left = newNode(key);
		else
			insertNode(node->left, key);
	}
	else {
		// If the key value is larger, continue to the right child
		printf("%d > %d, right\n", key, node->key);
		if (node->right == NULL)
			node->right = newNode(key);
		else
			insertNode(node->right, key);
	}
}

void preorder(node_t* node, int lvl) {
	int i;
	for (i = 0; i < lvl; i++)
		printf("  ");
	printf("%d\n", node->key);
	if (node->left != NULL)
		preorder(node->left, lvl + 1);
	if (node->right != NULL)
		preorder(node->right, lvl + 1);
}

void inorder(node_t* node, int lvl) {
	if (node->left != NULL)
		inorder(node->left, lvl + 1);
	int i;
	for (i = 0; i < lvl; i++)
		printf("  ");
	printf("%d\n", node->key);
	if (node->right != NULL)
		inorder(node->right, lvl + 1);
}

void postorder(node_t* node, int lvl) {
	if (node->left != NULL)
		postorder(node->left, lvl + 1);
	if (node->right != NULL)
		postorder(node->right, lvl + 1);

	int i;
	for (i = 0; i < lvl; i++)
		printf("  ");
	printf("%d\n", node->key);
}
