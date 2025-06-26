#include <iostream>

#define Max 10

int stack[Max];
int top = -1;

using namespace std;

void push();
void isFull();
void pop();
void isEmpty();
void display();

int main()
{
    char ch = 'y';
    int choice = 0;
    while(ch=='y' || ch=='Y')
    {
        cout<<endl<<"Enter (1) Push (2) Pop (3) Display (4) isEmpty (5) isFull : ";
        cin>>choice;
        switch(choice)
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
            display();
            break;
        }
        case 4:
        {
            isEmpty();
            break;
        }
        case 5:
        {
            isFull();
            break;
        }
        default:
        {
            cout<<"Invalid Input!"<<endl;
            break;
        }
        }
        cout<<"Enter (y|Y) for Continue or any other to Exit : ";
        cin>>ch;
    }
    return 0;
}

void push()
{
    int value;
    if(top==Max-1)
    {
        cout<<"Stack is Full."<<endl;
    }
    else
    {
        cout<<"Enter the Value = ";
        cin>>value;
        top++;
        stack[top] = value;
        cout<<"Value "<<value<<" is pushed in Stack."<<endl;
    }
}

void isFull()
{
    if(top==Max-1)
    {
        cout<<"Stack is Full."<<endl;
    }
    else
    {
        cout<<"Stack has space to store items."<<endl;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty."<<endl;
    }
    else
    {
        top--;
    }
}

void isEmpty()
{
    if(top==-1)
    {
        cout<<"Stack is Empty."<<endl;
    }
    else
    {
        cout<<"Stack is not Empty"<<endl;
    }
}

void display()
{
    for(int i=0; i<=top; i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
