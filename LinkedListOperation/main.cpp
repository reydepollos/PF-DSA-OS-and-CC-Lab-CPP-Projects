#include <iostream>

using namespace std;

struct Node{
    string data;
    Node* link;
};

void Insertion(Node*& head ,Node*& tail, string value);
void Display(Node* head);

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    string name;

    for(int i=1;i<=5;i++)
    {
        cout<<"Insert Value - "<<i<<" = ";
        cin>>name;
        Insertion(head,tail,name);
    }
    cout<<endl<<endl;
        Display(head);

    return 0;
}

void Insertion(Node*& head ,Node*& tail, string value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->link = nullptr;
    if(head==nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->link = newNode;
    tail = tail ->link;
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
