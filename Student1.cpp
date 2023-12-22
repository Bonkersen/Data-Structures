#include<iostream>
#include<string>
using namespace std;
struct node{
	string enrollno;
	string name;
	struct node *next;
};
struct node *head=NULL;
void insert1()
{
    string enrollno;
    string name;
    int pos,i;
	cout<<"\nEnter Name:";
	cin>>name;
	cout<<"\nEnter enroll no:";
	cin>>enrollno;
	cout<<"\nEnter the position in list you want this student data to be inserted:";
	cin>>pos;
	struct node *b,*temp,*temp1;
	temp=head;
	temp1=NULL;
	b=new node();
	b->enrollno=enrollno;
	b->name=name;
	if(pos==1)
	{
	b->next=head;
	head=b;
	}
	else
	{
	  for(i=1;i<pos;i++)
	  {
		  temp1=temp;
		  temp=temp->next;
	  }
	  temp1->next=b;
	  b->next=temp;
	}

}
void printall()
{
	struct node* ptr;
	ptr=head;
	int p=0;
	while(ptr!=0)
	{
	    p++;
		cout<<"\n"<<p<<")"<<"\nName:"<<ptr->name;
		cout<<"\nEnrollno:"<<ptr->enrollno<<"\n";
		ptr=ptr->next;
	}
}
int main()
{
    int p=0;
	while(p!=-1)
    {
        cout<<"\nEnter choice:\n1.Insert\n2.Print\n3.Exit\n";
        cin>>p;
        switch(p)
        {
        case 1:
             insert1();
             break;
        case 2:
            printall();
            break;
        case 3:
            p=-1;
            break;
        }

    }

}
