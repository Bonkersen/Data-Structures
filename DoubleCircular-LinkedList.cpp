#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void insert1(int data,int pos)
{
    struct node *b,*last,*ins,*insprev;
    last=head;
    ins=head;
        int l=1;
    b=new node();
    b->data=data;
    b->prev=NULL;
    if(head==NULL)
    {
        head=b;
        b->next=b;
        b->prev=b;
    }
    else if(pos==1)
    {
         while(last->next!=head)
        {
            last=last->next;
            l++;
        }
         b->next=head;
         b->prev=last;
         last->next=b;
         head=b;
    }
    else if(pos>1 && pos!=l)
    {
        for(int i=1;i<pos;i++)
        {
            insprev=ins;
            ins=ins->next;
        }
        insprev->next=b;
        b->prev=insprev;
        b->next=ins;
        ins->prev=b;

    }
    else if(pos==l)
    {
         while(last->next!=head)
        {
            last=last->next;
            l++;
        }
        b->next=last->next;
        last->next=b;
        b->prev=last;
        head->prev=b;
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
    insert1(1,1);
    insert1(2,1);
    insert1(3,1);
    insert1(4,1);
    insert1(5,1);
    insert1(6,1);
    insert1(4,7);
    print();

}
