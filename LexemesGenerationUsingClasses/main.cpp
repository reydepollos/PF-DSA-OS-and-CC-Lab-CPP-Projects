#include <iostream>

using namespace std;

class Paragraph
{
public:
    string word;
    Paragraph* link;
};

class LinkedList
{
public:
    Paragraph* head = nullptr;
    Paragraph* tail = nullptr;

    void insertion(string data)
    {
        Paragraph* temp=head;
        Paragraph* newNode=new Paragraph();
        newNode->word=data;
        newNode->link=nullptr;
        if(temp==nullptr)
        {
            head=tail=newNode;
        }
        else
        {
            tail->link=newNode;
            tail=newNode;
        }
    }

    void Display()
    {
        Paragraph* temp = head;
        cout<<"Linked List = { ";
        while(temp!=nullptr)
        {
            cout<<temp->word<<" -> ";
            temp=temp->link;
        }
        cout<<"NULL }"<<endl;

    }

};

int main()
{
    LinkedList Link;
    string data;
    int i=0;

    string para = "My Name is MUHAMMAD SALMAN SALEEM. I am studying from COMSATS University Lahore Campus.";
    int paraSize = para.length();
    cout<<"ParaGraph = "<<para<<"\nParagraph Length = "<<paraSize<<endl;

    while(i<paraSize)
    {
        while(isalnum(para[i]))
        {
            data = data + para[i];
            i++;
        }
        Link.insertion(data);
        data = "";
        while(para[i]==' ')
        {
            i++;
        }
        while(!isalnum(para[i]) && para[i]!=' ' && i<paraSize)
        {
            data = data + para[i];
            Link.insertion(data);
            i++;
        }
        while(para[i]==' ' && i<paraSize)
        {
            i++;
        }
        data=" ";
    }
    Link.Display();

    return 0;
}
