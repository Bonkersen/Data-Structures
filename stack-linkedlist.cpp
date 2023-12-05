#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
struct node *top=NULL;
void push()
{
	int data;
	cout<<"\nEnter Value: ";
	cin>>data;
	struct node *push;
	push = new node();
	push->data=data;
	push->next=top;
	top=push;
}
void pop()
{
	if(top==NULL)
	{
		cout<<"\nStack is Empty!\n";
	}
	else{
	struct node *pop;
	pop=top;
	top=pop->next;
	free(pop);
	}
}
void print()
{
	struct node *ptr;
	ptr=new node ();
	ptr=top;
	cout<<"\nStack:";
	while(ptr!=NULL)
	{
		cout<<" "<<ptr->data;
		ptr=ptr->next;
	}
	cout<<"\n";
}
int main()
{
	int n,x=1;
	while(x!=0)
	{
	cout<<"\n1.Push\n2.Pop\n3.Exit\n";
	cin>>n;
	switch (n)
	{
		case 1:
		{
			push();
			print();
			break;
		}
		case 2:
		{
			pop();
			print();
			break;
		}
		case 3:
		{
			x=0;
		}
	}
	}
	
	
}