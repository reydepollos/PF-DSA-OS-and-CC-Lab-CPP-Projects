#include <iostream>

using namespace std;

int main()
{
    int number = 0,result=0,temp;
    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        result = 0;
        cout<<"Enter the Number = ";
        cin>>number;

        temp = number;
        while(temp>0)
        {
            result = (result*10) + (temp%10);
            temp = temp/10;
        }
        cout<<"Reversed Number of "<<number<<" = "<<result<<endl;

        if(number==result)
        {
            cout<<endl<<"Number is Palindrome"<<endl;
        }


        cout<<endl<<endl<<"Enter (y/Y) for Continue and any other key to exit = ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
        }

    }

    return 0;
}
