#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert1(int data)
{
    struct node *b,*temp;
    b=new node();
    b->data=data;
    temp=head;
    if(head==NULL)
    {
        head=b;
        b->next=head;
    }
    else{
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        b->next=head;
        temp->next=b;
        head=b;

    }
}
void print()
{
    struct node *ptr;
    ptr=head;
    cout<<"\nLinked List:[";
    while(ptr->next!=head)
    {
        cout<<" "<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<" "<<ptr->data<<" ]\n";
}
int main()
{
    insert1(2);
    insert1(10);
    insert1(20);
    insert1(30);
    insert1(40);
    insert1(50);
    insert1(60);
    insert1(70);
    print();
}
