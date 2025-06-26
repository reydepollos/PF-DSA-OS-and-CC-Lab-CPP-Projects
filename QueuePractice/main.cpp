#include <iostream>

using namespace std;

#define maxSize 100

int queue[maxSize];
int front = -1;
int rear = -1;

void enqueue()
{
    if(rear == maxSize-1)
    {
        cout<<"Queue is full. Can not Enqueue."<<endl;
        return;
    }
    if(front==-1 && rear==-1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    int value;
    cout<<"Enter the Value to Enqueue : ";
    cin>>value;
    queue[rear]=value;
    cout<<value <<" enqueued to the queue."<<endl;
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty. Can not Dequeue."<<endl;
        return;
    }
    cout<<queue[front]<<" dequeued from the Queue."<<endl;
    if(front==rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

int getFront()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty."<<endl;
        return 0;
    }
    cout<<queue[front];
    return queue[front];
}

void display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty."<<endl;
        return;
    }
    cout<<"Queue Elements = ";
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    char ch = 'y';
    int choice;

    while(ch=='y' || ch=='Y')
    {
        again:
        cout<<"Enter your Choice (1)Enqueue (2)Dequeue (3)Display : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                enqueue();
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        default:
            {
                cout<<"Invalid Input. Again";
                goto again;
            }
        }

        cout<<"Enter y/Y for continue | Any other key to Exit : ";
        cin>>ch;
        cout<<endl;
    }


    return 0;
}
