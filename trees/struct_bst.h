
int *ar;
int size = 0;
int ind;

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
		ar = (int*) calloc(size++,sizeof(int));
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

int isTreeEmpty(/*struct BST *t*/){
	//return t==NULL;
	return root == NULL;
}

void Preorder(struct BST *bt){
	if(bt!=NULL){
		ar[ind++] = bt->data;
		//printf("%d ", bt->data);
		Preorder(bt->lchild);
		Preorder(bt->rchild);
	}
}

void Postorder(struct BST *bt){
	if(bt!=NULL){
		Postorder(bt->lchild);
		Postorder(bt->rchild);
		ar[ind++] = bt->data;
		//printf("%d ", bt->data);
	}
}


void Inorder(struct BST *bt){
	if(bt!=NULL){
		Inorder(bt->lchild);
		ar[ind++] = bt->data;
		//printf("%d ", bt->data);
		Inorder(bt->rchild);
	}
}


struct BST *delete_node(struct BST *bt, int val){
	if(bt->data==val){
		if(bt->lchild==NULL && bt->rchild==NULL)
			return NULL;
		else if(bt->lchild == NULL){
			bt->data = bt->rchild->data;
			bt->rchild = delete_node(bt->rchild, bt->data);
		}
		else if(bt->rchild==NULL){
			bt->data = bt->lchild->data;
			bt->lchild = delete_node(bt->rchild, bt->data);
		}
		else{
			ind = 0;
			Inorder(root);
			// taking predecessor 
			for(int i=0; i<size-1; i++)
			{
				if(ar[i+1]==val){
					printf("%d", ar[i]);
					bt->data = ar[i];
					bt->lchild = delete_node(bt->lchild, ar[i]);
				}
			}
		}
	}
	else if(bt->data < val){
		printf("%d\n", bt->data);
		//prev = bt;
		bt->rchild = delete_node(bt->rchild, val);
	}
	else{
		printf("%d\n", bt->data);
		bt->lchild = delete_node(bt->lchild, val);
	}
	return bt;

}

