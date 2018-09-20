#ifndef TREE_H
#define TREE_H

node_t* buildTree(FILE *);
node_t* newNode(const char*);
void insertNode(node_t*, char *tok);
void preorder(node_t*, FILE*);
void inorder(node_t*, FILE*);
void postorder(node_t*, FILE*);

#endif
