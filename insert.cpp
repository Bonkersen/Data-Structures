#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
void print()
{
	node* ptr=new node();
	ptr=head;
	while(ptr!=0)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void insert(int data,int n)
{
	node* temp1=new node();
	temp1->data=data;
	node* temp2;
        temp2 = head;

	if(n==1)
	{
		temp1->next=head;
		head=temp1;
	}
	else if(n==2)
	{
		temp1->next=temp2->next;
		temp2->next=temp1;
	}
	else
	{
		for(int i=0;i<n-2;i++)
		{
			temp2=temp2->next;
		}
		temp1->next=temp2->next;
                temp2->next=temp1;

	}
}
void insertbegin(int data)
{
	node* b=new node();
	b->data=data;
	b->next=head;
	head=b;
}
void insertend(int data)
{
	node* end=new node();
	end->data=data;
	node* t;
	t=head;
	while(t->next!=0)
	{
		t=t->next;
	}
	end->next=t->next;
	t->next=end;
}
void delet(int n)
{
	struct node *temp;
	struct node *temp2;
	temp=head;
	if(n == 1)
	{
		head=temp->next;
		free(temp);
	}
	else
	{
		for(int i=0;i<n-2;i++)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=temp2->next;
		free(temp2);
	}
}
void deletebegin()
{
	struct node *be;
	be=head;
	head=be->next;
	free(be);
}
void deleteend()
{
	struct node *e;
	struct node *io;
	e=head;
	while(e->next!=0)
	{
		io=e;
		e=e->next;
	}
	io->next=NULL;
	free(e);
}
int main()
{
	int n;
	insert(21,1);
	insert(67,2);
	insert(87,3);
	insert(32,1);
	insert(69,2);
	insert(90,5);
	insertend(43);
	insertbegin(2);
	print();
	printf("\nEnter pos of node:");
	scanf("%d",&n);
	deletebegin();
	deleteend();
	delet(n);
	print();

}
