
/*
Group D-10
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not.
*/


#include <iostream>
using namespace std;
#define size 10

class stack_exp
{
    int top;
    char stk[size];
public:
    stack_exp()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stack_exp::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stack_exp::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stack_exp::isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stack_exp::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stack_exp s1;
    char exp[25],ch;
    int flag=0;
    cout<<"\n\n\nEnter the expression to check whether it is in well form or not :  ";
    cin>>exp;
    if((exp[0]==')')||(exp[0]==']')||(exp[0]=='}'))
    {
        cout<<"\n Expression is Invalid !!!!\n";
        return 0;
    }
    else
    {
        for(int i=0;exp[i]!='\0';i++)
        {
            ch=exp[i];
            switch(ch)
            {
            case '(':s1.push(ch);
                     break;
            case '[':s1.push(ch);
                     break;
            case '{':s1.push(ch);
                     break;
            case ')':if(s1.pop() != '(')
                     {
                         flag=1;
                     }
                     break;
            case ']':if(s1.pop() != '[')
                     {
                         flag=1;
                     }
                     break;
            case '}':if(s1.pop() != '{')
                     {
                         flag=1;
                     }
                     break;
            }
            if(flag==1)
            {
                 cout<<"\n\t Sorry !!! Invalid Expression OR Expression is not well Parenthesized....\n";
                 return 0;
            }
        }

    }
    if(s1.isempty())
    {
        cout<<"\n\t Expression is well parenthesized!!!!!\n";
    }
    else
    {
        cout<<"\n\t Sorry !!! Invalid Expression OR Expression is not well Parenthesized....\n";
    }
    return 0;
}
'''Time Complexity: O(n), where n is the length of the input string.
Space Complexity: O(n), where n is the length of the input string (due to storing the input expression). The space used by the stack is constant (O(1)).'''