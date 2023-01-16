#include <stdio.h>
#include <stdlib.h>
#include "struct_bst.h"


int main(){
	int ch,val;
	do{
		printf("\nEnter your choice: \n1.Add node\n2.Check if Tree empty\n3.Preorder Traverse\n4.Postorder Traverse\n5.Inorder Traverse\n6.Delete\n7.Exit\n:: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter the value to be inserted: ");
				scanf("%d", &val);
				root = add_node(root, val);
				break;
			case 2:
				if(!isTreeEmpty())
					printf("\tTree is not empty!!\n");
				else
					printf("\tTree is empty!!\n");
				break;
			case 3:
				if(!isTreeEmpty())
					Preorder(root);
				else
					printf("\tTree is empty!!\n");
				break;
			case 4:
				if(!isTreeEmpty())
					Postorder(root);
				else
					printf("\tTree is empty!!\n ");
				break;
			case 5:
				if(!isTreeEmpty())
					Inorder(root);
				else
					printf("\tTree is empty!!\n");
				break;
			case 6:
				printf("Enter value to be deleted: ");
				scanf("%d", &val);
				if(!isTreeEmpty())
					root = delete_node(root, val);
				else
					printf("\tTree is empty!!\n");
				break;
			case 7:
				printf("\tExit!!\n");
				break;
			default: 
				printf("\tTry Again!!\n");
		}
	}while(ch!=7);

	return 0;
}
