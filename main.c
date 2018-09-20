#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <string>
#include "node.h"
#include "tree.h"

int main(int argc, char *argv[])
{
	FILE *fpInput = NULL;
	FILE *fpPreorder = NULL;
	FILE *fpInorder = NULL;
	FILE *fpPostorder = NULL;
	node_t *root = NULL;

	// Determine what to do depending on arguments
	if (argc == 1)
	{
		//Point to standard input and use default output file names
		fpInput = stdin;
		fpPreorder = fopen("out.preorder", "w");
		fpInorder = fopen("out.inorder", "w");
		fpPostorder = fopen("out.postorder", "w");
	}
	else if (argc == 2)
	{
		// Use argument for i/o file names
		char inputName[strlen(argv[1]) + sizeof(".fs18")];
		char preorderName[strlen(argv[1]) + sizeof(".preorder")];
		char inorderName[strlen(argv[1]) + sizeof(".inorder")];
		char postorderName[strlen(argv[1]) + sizeof(".postorder")];

		//char* inputName = (char*)malloc(sizeof(char)*(strlen(argv[1]) + sizeof(".fs18");



		// Generate output file names
		sprintf(inputName, "%s.fs18", argv[1]);
		sprintf(preorderName, "%s.preorder", argv[1]);
		sprintf(inorderName, "%s.inorder", argv[1]);
		sprintf(postorderName, "%s.postorder", argv[1]);

		printf("Input: \'%s\'\nFile: \'%s\'\nPre: \'%s\'\nInO: \'%s\'\nPost: \'%s\'\n", argv[1], inputName, preorderName, inorderName, postorderName);
	
		if ((fpInput = fopen(inputName, "r")) == NULL)
		{
			//Error and exit if file cannot be opened
			printf("Could not open \"%s\"\n", inputName);
			exit(0);
		}

		// Open output files for writing
		fpPreorder = fopen(preorderName, "w");
		fpInorder = fopen(inorderName, "w");
		fpPostorder = fopen(postorderName, "w");

	}
	else
	{
		// Error and exit if more than one argument is used
		printf("Error: Too many argumnets\n");
		exit(0);
	}

	root = buildTree(fpInput);
	preorder(root, fpPreorder);
	inorder(root, fpInorder);
	postorder(root, fpPostorder);

	// Close all files used
	fclose(fpInput);
	fclose(fpPreorder);
	fclose(fpInorder);
	fclose(fpPostorder);

	return 0;
}
