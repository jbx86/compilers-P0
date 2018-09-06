#include <stdio.h>
#include <stdlib.h>

#include "node.h"

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
	FILE *fp;
	node_t *head = NULL;

	if (argc > 2) {
		fprintf(stderr, "Error: Too many arguments\n");
		//exit(1);
	}

	/*head = (node_t *)malloc(sizeof(node_t));

	printf("%s is running with %d arguments\n", argv[0], argc);
	printf("Head node is %p\n", head);*/


	return 0;
}
