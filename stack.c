#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* top = NULL;

void push(int veri){
	if(top==NULL){
		struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
		eklenecek->data=veri;
	    eklenecek->next=NULL;
	    
	    top=eklenecek;
	}
	else{
		struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
		eklenecek->data=veri;
		eklenecek->next=top;
		top=eklenecek;  	
	}
}

void pop()
{
	if(top==NULL){
		printf("Stack zaten bos");
	}
	else
	{
		struct node* temp;
		temp=top;
		top=top->next;
		free(temp);
	}
}

int peek()
{
	return top->data;
}

void yazdir()
{
	struct node* q;
	q=top;
	printf("\n");
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}	
}

int main()
{
	int secim;
    int sayi;
	while(1==1){
		printf("\n1-Push");
		printf("\n2-Pop");
		printf("\n3-Peek");
		printf("Yapmak istediginiz islemi seciniz ");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Girmek istediginiz sayi ");
				scanf("%d",&sayi);
				push(sayi);
				yazdir();
				break;
			case 2:
			    pop();
				yazdir();
				break;
			case 3:
			    printf("Top elemani: ",peek());
				break;	
		}
	}
	 return 0;
}
