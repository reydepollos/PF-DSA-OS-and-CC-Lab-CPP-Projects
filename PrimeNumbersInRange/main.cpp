#include <iostream>

using namespace std;

int main()
{
    cout<<"///////// PRINTING PRIME NUMBERS IN RANGE /////////"<<endl;
    int lowerRange, upperRange,flag=0;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"Enter the Lower Range = ";
        cin>>lowerRange;
        while(lowerRange<2)
        {
            cout<<"Again Enter the Lower Range ( lowerRange >=2 ) = ";
            cin>>lowerRange;
        }
        cout<<"Enter the Upper Range = ";
        cin>>upperRange;
        while(upperRange<=lowerRange)
        {
            cout<<"Again Enter the Upper Range ( upperRange >"<<lowerRange<<" ) = ";
            cin>>upperRange;
        }
        cout<<endl<<endl<<"Prime Number from ("<<lowerRange<<" - "<<upperRange<<")"<<endl;
        for(int i=lowerRange;i<=upperRange;i++)
        {
            flag=0;
            for(int j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<i<<"  ";
            }
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
