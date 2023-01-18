#include<stdio.h>
#include<stdlib.h>

struct AVL
{
	int data;
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

struct AVL* newNode(int data)
{
	struct AVL* node = (struct AVL*)malloc(sizeof(struct AVL));
	node->data = data;
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

struct AVL* insert(struct AVL* node, int data)
{
	if (node == NULL)
		return(newNode(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else 
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct AVL *maxValue(struct AVL *node){
	while(node && node->right!=NULL)
		node = node->right;
	return node;
}

struct AVL *delete(struct AVL *node, int data){
	if(node == NULL)
		return node;
	
	if(node->data > data)
		node->left = delete(node->left, data);
	else if(node->data < data)
		node->right = delete(node->right, data);
	else{
		if((node->left==NULL) || (node->right==NULL)){
			struct AVL *temp = node->left ? node->left:node->right;
			if(temp == NULL)
				node = NULL;
			else
				*node = *temp;
		}
		else{
			struct AVL *temp = maxValue(node->left);
			node->data = temp->data;
			node->left = delete(node->left, temp->data);
		}
	}

	if(node == NULL)
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if(balance>1 && getBalance(node->left)>=0)
		return leftRotate(node);
	if(balance>1 && getBalance(node->left)<0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && getBalance(node->right)<=0)
		return rightRotate(node);
	if(balance<-1 && getBalance(node->right)>0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

void preOrder(struct AVL *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	struct AVL *root = NULL;
	
	//Insert
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 70);
	root = insert(root, 80);

	//Delete
	root = delete(root, 70);
	root = delete(root, 60);
	root = delete(root, 40);
	root = delete(root, 20);

	printf("\tPreorder traversal: ");
	preOrder(root);
	printf("\n");

	return 0;
}

