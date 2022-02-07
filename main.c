#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	struct n * right;
	struct n * left;
}node;

node * ekle(node * tree,int value){
	if(tree==NULL){
		node * root=(node *)malloc(sizeof(node));
		root->data=value;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else{
		if(tree->data>value){
			tree->left=ekle(tree->left,value);
		}
		else if(tree->data<value){
			tree->right=ekle(tree->right,value);
		}		
	}
	return tree;
}

void dolas(node * tree){
	if(tree==NULL){
		return;
	}
	dolas(tree->left);
	printf("%d|",tree->data);
	dolas(tree->right);
}

int bul(node * tree,int value){
	if(tree==NULL){
		return -1;
	}
	if(value==tree->data){
		return 1;
	}
	if(bul(tree->left,value)==1){
		return 1;
	}
	if(bul(tree->right,value)==1){
		return 1;
	}
	return -1;
}

int getMin(node * tree){
	if(tree->left==NULL)
		return tree->data;
	getMin(tree->left);
}

int getMax(node * tree){
	if(tree->right==NULL)
		return tree->data;
	getMax(tree->right);
}

node * sil(node * tree,int value){
	if(tree==NULL)
	{
		return NULL;
	}
	if(tree->data==value){
		if(tree->left==NULL&&tree->right==NULL){
			return NULL;
		}
		if(tree->right!=NULL){
			tree->data=getMin(tree->right);
			tree->right=sil(tree->right,getMin(tree->right));
			return tree;
		}	
		tree->data=getMax(tree->left);
		tree->left=sil(tree->left,getMax(tree->left));
		return tree;
	}
		
	if(tree->data<value){
		tree->right=sil(tree->right,value);
		return tree;
	}
	tree->left=sil(tree->left,value);
		return tree;
	
}

int main(int argc, char *argv[]) {
	node *agac=NULL;
	agac=ekle(agac,10);
	agac=ekle(agac,18);
	agac=ekle(agac,21);
	agac=ekle(agac,9);
	agac=ekle(agac,40);
	agac=ekle(agac,54);
	agac=ekle(agac,32);
	agac=ekle(agac,25);
	agac=ekle(agac,19);
	dolas(agac);
	printf("\n%d",bul(agac,60));
	printf("\nmax=%d,min=%d",getMax(agac),getMin(agac));
	agac=sil(agac,25);
	agac=sil(agac,10);
	agac=sil(agac,9);
	agac=sil(agac,32);
	agac=sil(agac,54);
	printf("\n");
	dolas(agac);
	return 0;
}
