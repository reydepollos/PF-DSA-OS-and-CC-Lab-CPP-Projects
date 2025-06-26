#include <iostream>
#include <string>

using namespace std;

struct Node{
    string data;
    Node* prev;
    Node* next;

    Node(string data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void Insertion(Node*& head,Node*& tail,string data);
void print(Node* head);
void printReverse(Node* tail);


int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    char space = ' ';
    string paragraph;
    cout<<"Enter Paragraph"<<endl;
    getline(cin,paragraph);
    int strlength = paragraph.length();
    cout<<"String Length = "<<strlength;
    int counter = 0;
    string word;
    string emptyWord;
    char character;
    cout<<endl;

again_check:
    while((paragraph[counter]>='a' && paragraph[counter]<='z') || (paragraph[counter]>='A' && paragraph[counter]<='Z'))
    {
        character = paragraph[counter];
        word = word + character;
        counter++;
    }

    Insertion(head,tail,word);
    word = emptyWord;
    character = paragraph[counter];
    if(character!=space)
    {
        word = word + character;
        Insertion(head,tail,word);
    }
    counter++;
    while(paragraph[counter]==space)
    {
        counter++;
    }
    if(counter<strlength)
    {
        word = emptyWord;
        goto again_check;
    }
    print(head);
    //printReverse(tail);
    return 0;
}


void Insertion(Node*& head,Node*& tail,string data)
{
    Node* newNode = new Node(data);
    if(head==nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void print(Node* head)
{
    Node* temp = head;
    cout<<"\nLinked List = { ";
    while(temp!=nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->next;
    }
    cout<<"}"<<endl;
}

void printReverse(Node* tail)
{
    Node* temp = tail;
    cout<<"\nLinked List = { ";
    while(temp!=nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->prev;
    }
    cout<<"}"<<endl;
}
