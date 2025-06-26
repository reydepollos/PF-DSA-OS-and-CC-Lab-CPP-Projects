#include <iostream>

using namespace std;

char Rule;

class Node
{
public:
    string data;
    Node* previous;
    Node* next;
};

class DoublyLinkedList
{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void Insertion(string data)
    {
        Node* newNode = new Node();
        newNode->previous = nullptr;
        newNode->next = nullptr;
        newNode->data = data;
        if(head==nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Display()
    {
        Node* temp = head;
        cout<<"\nLinked List = { ";
        while(temp!=nullptr)
        {
            cout<<temp->data;
            if(temp->next!=nullptr)
            {
                cout<<" | ";
            }
            temp = temp->next;
        }
        cout<<" } "<<endl;
    }

};

int main()
{
    DoublyLinkedList List;
    string line, word;
    int strSize=0, i=0;
    cout<<"Enter the Valid String to check Grammar is Left Recursion or not: "<<endl;
    getline(cin,line);
    strSize = line.length();
    cout<<"Length = "<<strSize<<endl;
    if(strSize==0)
    {
        cout<<"String is Empty."<<endl;
    }
    while(i<strSize)
    {
        while(!isalpha(line[i]) && i<strSize)
        {
            i++;
        }
        Rule = line[i];
        cout<<"\nRule = "<<Rule;
        i++;
        while(i<strSize)
        {
            while(line[i]=='-' && line[i+1]=='>')
            {
                i = i+2;
            }
            while(line[i]==' ')
            {
                i++;
            }
            while(line[i]!='|' && line[i]!=' ' && i<strSize)
            {
                word = word + line[i];
                i++;
            }
            if(word.length()>0)
            {
                List.Insertion(word);
                word = "";
            }
            i++;
        }
    }

    List.Display();

    return 0;
}
