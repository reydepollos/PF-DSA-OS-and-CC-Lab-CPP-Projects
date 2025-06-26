#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* link;
};

void InsertionAtBeginning(Node*& head);
void InsertionOfElementsAtBeginning(Node*& head);
void DisplayListElements(Node*& head);
void InsertionAtLast(Node*& head);
void InsertionAtPosition(Node*& head);
void DeleteFirstElement(Node*& head);
void DeleteLastElement(Node*& head);
void InsertionOfElementsAtEnd(Node*& head);
void MultipleElementsInsertionAtLast(Node*& head);
void SearchbyValue(Node*& head);
void SearchbyIndex(Node*& head);
void DeleteElementByIndex(Node*& head);
void SortList(Node*& head);
void RemoveDuplicates(Node* head);

int main()
{
    Node* head = nullptr;
    InsertionAtBeginning(head);

    int operation,insertionChoice,deletionChoice,searchChoice;
ChoiceBack:
    cout<<"\n\nSelect the Operation: "<<endl;
    cout<<"[ (1) INSERTION | (2) DELETION | (3) SEACHING | (4) DISPLAY | (5) SORTING | (6) REMOVE DUPLICATES | (7) EXIT ]"<<endl;
    cout<<"Enter your Selected Operation = ";
    cin>>operation;
    switch(operation)
    {
    case 1:
    {
insertionBack:
        cout<<"INSERTION METHODS \n\t(1) Insertion at Start \n\t(2) Insertion at Last \n\t(3) Insertion at Selected Index Position";
        cout<<"\n\t(4) Multiple Elements Insertion at Start \n\t(5) Multiple Elements Insertion at End"<<endl;
        cout<<"Enter the Selected Insertion Method = ";
        cin>>insertionChoice;
        switch(insertionChoice)
        {
        case 1:
        {
            InsertionAtBeginning(head);
            goto ChoiceBack;
        }
        case 2:
        {
            InsertionAtLast(head);
            goto ChoiceBack;
        }
        case 3:
        {
            InsertionAtPosition(head);
            goto ChoiceBack;
        }
        case 4:
        {
            InsertionOfElementsAtBeginning(head);
            goto ChoiceBack;
        }
        case 5:
        {
            InsertionOfElementsAtEnd(head);
            goto ChoiceBack;
        }
        default:
        {
            cout<<"Invalid Selection - You must be Enter Number from (1-5) = "<<endl;
            goto insertionBack;
        }
        }

    }
    case 2:
    {
deletionBack:
        cout<<"DELETION METHODS \t(1) Delete First Element \t(2) Delete Last Element \t(3) Delete Element by Index "<<endl;
        cout<<"Enter the Selected Deletion Method = ";
        cin>>deletionChoice;
        switch(deletionChoice)
        {
        case 1:
        {
            DeleteFirstElement(head);
            goto ChoiceBack;
        }
        case 2:
        {
            DeleteLastElement(head);
            goto ChoiceBack;
        }
        case 3:
        {
            DeleteElementByIndex(head);
            goto ChoiceBack;
        }
        default:
        {
            cout<<"Invalid Selection - You must be Enter Number from (1-3) = "<<endl;
            goto deletionBack;
        }
        }
    }
    case 3:
    {
SearchBack:
        cout<<"SEARCH METHODS \t(1) Search by Value  \t(2) Search by Index"<<endl;
        cout<<"Enter the Selected Search Method = ";
        cin>>searchChoice;
        switch(searchChoice)
        {
        case 1:
        {
            SearchbyValue(head);
            goto ChoiceBack;
        }
        case 2:
        {
            SearchbyIndex(head);
            goto ChoiceBack;
        }
        default:
        {
            cout<<"Invalid Selection - You must be Enter Number from (1-2) = "<<endl;
            goto SearchBack;
        }
        }
    }
    case 4:
    {
        DisplayListElements(head);
        goto ChoiceBack;
    }
    case 5:
    {
        SortList(head);
        goto ChoiceBack;
    }
    case 6:
    {
        RemoveDuplicates(head);
        goto ChoiceBack;
    }
    case 7:
    {
        cout<<"\n\n================== PROGRAM TERMINATED =================="<<endl<<endl;
        return 0;
    }
    default:
    {
        cout<<"Invalid Input: Enter Your Choice from (1-5):";
        goto ChoiceBack;
    }
    }
    return 0;
}

void InsertionAtBeginning(Node*& head)
{
    int data;
    cout<<"Enter the value, You want to Insert at Start of List"<<" = ";
    cin>>data;
    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = head;
    head = newNode;
    DisplayListElements(head);
}

void InsertionAtLast(Node*& head)
{
    int data;
    cout<<"Enter the value, You want to Insert at Last of List"<<" = ";
    cin>>data;
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

    DisplayListElements(head);
}

void InsertionAtPosition(Node*& head)
{
    int data, index,counter=0;

    Node* temp = head;
    while(temp!=nullptr)
    {
        temp = temp->link;
        counter++;
    }
notExist:
    cout<<"On which Index you want to Enter the value ( index <= "<<counter<<") = ";
    cin>>index;

    while(index>counter)
    {
        cout<<"Index not Exists.";
        goto notExist;
    }
    if(index==1)
    {
        InsertionAtBeginning(head);
        return;
    }
    temp = head;
    for(int i=1; i<index-1; i++)
    {
        temp = temp -> link;
    }
    cout<<"Enter the Value you want to add in Linked List = ";
    cin>>data;

    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = temp->link;
    temp->link = newNode;

    DisplayListElements(head);
}

void InsertionOfElementsAtBeginning(Node*& head)
{
    int data,num;
    cout<<"How many Elements you want to Insert = ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Enter the value-"<<i+1<<" = ";
        cin>>data;
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link = head;
        head = newNode;
    }

    DisplayListElements(head);
}

void InsertionOfElementsAtEnd(Node*& head)
{
    Node* temp = head;
    int data,num;
    cout<<"How many Elements you want to Insert at End = ";
    cin>>num;

    while(temp->link!=nullptr)
    {
        temp = temp->link;
    }

    for(int i=1; i<=num; i++)
    {
        cout<<"Enter the value-"<<i<<" = ";
        cin>>data;
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link = temp->link;
        temp->link = newNode;
        temp = temp->link;
    }
    DisplayListElements(head);

}


void DeleteFirstElement(Node*& head)
{
    Node* temp = head;
    if(temp==nullptr)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    head = head->link;
    delete(temp);
    cout<<"\nAfter Deleting First Element of Linked List: ";
    DisplayListElements(head);
}

void DeleteElementByIndex(Node*& head)
{
    int index=0,counter=0;
    Node* temp=head;

    while(temp!=nullptr)
    {
        temp = temp->link;
        counter++;
    }
notExist:
    cout<<"On which Index you want to Delete the value ( index <= "<<counter<<") = ";
    cin>>index;

    while(index>counter)
    {
        cout<<"Index not Exists.";
        goto notExist;
    }
    temp = head;
    counter=1;

    if(index==1)
    {
        DeleteFirstElement(head);
        return;
    }

    while(temp!=nullptr)
    {
        if(counter==index-1)
        {
            break;
        }
        temp = temp->link;
        counter++;
    }
    Node* deletedIndex = temp->link;
    temp->link =temp->link->link;
    delete(deletedIndex);
    DisplayListElements(head);

}

void DeleteLastElement(Node*& head)
{
    if(head==nullptr)
    {
        cout<<"List is Empty.";
        return;
    }
    if(head->link==nullptr)
    {
        delete(head);
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->link->link!=nullptr)
    {
        temp = temp->link;
    }
    delete(temp->link);
    temp->link = nullptr;

    cout<<"Last Element is deleted from Linked List:"<<endl;
    DisplayListElements(head);
}

void SearchbyValue(Node*& head)
{
    int data,index=0,result=0;
    Node* temp=head;

    cout<<"Which Value you want to search = ";
    cin>>data;

    while(temp!=nullptr)
    {
        index++;
        if(temp->data==data)
        {
            result=1;
            break;
        }
        temp = temp->link;
    }
    if(result==1)
    {
        cout<<"Data Found at Index-"<<index<<endl;
    }
    else
    {
        cout<<"Data Not Found."<<endl;
    }
}

void SearchbyIndex(Node*& head)
{
    int data,index=0,counter=0;
    Node* temp=head;

    while(temp!=nullptr)
    {
        temp = temp->link;
        counter++;
    }
notExist:
    cout<<"On which Index you want to Search the value ( index <= "<<counter<<") = ";
    cin>>index;

    while(index>counter)
    {
        cout<<"Index not Exists.";
        goto notExist;
    }
    temp = head;
    counter=0;

    while(temp!=nullptr)
    {
        if(counter==index-1)
        {
            break;
        }
        temp = temp->link;
        counter++;
    }
    cout<<"Data Found at Index-"<<index<<" is "<<temp->data<<endl;
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

void SortList(Node*& head)
{
    if(head==nullptr)
    {
        cout<<"List is Empty so Sorting can not be Performed."<<endl;
        return;
    }
    if(head->link==nullptr)
    {
        cout<<"List has 1 Element only so Sorting can not be Performed."<<endl;
        return;
    }
    int data,temp;
    Node* EndPoint = nullptr;

    while(EndPoint!=head->link)
    {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = current->link;
        while(next!=EndPoint)
        {
            if(current->data > next->data)
            {
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            prev = current;
            current = next;
            next = next->link;
        }
        EndPoint = current;
    }
    cout<<"Sorted Linked List =";
    DisplayListElements(head);
}

void MultipleElementsInsertionAtLast(Node*& head)
{
    int data,num;
    cout<<"How many Elements you want to Insert"<<" = ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Enter the value, You want to Insert at Last of List"<<" = ";
        cin>>data;
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

    DisplayListElements(head);
}

void RemoveDuplicates(Node* head)
{
    Node* current = head;
    while (current != nullptr && current->link != nullptr)
    {
        Node* runner = current;
        while (runner->link != nullptr)
        {
            if (current->data == runner->link->data)
            {
                Node* duplicate = runner->link;
                runner->link = runner->link->link;
                delete duplicate;
            }
            else
            {
                runner = runner->link;
            }
        }
        current = current->link;
    }
    cout<<"List After Removing Duplicates:"<<endl;
    DisplayListElements(head);
}
