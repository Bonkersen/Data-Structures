#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
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
    int i=0;
    reverse(infix.begin(),infix.end());
    string prefix;
    stack <int>s;
    while(infix[i]!='\0')
    {
        if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z')
        {
            prefix+=infix[i];
            i++;
        }
        else if(infix[i]==')')
        {
            s.push(infix[i]);
            i++;
        }
        else if(infix[i]=='(')
        {
            while(s.top()!=')'){
                prefix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while(!s.empty() && precedence(infix[i])<=precedence(s.top()))
            {
                prefix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        prefix+=s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}
int main()
{
    string infix="(a+b)*(c+d)";
    cout<<"Prefix:"<<convert(infix);
}
