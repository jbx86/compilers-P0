#include "sys.h"
#include "node.h"
#include "tree.h"
#define BUFFSIZE 10

static int level = 0;

// Given a file pointer, will create a tree and return pointer to the root node
node_t* buildTree(FILE *fp) {
	node_t *root = NULL;
	char buff[BUFFSIZE];

	// Copy from input source to buffer until EOF
	while (fgets(buff, BUFFSIZE, fp) != NULL) {

		// Parse tokens from buffer until end of buffer/line
		char *tok = strtok(buff, " \t\n");
		while (tok != NULL) {
			if (root == NULL)
				root = newNode(tok);	//If no root exists, create root from token
			else
				insertNode(root, tok);	//Else, find token's place in the tree
			tok = strtok(NULL, " \t\n");
		}

	}
	return root;
}

// Create a new node in tree and start a set with the token
node_t* newNode(const char* tok) {
	node *node = (node_t*)malloc(sizeof(node_t));
	node->tokSet = new set<string>;
	node->tokSet->insert(tok);
	node->key = strlen(tok);
	node->left = NULL;
	node->right = NULL; 
	return node;
}

// Traverse tree until proper node is found/created
void insertNode(node_t *node, char *tok) {

	if (strlen(tok) == node->key) {
		node->tokSet->insert(tok);
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

void preorder(node_t* node, const char fout[]) {

	//Root
	FILE *fp = fopen(fout, "a");
	for (int i = 0; i < level; i++)
		fprintf(fp, "  ");
	fprintf(fp, "%d", node->key);
	for (set<string>::iterator it = node->tokSet->begin(); it != node->tokSet->end(); it++)
		fprintf(fp, " %s", it->c_str());
	fprintf(fp, "\n");


	//Left
	if (node->left != NULL){
		level++;
		preorder(node->left, fout);
		level--;
	}

	//Right
	if (node->right != NULL) {
		level++;
		preorder(node->right, fout);
		level--;
	}

	return;
}

void inorder(node_t* node, const char fout[]) {

	//Left
	if (node->left != NULL) {
		level++;
		inorder(node->left, fout);
		level--;
	}

	//Root
	for (int i = 0; i < level; i++)
		printf("  ");
	printf("%d", node->key);
	for (set<string>::iterator it = node->tokSet->begin(); it != node->tokSet->end(); it++)
		printf(" %s", it->c_str());
	printf("\n");

	//Right
	if (node->right != NULL) {
		level++;
		inorder(node->right, fout);
		level--;
	}

	return;
}

void postorder(node_t* node, const char fout[]) {

	//Left
	if (node->left != NULL) {
		level++;
		postorder(node->left, fout);
		level--;
	}

	//Right
	if (node->right != NULL) {
		level++;
		postorder(node->right, fout);
		level--;
	}

	//Root
	for (int i = 0; i < level; i++)
		printf("  ");
	printf("%d", node->key);
	for (set<string>::iterator it = node->tokSet->begin(); it != node->tokSet->end(); it++)
		printf(" %s", it->c_str());
	printf("\n");

	return;
}
