#include <iostream>

using namespace std;

const int maxSize = 10;

void enqueue(int queue[],int &front,int &rear,int value);
void displayQueue(int &front,int &rear,int queue[]);
void dequeue(int queue[],int &front,int &rear);
//void display(int &front,int &rear,int queue[]);

int main()
{
    int queue[maxSize];
    int front = -1;
    int rear = -1;
    int option,value;
againOption:
    cout<<"\nEnter your Option [ (1)Enqueue (2)Dequeue (3)Display (4)Exit (5)Values Count ] = ";
    cin>>option;
    switch(option)
    {
    case 1:
    {
        cout<<"Enter Value in Queue = ";
        cin>>value;
        enqueue(queue,front,rear,value);
        goto againOption;
    }
    case 2:
    {
        dequeue(queue,front,rear);
        goto againOption;
    }
    case 3:
    {
        displayQueue(front,rear,queue);
        goto againOption;
    }
    case 4:
    {
        cout<<endl<<endl<<"\t\t======== PROGRAM TERMINATED ========"<<endl<<endl;
        return 0;
    }
    case 5:
    {
        if(front==0 && rear-front+1==1)
        {
            cout<<endl<<rear-front+1<<" Value in Queue."<<endl;
        }
        else if(front>-1)
        {
            cout<<endl<<rear-front+1<<" Values in Queue."<<endl;
        }
        else
        {
            cout<<endl<<rear-front<<" Value in Queue."<<endl;
        }
        goto againOption;
    }
    default:
    {
        cout<<"Invalid Option Selected ... Again ";
        goto againOption;
    }
    }
    return 0;
}

void enqueue(int queue[],int &front,int &rear,int value)
{
    if(rear-front == maxSize-1)
    {
        cout<<endl<<"Queue overflow."<<endl;
    }
    else
    {
        rear++;
        queue[rear] = value;
        cout<<endl<<value<<" is Added in Queue.";
        if(front == -1)
        {
            front = 0;
        }
    }
    displayQueue(front,rear,queue);
}


void dequeue(int queue[],int &front,int &rear)
{
    int element;
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty."<<endl;
    }
    else
    {
        element = queue[front];
        cout<<endl<<element<<" is Removed from Queue.";
        if(front==rear)
        {
            front = rear = -1;
            displayQueue(front,rear,queue);
        }
        else
        {
            front++;
            displayQueue(front,rear,queue);
        }
    }
}

void displayQueue(int &front,int &rear,int queue[])
{
    cout<<endl<<"Queue Elements = { ";
    for(int i=front; i<rear; i++)
    {
        cout<<queue[i]<<", ";
    }
    if(rear>-1)
    {
        cout<<queue[rear];
    }
    cout<<" }"<<endl;
}

/*
void display(int &front,int &rear,int queue[])
{
    cout<<endl<<endl<<"Queue Elements = { ";
    for(int i=0;i<rear;i++)
    {
        cout<<queue[i]<<", ";
    }
    cout<<queue[rear]<<" }"<<endl;
}
*/
