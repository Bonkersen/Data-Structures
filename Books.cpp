#include<iostream>
#include<string>
using namespace std;
struct node
{
	int price;
	string title,author;
	struct node *next;
};
struct node *head;
void inbook(int price,string title,string author)
{
	struct node *book;
	book=new node();
	book->price=price;
	book->title=title;
	book->author=author;
	book->next=head;
	head=book;
}
void display()
{
	int k=1;
	struct node *ptr;
	ptr=new node();
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<k<<"\nTitle:"<<ptr->title<<"\nAuthor:"<<ptr->author<<"\nPrice"<<ptr->price<<"\n";
		k++;
		ptr=ptr->next;
	}
}
void sort()
{
	struct node *current;
	struct node *n;
	current=head;
	n=NULL;
	int tprice;
	string tauthor,ttitle;
	while(current!=0)
	{
		n=current->next;
		while(n!=0)
		{
			if(current->price > n->price)
			{
			tprice=current->price;
			tauthor=current->author;
			ttitle=current->title;
			current->price=n->price;
			current->author=n->author;
			current->title=n->title;
			n->price=tprice;
			n->author=tauthor;
			n->title=ttitle;
			
			}
			n=n->next;
		}
		current=current->next;
	}
}
int main()
{
	int u=1,p,price;
	string title,author;
	while(u!=0)
	{
		cout<<"\n1.Enter book details\n2.Display all\n3.Display Book with max price\n4.Exit\n";
		cin>>p;
		switch(p)
		{
			case 1:
			{
		cout<<"\nEnter book title:";
		cin>>title;
		cout<<"\nEnter book author:";
		cin>>author;
		cout<<"\nEnter book price:";
		cin>>price;
		inbook(price,title,author);
		break;
		
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				struct node *end;
				end=new node();
				end=head;
				sort();
				while(end->next!=NULL)
				{
					end=end->next;
				}
				cout<<"\nMax price-\n"<<"\nTitle:"<<end->title<<"\nAuthor:"<<end->author<<"\nPrice:"<<end->price<<"\n";
				break;
			}
			case 4:
			{
				u=0;
				break;
			}
		}
	}
	
	
	
}