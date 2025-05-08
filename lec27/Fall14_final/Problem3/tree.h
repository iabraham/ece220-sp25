#ifndef TREE
#define TREE

/* A node in a tree
*  value - the node's value
*  left - a pointer to the left node
*  right - a pointer to the right node
*/
typedef struct node {
    int value;
    struct node * left;
    struct node * right;
}node;

// Given the root of a tree deletes it, freeing memory
void delete_tree(node * root);

// Given a file creates a tree from the file contents
node * create_tree(char * fileName);

#endif /*!TREE*/
