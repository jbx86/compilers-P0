#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "tree.h"

#define BUFFSIZE 1024

//void insertNode();

int main(int argc, char *argv[]) {
	char buff[BUFFSIZE];
	char out[] = "out";
	FILE *fp = NULL;
	node_t *root = NULL;

	// Determine what to do depending on arguments
	if (argc == 1) {
		fp = stdin;
	}
	else if (argc == 2) {
		strcpy(out, argv[1]);
		char temp[strlen(argv[1])];
		strcpy(temp, argv[1]);
		strcat(temp, ".fs18");
		if ((fp = fopen(temp, "r")) == NULL) {
			printf("Could not open %s\n", temp);
			exit(0);
		}
		printf("Opened %s successfully\n", temp);
	}
	else {
		printf("Error: Too many argumnets\n");
		exit(0);
	}

	// Read from file pointer
	while (fgets(buff, BUFFSIZE, fp) != NULL) {
		char *tok = strtok(buff, " \t\n");
		while (tok != NULL) {
			printf("[%s]", tok);
			if (root == NULL)
				root = newNode(strlen(tok));
			else
				insertNode(root, strlen(tok));
			tok = strtok(NULL, " \t\n");
		}
		printf("\n");
	}

	preorder(root, 0);

	printf("\n%s.output\n", out);

	return 0;
}
