
#include <stdlib.h>
#include <stdio.h>

struct node {
	int val;
	struct node* left;
	struct node* right;
} ;

struct node* createNode(int val)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void inorder(struct node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void mirrorify(struct node* root, struct node** mirror)
{
	if (root == NULL) {
		mirror = NULL;
		return;
	}

	*mirror = createNode(root->val);
	mirrorify(root->left, &((*mirror)->right));
	mirrorify(root->right, &((*mirror)->left));
}

// Driver code
int main()
{

	struct node* tree = createNode(5);
	tree->left = createNode(3);
	tree->right = createNode(6);
	tree->left->left = createNode(2);
	tree->left->right = createNode(4);

	printf("Inorder of original tree: ");
	inorder(tree);
	struct node* mirror = NULL;
	mirrorify(tree, &mirror);

	printf("\nInorder of mirror tree: ");
	inorder(mirror);

	return 0;
}
