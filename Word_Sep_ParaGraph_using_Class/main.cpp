#include<iostream>

using namespace std;
struct Node{
    string data;
    Node* link;
};


class LinkedList
{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void Insertion(string data)
    {
        Node* newNode = new Node(); // Node* newNode = new Node(data); (if values passed through Constructors)
        newNode->data = data;       // If values not passed by contructors
        newNode->link = nullptr;    // If values not passed by contructors
        if(head==nullptr)
        {
            head = newNode;
            tail=newNode;
        }
        else
        {
            tail->link = newNode;
            tail = tail -> link;
        }
    }

    void DisplayListElements()
    {
        int i=1;
        Node* temp = head;
        cout<<"\nLinked List = {";
        while(temp!=nullptr)
        {
            cout<<"\t("<<i<<") "<<temp->data;
            temp = temp->link;
            i++;
        }
        cout<<"*) NULL \n}"<<endl<<endl;
    }
};

int main()
{
    LinkedList List;
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

    List.Insertion(word);
    word = emptyWord;
    character = paragraph[counter];
    if(character!=space)
    {
        word = word + character;
        List.Insertion(word);
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
    List.DisplayListElements();
    return 0;
}
