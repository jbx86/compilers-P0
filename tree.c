#include "sys.h"
#include "node.h"
#define BUFFSIZE 1024

node_t* newNode(char*);
void insertNode(node_t*, char*);

node_t *buildTree(FILE *fp) {
	node_t *root = NULL;
	char buff[BUFFSIZE];

	// Copy from input source to buffer until EOF
	while (fgets(buff, BUFFSIZE, fp) != NULL) {
		// Parse tokens from buffer until end of buffer/line
		char *tok = strtok(buff, " \t\n");
		while (tok != NULL) {
			if (root == NULL)
				root = newNode(tok);
			else
				insertNode(root, tok);
			tok = strtok(NULL, " \t\n");
		}
	}
	return root;
}

node_t* newNode(char* tok) {
	node *node = (node_t*)malloc(sizeof(node_t));
	node->key = strlen(tok);
	node->left = NULL;
	node->right = NULL;
	//printf("Node created from \"%s\"\n%p:\t%d\t%p\t%p\n", tok, (void*)node, node->key, (void*)node->left, (void*)node->right); 
	return node;
}

void insertNode(node_t *node, char *tok) {
	if (strlen(tok) == node->key) {
		//printf("Node already exists\n");
	}
	else if (strlen(tok) < node->key) {
		if (node->left == NULL)
			node->left = newNode(tok);
		else
			insertNode(node->left, tok);
	}
	else {
		if (node->right == NULL)
			node->right = newNode(tok);
		else
			insertNode(node->right, tok);
	}
	return;
}
