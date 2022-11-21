// Construction of BST from preorder

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
    newNode->right = NULL;
	return newNode;
}

// preIndex is used to keep track of index in pre[].
struct node* constructTreeUtil(int pre[], int * preIndex, int low, int high, int size){
	
	if (*preIndex >= size || low > high)
		return NULL;

	// The first node in preorder traversal is root. So take
	// the node at preIndex from pre[] and make it root, and
	// increment preIndex
	struct node* root = newNode(pre[*preIndex]);
	*preIndex = *preIndex + 1;

	// If the current subarray has only one element, no need
	// to recur
	if (low == high)
		return root;

	// Search for the first element greater than root
	int i;
	for (i = low; i <= high; ++i)
		if (pre[i] > root->data)
			break;

	// Use the index of element found in preorder to divide
	// preorder array in two parts. Left subtree and right
	// subtree
	root->left = constructTreeUtil(pre, preIndex, *preIndex,
								i - 1, size);
	root->right = constructTreeUtil(pre, preIndex, i, high, size);

	return root;
}

// The main function to construct BST from given preorder traversal. This function mainly uses constructTreeUtil()
struct node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, 0, size - 1, size);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	struct node* root = constructTree(pre, size);

	printf("Inorder traversal of the constructed tree: \n");
	printInorder(root);

	return 0;
}
