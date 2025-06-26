#include <iostream>

using namespace std;

struct Node{
    string word;
    Node* link;
};

void Insertion(Node* &head,Node* &tail,string word)
{
    Node* temp = head;
    Node* newNode = new Node();
    newNode->word = word;
    newNode->link = nullptr;
    if(temp==nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->link = newNode;
        tail = newNode;
    }
}

void display(Node* head)
{
    cout<<"Linked List = { ";
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->word<<" -> ";
        temp = temp->link;
    }
    cout<<" NULL }"<<endl;
}

int main()
{
//    string paragraph;
//    cout<<"Enter Paragraph "<<endl;
//    getline(cin,paragraph);
//    cout<<"Paragraph = "<<paragraph<<endl;
    Node* head = nullptr;
    Node* tail = nullptr;
    string word;

    for(int i=0;i<5;i++)
    {
        cout<<"Enter Word = ";
        cin>>word;
        Insertion(head,tail,word);
    }
    display(head);


    return 0;
}
