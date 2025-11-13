#include<iostream>
#include<string.h>
using namespace std;

class parenthesis
{
char st[20];
int top;
    public :
       void push(char a);
       void pop();
       void input();
};

void parenthesis::push(char a)
{
    top++;
    st[top] = a;
}

void parenthesis::pop()
{
    top--;
}

void parenthesis::input()
{
    char ch[20];
    int i = 0;
    top = -1;  
    cout << "Enter the expression:";
    cin >> ch;

while (i<strlen(ch))  
    {
        if ((ch[i] == '(') || (ch[i] == '[') || (ch[i] == '{'))  
        {
        push(ch[i]);
        }
        else if (ch[i] == ')')  
        {
         if ( st[top] == '(') 
            {
             pop();
             cout<<"expression is matched\n";
            }
         else
            {
                cout << "Matching opening bracket '(' is not found! \n";
                return;
            }
        }
        else if (ch[i] == '}')  
        {
            if (st[top] == '{')  
            {
                pop();
                 cout<<"expression is matched\n";
            }
            else
            {
                cout << "Matching opening bracket '{' is not found!.\n";
                return;
            }
        }
        else if (ch[i] == ']') 
        {
            if ( st[top] == '[') 
            {
                pop();
                 cout<<"expression is matched\n";
            }
            else
            {
                cout << "Matching opening bracket '[' is not found! .\n";
                return;
            }
        }
        i++; 
    }

if(top==-1)
{
    cout<<"stack is empty\n";
    cout<<"expression is well parenthesized";
}
else
{
    while(top!=-1)
    {

        if(st[top]=='(')
        {
            pop();
            cout<<"matching ')' is not found\n";
        }

         if(st[top]=='[')
        {
            pop();
            cout<<"matching ']' is not found\n";
        }

         if(st[top]=='{')
        {
            pop();
            cout<<"matching '}' is not found";
        }
        else
        {
           cout<<"expression is not well parenthesized";
        }
    }
}
}
    



int main()
{
  parenthesis p;
  p.input();
  return 0;
}

