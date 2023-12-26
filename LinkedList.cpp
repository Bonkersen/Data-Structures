#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void print()
{
    struct node *ptr;
    ptr=head;
    int c=0;
    cout<<"\nLinked List:[";
    while(ptr!=NULL)
    {
        c++;
        cout<<" "<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"](INDEX="<<c<<")\n";
}
void insertbegin(int data)
{
    struct node *b;
    b=new node();
    b->data=data;
    b->next=head;
    head=b;
}
void insertend(int data)
{
    struct node *e,*temp;
    e=new node();
    e->data=data;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    e->next=temp->next;
    temp->next=e;
}
void insertatposition(int data,int pos)
{
    struct node *ins,*temp,*temp1;
    ins=new node();
    temp=head;
    ins->data=data;
    if(pos==1)
    {
         ins->next=head;
         head=ins;
    }
    else
    {
    for(int i=1;i<pos;i++)
    {
        temp1=temp;
        temp=temp->next;
    }
    ins->next=temp1->next;
    temp1->next=ins;
    }

}
void deleteatbegin()
{
    struct node *temp;
    temp=head;
    head=temp->next;
    temp->next=NULL;
    free(temp);
}
void deleteatend()
{
    struct node *temp,*temp1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    free(temp);
}
void deleteatposition(int pos)
{
    struct node *temp,*temp1;
    temp=head;
    if(pos==1)
    {
    temp=head;
    head=temp->next;
    temp->next=NULL;
    free(temp);
    }
    else
    {
    for(int i=1;i<pos;i++)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next=NULL;
    free(temp);
    }
}
void searchnode(int data)
{
    struct node *s;
    s=head;
    int p=1;
    while(s->data!=data)
    {
        p++;
        s=s->next;
    }
    cout<<"\nNode with data="<<s->data<<" is at position "<<p<<"\n";
}
void sortlinkedlist()
{
    int temp;
    struct node *current,*next=NULL;
    current=head;
    while(current!=NULL)
    {
       next=current->next;
        while(next!=NULL)
        {
            if(current->data>next->data)
            {
                temp=next->data;
                next->data=current->data;
                current->data=temp;
            }
            next=next->next;
        }
        current=current->next;
    }
}
int main()
{
  insertbegin(2);
  insertbegin(3);
  insertbegin(5);
  insertbegin(2);
  insertbegin(9);
  print();
  insertend(45);
  print();
  insertatposition(23,1);
  print();
  deleteatbegin();
  print();
  deleteatend();
  print();
  deleteatposition(1);
  print();
  searchnode(5);
  insertbegin(2);
  insertbegin(3);
  insertbegin(5);
  insertbegin(2);
  insertbegin(9);
  print();
  sortlinkedlist();
  print();
}
