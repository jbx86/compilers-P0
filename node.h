#ifndef NODE_H
#define NODE_H

// Binary tree node
typedef struct node {
	unsigned int key;
	std::set<std::string> *tokSet;
	struct node *left;
	struct node *right;
} node_t;

#endif
