#include <iostream>
using namespace std;

void Push(int value,int &top,int stack[],int max_Size);
void pop(int &top,int stack[]);
void display(int top,int stack[]);

int main()
{
    const int max_Size = 100;
    int stack[max_Size];
    int top=-1;

    pop(top,stack);
    Push(32,top,stack,max_Size);
    Push(45,top,stack,max_Size);
    Push(12,top,stack,max_Size);
    Push(27,top,stack,max_Size);
    pop(top,stack);
    Push(41,top,stack,max_Size);
    return 0;
}

void Push(int value,int &top,int stack[],int max_Size)
{
    if(top>max_Size-1)
    {
        cout<<"STACK OVERFLOW"<<endl;
    }
    else
    {
        top++;
        stack[top] = value;
        cout<<endl<<value<<" is Added into Stack."<<endl;
        display(top,stack);
    }
}

void pop(int &top,int stack[])
{
    if(top<=-1)
    {
        cout<<"STACK IS EMPTY"<<endl;
    }
    else
    {
        cout<<endl<<stack[top]<<" is removed from Stack."<<endl;
        top--;
        display(top,stack);
    }
}

void display(int top,int stack[])
{
    cout<<endl<<"Stack Values are = { ";
    for(int i=0; i<top; i++)
    {
        cout<<stack[i]<<", ";
    }
    cout<<stack[top]<<" }"<<endl;
}



/*
// USING GLOBAL VARIABLES
const int max_Size = 100;
int stack[max_Size];
int top = -1;

void Push(int value);
void pop();
void display();

int main()
{
    pop();
    Push(32);
    Push(45);
    Push(39);
    pop();
    Push(41);
    display();
    return 0;
}

void Push(int value)
{
    if(top>max_Size-1)
    {
        cout<<"STACK OVERFLOW"<<endl;
    }
    else
    {
        top++;
        stack[top] = value;
        cout<<endl<<value<<" is Added into Stack."<<endl;
        display();
    }
}

void pop()
{
    if(top<=-1)
    {
        cout<<"STACK IS EMPTY"<<endl;
    }
    else
    {
        cout<<endl<<stack[top]<<" is removed from Stack."<<endl;
        top--;
        display();
    }
}

void display()
{
    cout<<endl<<"Stack Values are = { ";
    for(int i=0;i<top;i++)
    {
        cout<<stack[i]<<", ";
    }
    cout<<stack[top]<<" }"<<endl;
}
*/
