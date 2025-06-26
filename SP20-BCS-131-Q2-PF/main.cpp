#include <iostream>

using namespace std;

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
            cout<<"Enter the Number = ";
            cin>>number;
            break;
        }
        case 2:
        {
            if(number==0)
            {
                cout<<"You have not Entered any Number ... Enter the Number = ";
                cin>>number;
            }
            squareValue = number * number;
            cout<<"Square Value of "<<number<<" = "<<squareValue<<endl;
            break;
        }
        case 3:
        {
            if(number==0)
            {
                cout<<"You have not Entered any Number ... Enter the Number = ";
                cin>>number;
            }
            cout<<"Number Value = "<<number<<endl;
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
