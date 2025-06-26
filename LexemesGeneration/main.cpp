#include <iostream>

using namespace std;

struct Paragraph
{
    string word;
    Paragraph* link;
};

void insertion(Paragraph* &head,Paragraph* &tail, string data){
    Paragraph* temp=head;
    Paragraph* newNode=new Paragraph();
    newNode->word=data;
    newNode->link=nullptr;
    if(temp==nullptr){
        head=tail=newNode;
    }
    else{
        tail->link=newNode;
        tail=newNode;
    }

}

void Display(Paragraph* &head){
    Paragraph* temp = head;
    cout<<"Linked List = { ";
    while(temp!=nullptr){
        cout<<temp->word<<" -> ";
        temp=temp->link;
    }
    cout<<"NULL }"<<endl;
}

int main()
{
    Paragraph* head = nullptr;
    Paragraph* tail = nullptr;
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
        insertion(head,tail,data);
        data = "";
        while(para[i]==' ')
        {
            i++;
        }
        while(!isalnum(para[i]) && para[i]!=' ' && i<paraSize)
        {
            data = data + para[i];
            insertion(head, tail, data);
            i++;
        }
        while(para[i]==' ' && i<paraSize)
        {
            i++;
        }
        data=" ";
    }
    Display(head);

    return 0;
}
