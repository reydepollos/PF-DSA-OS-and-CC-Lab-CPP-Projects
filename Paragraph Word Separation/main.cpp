#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* link;
};

void Insertion(Node*& head,string data);
void DisplayListElements(Node*& head);

int main()
{
    Node* head = nullptr;
    string paragraph = "My Name is Muhammad Salman Saleem. I am Studying bachelor of sciences in computer science in COMSATS University Lahore Campus.";
    int strlength = paragraph.length();
    cout<<"String Length = "<<strlength;
    int counter = 0;
    string word;
    string emptyWord;
    char character;
    cout<<endl;

again_check:
    while((paragraph[counter]>='a' && paragraph[counter]<='z') || (paragraph[counter]>='A' && paragraph[counter]<='Z') )
    {
        character = paragraph[counter];
        word = word + character;
        counter++;
    }
    Insertion(head,word);
    word = emptyWord;
    if(paragraph[counter]!=' ')
    {
        character = paragraph[counter];
        word = word + character;
        Insertion(head,word);
    }
    counter++;
    if(counter<strlength)
    {
        word = emptyWord;
        goto again_check;
    }
    DisplayListElements(head);
    return 0;
}

void Insertion(Node*& head,string data)
{
    Node* temp = head;

    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = nullptr;

    if(head==nullptr)
    {
        head = newNode;
        return;
    }

    while(temp->link!=nullptr)
    {
        temp = temp->link;
    }
    temp->link = newNode;

}

void DisplayListElements(Node*& head)
{
    Node* temp = head;
    cout<<"\nLinked List = { ";
    while(temp!=nullptr)
    {
        cout<<temp->data<<" -> ";
        temp = temp->link;
    }
    cout<<"NULL }"<<endl<<endl;
}
