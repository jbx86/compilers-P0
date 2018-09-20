#include "sys.h"
#include <vector>
#include <iostream>
#include <set>
#include <string>

//using namespace std;

typedef struct node {
	std::set<std::string> nodeSet;
} node_t;

int main() {

//	std::cout << sizeof(std::set<std::string>) << std::endl;

	// Normal allocation and use
	
/*
	node_t sNode;
	sNode.nodeSet.insert("One");
	sNode.nodeSet.insert("Two");
	sNode.nodeSet.insert("Three");
	std::cout << "Static set:";
	for (std::set<std::string>::iterator it = sNode.nodeSet.begin(); it != sNode.nodeSet.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
*/
	// Dynamic allocation and use
	
	node_t* dNode = new node_t;

/*
//	dNode->nodeSet.insert("Four");
//	dNode->nodeSet.insert("Five");
//	dNode->nodeSet.insert("Six");
//	std::cout << "Dynamic set:";
//	for (std::set<std::string>::iterator sIt = dNode->nodeSet.begin(); sIt != dNode->nodeSet.end(); sIt++)
//		std::cout << ' ' << *sIt;
//	std::cout << std::endl;
*/
	FILE *fp = stdin;
	char buff[1024];
	while (fgets(buff, 1024, fp) != NULL) {
		char *tok = strtok(buff, " \t\n");
		while (tok != NULL) {
			//printf("[%s]", tok);
			dNode->nodeSet.insert(tok);
			tok = strtok(NULL, " \t\n");
		}
		//printf("\n");
	}

	for (std::set<std::string>::iterator sIt = dNode->nodeSet.begin(); sIt != dNode->nodeSet.end(); sIt++)
		std::cout << ' ' << *sIt;
	std::cout << std::endl;
 

	return 0;
}
