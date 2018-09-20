#include "sys.h"
#include <stdio.h>
#include <stdlib.h>


int main () {

	char buff[255];

	FILE *fp = NULL;
	fp = stdin;

	while (fscanf(fp, "%s", buff) != EOF) {
		printf("[%s]\n", buff);
	}

	return 0;
}
