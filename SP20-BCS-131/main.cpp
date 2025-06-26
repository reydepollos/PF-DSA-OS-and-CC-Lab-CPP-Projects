#include <iostream>

using namespace std;

double input(double number);
double square(double number);
double printValue(double number);

int main()
{
    double number=0,squareValue=0;
    int option;
    char ch;
    do
    {
        cout<<"Given Options: \n(1) Take Input \n(2) Square of Value \n(3) Print Value\nEnter your Selected Option = ";
        cin>>option;
        switch(option)
        {
        case 1:
        {
            number = input(number);
            break;
        }
        case 2:
        {
            if(number==0)
            {
                number  = input(number);
            }
            squareValue = square(number);
            cout<<"Square Value of "<<number<<" = "<<squareValue<<endl;
            break;
        }
        case 3:
        {
            if(number==0)
            {
                number = input(number);
            }
            printValue(number);
            break;
        }
        default:
        {
            cout<<"Invalid Entry."<<endl;
        }
        }
        cout<<endl<<"Enter (y/Y) for Continue and any other key for Exit = ";
        cin>>ch;
        cout<<"========================================================="<<endl;
    }
    while(ch=='y' || ch=='Y');
    return 0;
}

double input(double number)
{
    cout<<"Enter the Number = ";
    cin>>number;
    return number;
}

double square(double number)
{
    number = number * number;
    return number;
}

double printValue(double number)
{
    cout<<"Number Value = "<<number<<endl;
}
