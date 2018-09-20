node_t* buildTree(FILE *);
node_t* newNode(const char*);
void insertNode(node_t*, char *tok);
void preorder(node_t*, const char []);
void inorder(node_t*, const char []);
void postorder(node_t*, const char []);
