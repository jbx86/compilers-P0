#include<iostream>
#include<fstream>
#include<set>
#include<string>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "node.h"

#define BUFFSZ 128
#define STRSZ 1024

using namespace std;

void addToTree(char*);

int main(int argc, char* argv[])
{
	FILE *fp;
	char *tok;
	char str[STRSZ];
	char buff[BUFFSZ];


	// Determine what to read from arguments
	// could be own function returning file pointer
	if (argc > 2) {
		cout << "Error: Too many arguments" << endl;
	}

	if (argc == 2) {
		char inname[20];
		strcpy(inname, argv[1]);
		strcat(inname, ".fs18");
		if ((fp = fopen(inname, "r")) != NULL) {
			printf("Read successful\n");
		}
		else {
			printf("Could not open %s.fs18 for reading\n", inname);
		}
		
	}
	else {
		fp = stdin;
	}
	// End function


	// Read from file input
	str[0] = '\0';
	while (fgets(buff, BUFFSZ, fp) != NULL) {
		strcat(str, buff);
	}

	// Parse words from string
	tok = strtok(str, " \t\n");
	while (tok != NULL) {
		addToTree(tok);	
		//printf("%d: \'%s\'\n", strlen(tok), tok);
		tok = strtok(NULL, " \t\n"); //scan same string until end is reached
	}


	return 0;
}

void addToTree(char *word) {
	printf("%d: \'%s\'\n", strlen(word), word);
	return;
}

/*
	set<string> setOfNumbers;

	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("first");
	setOfNumbers.insert("forth");

	cout << "Set Size = " << setOfNumbers.size() << endl;

	// Iterate through all the elements in the set
	for (set<string>::iterator it = setOfNumbers.begin(); it != setOfNumbers.end(); ++it)
		cout << ' ' << *it;
	cout << endl;

	return 0;
*/
