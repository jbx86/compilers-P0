

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

#include "node.h"
#include "tree.h"

#define BUFFSIZE 1024

//void insertNode();

int main(int argc, char *argv[]) {
	node_t *node = newNode(10);
	printf("%d\n", node->key);
	node->key = 5;
	node::tokens.insert("Hello");

	set<string> tok;
	tok.insert("Hello");
	tok.insert("It's");
	tok.insert("Me");

	return 0;
}
