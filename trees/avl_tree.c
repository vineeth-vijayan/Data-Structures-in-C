#include<stdio.h>
#include<stdlib.h>

struct AVL
{
	int key;
	struct AVL *left;
	struct AVL *right;
	int height;
};

int height(struct AVL *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct AVL* newAVL(int key)
{
	struct AVL* node = (struct AVL*)malloc(sizeof(struct AVL));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

struct AVL *rightRotate(struct AVL *y)
{
	struct AVL *x = y->left;
	struct AVL *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

struct AVL *leftRotate(struct AVL *x)
{
	struct AVL *y = x->right;
	struct AVL *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(struct AVL *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct AVL* insert(struct AVL* node, int key)
{
	if (node == NULL)
		return(newAVL(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void preOrder(struct AVL *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	struct AVL *root = NULL;
	root = insert(root, 100);
	root = insert(root, 150);
	root = insert(root, 80);
	root = insert(root, 60);
	root = insert(root, 25);
	root = insert(root, 200);
	root = insert(root, 120);
	root = insert(root, 130);
	root = insert(root, 170);
	root = insert(root, 90);
	root = insert(root, 75);


	printf("\tPreorder traversal: ");
	preOrder(root);

	return 0;
}

