#include "sys.h"
#include <vector>
#include <iostream>
#include <set>

//using namespace std;

typedef struct node {
	std::set<int> myset;
} node_t;

/*test mytest;

void foo() {
	mytest.myset.insert(3);
}
*/

int main() {
	node_t mytest;
	mytest.myset.insert(3);
	//foo();
	std::cout << "myset contains:";
	for (std::set<int>::iterator it = mytest.myset.begin(); it != mytest.myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	return 0;
}
