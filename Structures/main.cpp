#include <iostream>

using namespace std;

/*
class Employee
{
public:
    int id;
    string name;
    float salary;
    Employee* link;
};
*/
struct Employee{
    int id;
    string name;
    float salary;
    Employee* link;
};

class EmployeeList
{
private:
    Employee* head;
    Employee* tail;
public:
    EmployeeList() : head(nullptr),tail(nullptr){};
    int id = 0;
    void Insertion(string name, float salary)
    {
        id++;
        Employee* emp = new Employee();
        emp->id = id;
        emp->name = name;
        emp->salary = salary;
        emp->link = nullptr;
        if(head==nullptr)
        {
            head = emp;
            tail = emp;
        }
        else
        {
            tail -> link = emp;
            tail = emp;
        }
    }

    void displayList()
    {
        Employee* temp = head;
        cout<<"ID\t\tNAME\t\tSALARY"<<endl;
        while(temp!=nullptr)
        {
            cout<<temp->id<<"\t\t"<<temp->name<<"\t\t"<<temp->salary<<endl;
            temp = temp->link;
        }
    }

};

int main()
{
    EmployeeList empList;
    empList.Insertion("SALMAN", 78231.3);
    empList.Insertion("ADNAN",78293.4);
    empList.Insertion("FARHAN", 68231.3);
    empList.Insertion("NOUMAN",98293.4);
    empList.displayList();
}







/*
struct Employee{
    int id;
    string name;
    float salary;
    Employee* link;
};

void Insertion(Employee*& head,Employee*& tail, int id, string name, float salary);
void displayList(Employee*& head);

int main()
{
    Employee* head = nullptr;
    Employee* tail = nullptr;
    Insertion(head,tail,1,"SALMAN",78932.89);
    Insertion(head,tail,2,"FARHAN",89932.89);
    Insertion(head,tail,3,"NOUMAN",90972.89);
    Insertion(head,tail,4,"SALEEM",98932.89);
    displayList(head);
    return 0;
}

void Insertion(Employee*& head,Employee*& tail, int id, string name, float salary)
{
    Employee* emp = new Employee();
    emp->id = id;
    emp->name = name;
    emp->salary = salary;
    emp->link = nullptr;
    if(head==nullptr)
    {
        head = emp;
        tail = emp;
    }
    else
    {
        tail -> link = emp;
        tail = emp;
    }
}

void displayList(Employee*& head)
{
    Employee* temp = head;
    cout<<"ID\t\tNAME\t\tSALARY"<<endl;
    while(temp!=nullptr)
    {
        cout<<temp->id<<"\t\t"<<temp->name<<"\t\t"<<temp->salary<<endl;
        temp = temp->link;
    }
}
*/
