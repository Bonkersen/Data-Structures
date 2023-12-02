#include<iostream>
using namespace std;
int stack[10],top=-1,n;
void push()
{
  
  int data;
  if(top==n-1)
  {
	  cout<<"\nStack overflow\n";
  }
  else
  {	  
  cout<<"\nEnter Value: ";
  cin>>data;
   top=top+1;
  stack[top]=data;
  }
}
void pop()
{
	if(top == -1)
	{
		cout<<"\nStack is empty!\n";
	}
	else{
	top=top-1;
	}
}
void show()
{
	cout<<"\nStack Elements:\n";
	for(int i=top;i>=0;i--)
	{
		cout<<"\n"<<stack[i];
	}
}
int main()
{
	cout<<"\nEnter stack size:";
	cin>>n;
	int m=1,l;
	while(m!=0)
	{
		cout<<"\n1.Push\n2.Pop\n3.Show\n4.Exit\n";
		cin>>l;
		switch(l)
		{
			case 1:
			{
			push();
			break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				show();
				break;
			}
			case 4:
			{
				m=0;
			}
		}
	}
}