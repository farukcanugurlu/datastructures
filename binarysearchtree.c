#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;
typedef struct node node;

struct node *newNode(int key){
	node* temp = (node*)malloc(sizeof(node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;

	if(root==NULL){
		root=temp;
	}
	return temp;
};

void inorder(struct node *root){
	
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

node* search(int aranan){
    struct node* index;
    index=root;

    while(index->data!=aranan){
        if(index!=NULL){
            printf("%d ",index->data);
            if(aranan<index->data){
               index=index->left;
            }
            else{
               index=index->right;
            }
        }   
         if(index==NULL){
            printf("\n aradiginiz sayi bulunmuyor...");
            return NULL;
         }  
    }
    printf(" %d",index->data);
    return index;
}

node* addNode(node* node,int key){
   if(node == NULL){
	return newNode(key);
   }
   if(key<node->data){
	node->left = addNode(node->left,key);
   }
   else if(key>node->data){
     node->right=addNode(node->right,key);
   }
   return node;
};

int height(node *root) {
    if(root == NULL)
       return -1;
    else{
       int left_height, right_height;
       left_height = height(root -> left);
       right_height = height(root -> right);
    if(right_height > left_height)
       return right_height + 1;
    else
       return left_height + 1;
}
}

int size(node *root) {
if(root == NULL)
return 0;
else
return size(root -> left) + 1 + size(root -> right);
}

int minValue(BTREE* root) {
if(root == NULL)
return 0;
while(root -> left != NULL)
root = root -> left;
return(root -> data);
}

int minValue(BTREE* root) {
if(root == NULL)
return 0;
while(root -> left != NULL)
root = root -> left;
return(root -> data);
}

int main()
{
	int secim;
	int yukseklik;

	while(1){
		printf("\n 1-Sayi Ekle...");
		printf("\n 2-Inorder traversal...");
        printf("\n 3-Arama fonksiyonu...");
		printf("\n Seciminizi yapiniz...");
		scanf("%d",&secim);
        	switch(secim)
	{
		case 1:
		   printf("\n Girmek istediginiz sayi?..");
		   scanf("%d",&secim);
		   addNode(root,secim);
		   break;
		case 2:
		   inorder(root);
           break;
        case 3:
           printf("Hangi sayiyi aramak istiyorsunuz?..");
           scanf("%d",&secim);
           search(secim);
           break;
		case 4:
		   yukseklik= height(root);
		   printf("%d",yukseklik);
		   break;
		case 5:
		   printf("%d",size(root));
		   break;
	}
	}

}