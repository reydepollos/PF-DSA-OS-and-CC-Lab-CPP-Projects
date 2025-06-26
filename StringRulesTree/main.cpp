#include <iostream>

using namespace std;

class Production
{
public:
    string data;
    Production* Next;
    Production* Previous;

    Production(string data):data(data), Next(nullptr), Previous(nullptr) {};
};

class LinkedList
{
private:
    Production* Head;
    Production* Tail;
public:
    LinkedList():Head(nullptr),Tail(nullptr) {};

    void Insertion(string data)
    {
        Production* newProduction = new Production(data);
        if(Head==nullptr)
        {
            Head = Tail = newProduction;
        }
        else
        {
            Tail->Next = newProduction;
            newProduction->Previous = Tail;
            Tail = newProduction;
        }
    }

    void display()
    {
        Production* temp =Head;
        cout<<endl<<"Production = { ";
        while(temp->Next!=nullptr)
        {
            cout<<temp->data<<" , ";
            temp = temp->Next;
        }
        cout<<temp->data<<" }"<<endl;
    }

    void displayReverse()
    {
        Production* temp =Tail;
        cout<<endl<<"Production (Reverse Print) = { ";
        while(temp->Previous!=nullptr)
        {
            cout<<temp->data<<" , ";
            temp = temp->Previous;
        }
        cout<<temp->data<<" }"<<endl;
    }

};

int main()
{
    LinkedList List;
    int strlength;
    string rule2 = ";",word, emptyWord;
    char character,space=' ';
    int counter = 0;
    string paragraph = "A->id+E; E ->E+E | E*E| id ; ";
    //cout<<"Enter String"<<endl;
    //getline(cin,paragraph);
    strlength = paragraph.length();
    cout<<"String = "<<paragraph<<endl;
    cout<<"String Length = "<<strlength<<endl;

    while(counter<strlength)
    {
        while((paragraph[counter]!='-' && paragraph[counter+1]!='>') && paragraph[counter]!=';' && paragraph[counter]!='|' && paragraph[counter]!=' ')
        {
            character = paragraph[counter];
            word = word + character;
            counter++;
        }
        if(paragraph[counter]=='-' && paragraph[counter+1]=='>'){counter = counter + 2;}
        while(paragraph[counter]==';' || paragraph[counter]=='|' || paragraph[counter]==' '){counter++;}
        if(word!=emptyWord)
        {
            cout<<endl<<"Token = "<<word<<endl;
            List.Insertion(word);
            word = emptyWord;
        }
    }

    List.display();
    List.displayReverse();

    cout<<endl<<"/////////////////////////////////////////////////"<<endl;

    return 0;
}


/*
struct Rule
{
    string ruleDefined;
    Rule* Next;
    Rule* Previous;

    Rule(string ruleDefined)
    {
        this->ruleDefined = ruleDefined;
        this->Next = nullptr;
        this->Previous = nullptr;
    }
};

struct Production
{
    string data;
    Production* Next;
    Production* Previous;

    Production(string data)
    {
        this->data = data;
        this->Next = nullptr;
        this->Previous = nullptr;
    }
};

void Insertion(Production* &Head,Production* &Tail, string data)
{
    Production* newProduction = new Production(data);
    if(Head==nullptr)
    {
        Head = Tail = newProduction;
    }
    else
    {
        Tail->Next = newProduction;
        newProduction->Previous = Tail;
        Tail = newProduction;
    }
}

void display(Production* Head)
{
    Production* temp =Head;
    cout<<endl<<"Production = { ";
    while(temp->Next!=nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->Next;
    }
    cout<<temp->data<<" }"<<endl;
}

void displayReverse(Production* Tail)
{
    Production* temp =Tail;
    cout<<endl<<"Production (Reverse Print) = { ";
    while(temp->Previous!=nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->Previous;
    }
    cout<<temp->data<<" }"<<endl;
}

int main()
{
    Production* Head = nullptr;
    Production* Tail = nullptr;
    Rule* First = nullptr;
    Rule* Last = nullptr;
    int strlength;
    string rule2 = ";",word, emptyWord;
    char character,space=' ';
    int counter = 0;
    string paragraph = "A->id+E; E ->E+E | E*E| id ; ";
    cout<<"Enter String"<<endl;
    //getline(cin,paragraph);
    strlength = paragraph.length();
    cout<<"String = "<<paragraph<<endl;
    cout<<"String Length = "<<strlength<<endl;

    while(counter<strlength)
    {
        while((paragraph[counter]!='-' && paragraph[counter+1]!='>') && paragraph[counter]!=';' && paragraph[counter]!='|' && paragraph[counter]!=' ')
        {
            character = paragraph[counter];
            word = word + character;
            counter++;
        }
        if(paragraph[counter]=='-' && paragraph[counter+1]=='>'){counter = counter + 2;}
        while(paragraph[counter]==';' || paragraph[counter]=='|' || paragraph[counter]==' '){counter++;}
        if(word!=emptyWord)
        {
            cout<<endl<<"Word = "<<word<<endl;
            Insertion(Head,Tail,word);
            word = emptyWord;
        }
    }

    display(Head);
    displayReverse(Tail);

    cout<<endl<<"/////////////////////////////////////////////////"<<endl;

    return 0;
}
*/
