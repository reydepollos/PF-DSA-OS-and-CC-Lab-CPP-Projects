#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* link;
};

void display(Node* head)
{
    Node* temp = head;
    cout<<endl<<"Linked List : { ";
    while(temp!=nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->link;
    }
    cout<<"NULL }"<<endl;
}

void insertionAtStart(Node* &head)
{
    int value;
    cout<<"Add the value in start of List : ";
    cin>>value;
    Node* newNode = new Node();
    newNode->data = value;
    newNode->link = head;
    head = newNode;
    display(head);
}

void insertionAtLast(Node* &head, Node* &tail)
{
    int value;
    cout<<"Add the Value in Last of List : ";
    cin>>value;

    Node* temp = head;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->link = nullptr;

    if(temp==nullptr)
    {
        head = tail = newNode;
        return;
    }
    tail->link = newNode;
    tail = newNode;
    display(head);
}

void deleteFirstElement(Node* &head)
{
    Node* temp = head;
    if(temp==nullptr)
    {
        cout<<"List is Empty."<<endl;
        return;
    }
    head = head->link;
    delete(temp);
    cout<<"\nList after Deleting First Element."<<endl;
    display(head);
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    char ch = 'y';
    int choice;

    while(ch=='y' || ch=='Y')
    {
again:
        cout<<"\n(1)Insertion at Start\n(2)Insertion at Last\n(3)Display List\nEnter Your Selection : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
        {
            insertionAtStart(head);
            break;
        }
        case 2:
        {
            insertionAtLast(head,tail);
            break;
        }
        case 3:
        {
            display(head);
            break;
        }
        case 4:
        {
            deleteFirstElement(head);
            break;
        }
        default:
        {
            cout<<"Invalid Input.";
            goto again;
        }
        }

        cout<<"Enter (y/Y) to Continue or Any other key to Exit : ";
        cin>>ch;
    }

    return 0;
}
