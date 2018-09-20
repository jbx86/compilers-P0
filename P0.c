#include "sys.h"
#include "node.h"
#include "tree.h"
#include "traversals.h"

int main(int argc, char *argv[]) {
	char fname[] = "out"; // output file name defaults to out.extension
	FILE *fp = NULL;
	node_t *root = NULL;
	long int flen;

	// Determine what to do depending on arguments
	if (argc == 1) {
		fp = stdin; //stdin if no arguments are given
	}
	else if (argc == 2) {
		// If an argument is given, open argv[1].fs18
		strcpy(fname, argv[1]);
		char fin[strlen(argv[1])];
		strcpy(fin, argv[1]);
		strcat(fin, ".fs18");
		if ((fp = fopen(fin, "r")) == NULL) {
			//Error and exit if file cannot be opened
			printf("Could not open %s\n", fin);
			exit(0);
		}
	}
	else {
		// Error and exit if more than one argument is used
		printf("Error: Too many argumnets\n");
		exit(0);
	}

	root = buildTree(fp);

	fseek(fp, 0L, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	printf("%ld\n", flen);

	//root = buildTree(fp); //Build tree from selected input
	
	printf("root: %p\n", (void*)root);
	printf("Preorder:\n");
	preorder(root, fname);
	printf("Inorder:\n");
	inorder(root, fname);
	printf("Postorder:\n");
	postorder(root, fname);

	return 0;
}
