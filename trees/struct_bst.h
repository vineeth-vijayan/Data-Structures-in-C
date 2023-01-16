
struct BST{
	int data;
	struct BST *lchild, *rchild;
};

struct BST *root = NULL;

struct BST* add_node(struct BST *bt, int d){
	if(bt == NULL){
		struct BST *b = (struct BST*) malloc(sizeof(struct BST));
		b->data = d;
		b->lchild = b->rchild = NULL;
		bt = b;
		printf("\tNode added!!\n");
		return bt;
	}
	else{
		if(bt->data > d)
			bt->lchild = add_node(bt->lchild, d);
		else
			bt->rchild = add_node(bt->rchild, d);
	}
	return bt;
}

int isTreeEmpty(){
	return root == NULL;
}

void Preorder(struct BST *bt){
	if(bt!=NULL){
		printf("%d ", bt->data);
		Preorder(bt->lchild);
		Preorder(bt->rchild);
	}
}

void Postorder(struct BST *bt){
	if(bt!=NULL){
		Postorder(bt->lchild);
		Postorder(bt->rchild);
		printf("%d ", bt->data);
	}
}


void Inorder(struct BST *bt){
	if(bt!=NULL){
		Inorder(bt->lchild);
		printf("%d ", bt->data);
		Inorder(bt->rchild);
	}
}

struct BST *maxValue(struct BST *bt){
	while(bt->rchild!=NULL)
		bt = bt->rchild;
	return bt;
}

struct BST *minValue(struct BST *bt){
	while(bt->lchild!=NULL)
		bt = bt->lchild;
	return bt;
}

struct BST *delete_node(struct BST *bt, int val){
	if(bt == NULL)
		return bt;
	else if(bt->data < val)
		bt->rchild = delete_node(bt->rchild, val);
	else if(bt->data > val)
		bt->lchild = delete_node(bt->lchild, val);
	else{
		if(bt->lchild==NULL && bt->rchild==NULL)
			return NULL;
		else if(bt->rchild==NULL){
			struct BST *temp = bt->lchild;
			free(bt);
			return temp;
		}
		else if(bt->lchild == NULL){
			struct BST *temp = bt->rchild;
			free(bt);
			return temp;
		}
		else{
			struct BST *minVal = maxValue(bt->lchild);
			bt->data = minVal->data;
			bt->lchild = delete_node(bt->lchild, minVal->data);
		}
	}
	return bt;
}

