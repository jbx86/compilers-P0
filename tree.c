#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <string>

#include "node.h"

//Helper function prototypes
node_t* newNode(const char*);
void insertNode(node_t*, char*);

//Helper variable
static int level = 0;

/* Given a file pointer, will create a tree and return pointer to the root node */
node_t* buildTree(FILE *fp)
{
	node_t *root = NULL;
	const int SIZE = 256;
	char buff[SIZE];

	// Copy from input source to buffer until EOF
	while (fscanf(fp, "%s", buff) != EOF)
	{
		if (root == NULL)
			root = newNode(buff);
		else
			insertNode(root, buff);

	}

	return root;
}

/* Allocate and initialize a node and return a pointer to it */
node_t* newNode(const char* tok)
{
	node *node = (node_t*)malloc(sizeof(node_t));
	node->tokSet = new std::set<std::string>;
	node->tokSet->insert(tok);
	node->key = strlen(tok);
	node->left = NULL;
	node->right = NULL; 
	return node;
}

// Traverse tree until proper node is found/created
void insertNode(node_t *node, char *tok)
{
	if (strlen(tok) == node->key)
	{
		node->tokSet->insert(tok);
	}
	else if (strlen(tok) < node->key)
	{
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

void preorder(node_t* node, FILE *fp)
{	
	//Print root
	for (int i = 0; i < level; i++)
		fprintf(fp, "  ");
	fprintf(fp, "%d", node->key);
	for (std::set<std::string>::iterator it = node->tokSet->begin(); it != node->tokSet->end(); it++)
		fprintf(fp, " %s", it->c_str());
	fprintf(fp, "\n");

	//Traverse left child
	if (node->left != NULL)
	{
		level++;
		preorder(node->left, fp);
		level--;
	}

	//Traverse right child
	if (node->right != NULL)
	{
		level++;
		preorder(node->right, fp);
		level--;
	}

	return;
}

void inorder(node_t* node, FILE *fp)
{
	//Traverse left child
	if (node->left != NULL)
	{
		level++;
		inorder(node->left, fp);
		level--;
	}

	//Print root
	for (int i = 0; i < level; i++)
		fprintf(fp, "  ");
	fprintf(fp, "%d", node->key);
	for (std::set<std::string>::iterator it = node->tokSet->begin(); it != node->tokSet->end(); it++)
		fprintf(fp, " %s", it->c_str());
	fprintf(fp, "\n");

	//Traverse right child
	if (node->right != NULL)
	{
		level++;
		inorder(node->right, fp);
		level--;
	}

	return;
}

void postorder(node_t* node, FILE *fp)
{
	//Traverse left child
	if (node->left != NULL)
	{
		level++;
		postorder(node->left, fp);
		level--;
	}

	//Traverse right child
	if (node->right != NULL)
	{
		level++;
		postorder(node->right, fp);
		level--;
	}

	//Print root
	for (int i = 0; i < level; i++)
		fprintf(fp, "  ");
	fprintf(fp, "%d", node->key);
	for (std::set<std::string>::iterator it = node->tokSet->begin(); it != node->tokSet->end(); it++)
		fprintf(fp, " %s", it->c_str());
	fprintf(fp, "\n");

	return;
}
