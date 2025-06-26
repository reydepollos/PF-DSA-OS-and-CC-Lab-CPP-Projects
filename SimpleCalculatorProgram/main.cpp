#include <iostream>

using namespace std;

int main()
{
    float firstNumber = 0,secondNumber=0,result=0;
    char ch = 'y',operation;
    while(ch=='y' || ch=='Y')
    {
        cout<<"Enter First Number = ";
        cin>>firstNumber;
        cout<<"Enter Second Number = ";
        cin>>secondNumber;
enterOperation:
        cout<<"Enter operation you want = ";
        cin>>operation;
        while(operation!='+' && operation!='*' && operation!='/' && operation!='-')
        {
            cout<<"Again Enter ( + , - , * , / ) ... ";
            goto enterOperation;
        }
        while(secondNumber==0 && operation=='/')
        {
            cout<<"Second Number can not be zero as denominator ... Enter another Number = ";
            cin>>secondNumber;
        }
        switch(operation)
        {
        case '+':
        {
            result = firstNumber + secondNumber;
            cout<<"Addition = "<<result<<endl;
            break;
        }
        case '-':
        {
            result = firstNumber - secondNumber;
            cout<<"Subtraction = "<<result<<endl;
            break;
        }
        case '*':
        {
            result = firstNumber * secondNumber;
            cout<<"Multiplication = "<<result<<endl;
            break;
        }
        case '/':
        {
            result = firstNumber / secondNumber;
            cout<<"Division = "<<result<<endl;
            break;
        }
        }
        cout<<"Enter (y/Y) for continue or Any other key for Exit = ";
        cin>>ch;
    }
}
