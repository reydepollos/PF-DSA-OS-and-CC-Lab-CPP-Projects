#include <iostream>

using namespace std;

#define Max 100

char stack[Max];
int top = -1;

void push(char c)
{
    if(top >= Max-1)
    {
        cout<<"Stack Overflow.\n";
    }
    else
    {
        stack[++top] = c;
    }
}

char pop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty.";
        return '\0';
    }
    return stack[top--];
}

char peek()
{
    if(top==-1)
    {
        return '\0';
    }
    return stack[top];
}

int precedence(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPostfix(string exp)
{
    string result;

    for(int i=0; i<exp.length(); i++)
    {
        char c = exp[i];

        //if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        if(isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if ( c == ')')
        {
            while(top!=-1 && peek()!='(')
            {
                result += pop();
            }
            pop();
        }
        else
        {
            while(top!=-1 && precedence(peek()) >= precedence(c))
            {
                result += pop();
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        result +=pop();
    }

    cout<<endl<<"Postfix Expression : "<<result<<endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
