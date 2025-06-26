#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* link;
};

void Insertion(Node*& head,Node*& tail, int value,int &index);
void InsertionAtIndex(Node* &head, int &index,int &indexSelected);
void Display(Node* head);
void deleteFirstElement(Node* &head,int &index);
void deleteLastElement(Node* &head,Node* &tail);


int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int index=0;
    int indexSelected;
    int value;
    char alpha = 'y';
    while(alpha=='y' || alpha=='Y')
    {

        for(int i=1; i<=3; i++)
        {
            cout<<"Insert Value - "<<i<<" = ";
            cin>>value;
            Insertion(head,tail,value,index);
        }
        cout<<endl<<endl;
        Display(head);
        InsertionAtIndex(head,index,indexSelected);
        deleteFirstElement(head,index);
        deleteLastElement(head,tail);

        cout<<"Enter (y/Y) for continue Or Any other key for Exit = ";
        cin>>alpha;
    }
    return 0;
}

void Insertion(Node*& head,Node*& tail, int value,int &index)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->link = nullptr;
    if(head==nullptr)
    {
        head = newNode;
        tail = newNode;
        index = 1;
    }
    else
    {
        tail->link = newNode;
        tail = tail ->link;
        index++;
    }
}

void InsertionAtIndex(Node* &head, int &index,int &indexSelected)
{
    Node* temp = head;
    Node* next = head;
    int value;
indexAgain:
    cout<<"Enter an Index at which you want to Insert the value ( index <= "<<index+1<<" ) = ";
    cin>>indexSelected;
    while(indexSelected>index+1 || indexSelected<0)
    {
        cout<<"Again ... ";
        goto indexAgain;
    }
    cout<<"Enter Value = ";
    cin>>value;
    Node* newNode = new Node();
    newNode->data = value;
    newNode->link = nullptr;
    if(indexSelected==1)
    {
        newNode->link = head;
        head = newNode;
        index++;
        Display(head);
    }
    else
    {
        for(int i=1; i<indexSelected-1; i++)
        {
            temp = temp->link;
        }
        next = temp->link;
        temp->link = newNode;
        newNode->link = next;

        index++;
        Display(head);
    }
}

void Display(Node* head)
{
    Node* temp = head;
    cout<<"Linked List Elements = { ";
    while(temp->link!=nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->link;
    }
    cout<<temp->data<<" }";
    cout<<endl<<endl;
}

void deleteFirstElement(Node* &head,int &index)
{
    Node* temp = head;
    head = head->link;
    index--;
    delete temp;
    Display(head);
}

void deleteLastElement(Node* &head,Node* &tail)
{
    Node* temp = head;
    Node* lastElement = head;
    int last;
    if(head==nullptr)
    {
        cout<<"List is Empty.";
    }
    while(temp->link!=nullptr)
    {
        lastElement = temp;
        temp = temp->link;
    }
    last = temp->data;
    cout<<"Last = "<<last<<endl;
    delete(temp);
    tail = lastElement;
    Display(head);
}
