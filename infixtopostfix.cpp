#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char c)
{
    if(c=='+'||c=='-')
    {
        return 1;
    }
    if(c=='*'||c=='/')
    {
        return 2;
    }
    if(c=='^')
    {
        return 3;
    }
    return 0;
}
string convert(string infix)
{
    int i = 0;
    string postfix = "";
    stack <int>s;
     while(infix[i]!='\0')
    {
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')
        {
            postfix += infix[i];
            i++;
        }
       else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
            i++;

        }
        else{
            while(!s.empty() && precedence(infix[i])<=precedence(s.top()))
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    cout<<"\nPostfix:"<<postfix;
    return postfix;
}
int main()
{
    string infix;
    cout<<"\nEnter infix expression:";
    cin>>infix;
    string postfix;
    postfix = convert(infix);

    return 0;
}
