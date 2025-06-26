#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* link;
};

void Insertion(Node*& head,Node*& tail,string data);
void DisplayListElements(Node*& head);

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    char space = ' ';
    string paragraph = "My Name is Muhammad Salman Saleem. I am Studying bachelor of sciences in computer science in COMSATS University Lahore Campus. This is my last Semester.";
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
    DisplayListElements(head);
    return 0;
}

void Insertion(Node*& head,Node*& tail,string data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = nullptr;

    if(head==nullptr)
    {
        head = newNode;
        tail=newNode;
        return;
    }
    tail->link = newNode;
    tail = tail->link;
}

void DisplayListElements(Node*& head)
{
    int i=1;
    Node* temp = head;
    cout<<"\nLinked List = { \n\t(";
    while(temp!=nullptr)
    {
        cout<<i<<") "<<temp->data;
        temp = temp->link;
        i++;
        if(i%5!=0)
        {
            cout<<" (";
        }
        if(i%5==0)
        {
            cout<<" ("<<i<<") "<<temp->data<<endl<<"\t(";
            i++;
            temp = temp->link;
        }
    }
    cout<<"*) NULL \n}"<<endl<<endl;
}

//void DisplayListElements(Node*& head)
//{
//    Node* temp = head;
//    cout<<"\nLinked List = { ";
//    while(temp!=nullptr)
//    {
//        cout<<temp->data<<"  ->  ";
//        temp = temp->link;
//    }
//    cout<<"NULL }"<<endl<<endl;
//}
