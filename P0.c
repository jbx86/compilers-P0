#include "sys.h"
#include "node.h"
#include "tree.h"
#include "traversals.h"

int main(int argc, char *argv[]) {
	char fout[] = "out"; // output file name defaults to out.extension
	FILE *fp = NULL;
	node_t *root = NULL;

	// Determine what to do depending on arguments
	if (argc == 1) {
		fp = stdin; //stdin if no arguments are given
	}
	else if (argc == 2) {
		// If an argument is given, open argv[1].fs18
		strcpy(fout, argv[1]); // change output file name to reflect argument
		char temp[strlen(argv[1])];
		strcpy(temp, argv[1]);
		strcat(temp, ".fs18");
		if ((fp = fopen(temp, "r")) == NULL) {
			//Error and exit if file cannot be opened
			printf("Could not open %s\n", temp);
			exit(0);
		}
	}
	else {
		// Error and exit if more than one argument is used
		printf("Error: Too many argumnets\n");
		exit(0);
	}

	root = buildTree(fp); //Build tree from selected input
	printf("root: %p\n", (void*)root);
	//printf("Preorder:\n");
	preorder(root, fout);
	//printf("Inorder:\n");
	inorder(root, fout);
	//printf("Postorder:\n");
	postorder(root, fout);

	return 0;
}
