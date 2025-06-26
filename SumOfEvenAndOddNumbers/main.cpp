#include <iostream>

using namespace std;

int main()
{
    int number = 0,even,odd;
    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        even = 0;
        odd = 0;
        cout<<"Enter the Number = ";
        cin>>number;
        while(number<1)
        {
            cout<<"Enter the Number Greater then 0 = ";
            cin>>number;
        }
        for(int i=0;i<=number;i++)
        {
            if(i%2==0)
            {
                even = even + i;
            }
            else
            {
                odd = odd + i;
            }
        }
        cout<<endl<<"Sum of Even numbers of First "<<number<<" numbers = "<<even;
        cout<<endl<<"Sum of Odd numbers of First "<<number<<" numbers = "<<odd<<endl;

        cout<<endl<<endl<<"Enter (y/Y) for Continue and any other key to exit = ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
        }

    }

    return 0;
}
