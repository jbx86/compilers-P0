#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node_t* newNode(int key) {
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	printf("New node %d\n", key);
	return node;
}

void insertNode(node_t* node, int key) {
	if (key == node->key) {
		printf("%d is alread in the tree\n", key);
	}
	else if (key <= node->key) {
		printf("%d < %d, left\n", key, node->key);
		if (node->left == NULL)
			node->left = newNode(key);
		else
			insertNode(node->left, key);
	}
	else {
		printf("%d > %d\n, right\n", key, node->key);
		if (node->right == NULL)
			node->right = newNode(key);
		else
			insertNode(node->right, key);
	}
}
