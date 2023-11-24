#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
int size=0;
void print()
{
	node* ptr=new node();
        ptr=head;
	printf("\nLinked List:\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void begin(int data)
{
	node* b=new node();
	b->data=data;
	b->next=head;
	head=b;
	size++;

}
void reverse()
{
	struct node *current,*prev,*next;
	current=head;
	prev=NULL;
	if(size==1)
	{

	}
	else{
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
         head=prev;
	}
}
int main()
{
	head=NULL;
	begin(2);
	begin(10);
	begin(30);
	print();
	reverse();
	print();
}

