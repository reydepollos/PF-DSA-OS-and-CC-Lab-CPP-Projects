#include <iostream>

using namespace std;

int main()
{
    int rows,temp=0;
    cout<<"Enter Even Number of rows = ";
    cin>>rows;

    for(int i=1;i<=rows;i++)
    {
        if(i<=rows/2)
        {
            for(int j=1;j<=i*2;j++)
            {
                cout<<"*";
            }
        }
        else
        {
            for(int j=i;j<=i+temp;j++)
            {
                cout<<"*";
            }
            temp = temp +2;
        }
        cout<<endl;
    }

    return 0;
}
