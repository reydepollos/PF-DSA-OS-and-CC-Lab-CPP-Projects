#include <iostream>

using namespace std;

int main()
{
    int rows = 0,temp=0, num=1,value=0;
    bool reverseState=false;

    cout << "Enter Rows = ";
    cin>>rows;

    temp = rows-1;
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j%2==0)
            {
                reverseState = true;
                value = temp + rows -num +2;
            } else {
                reverseState = false;
                value = temp +j +num+1;
            }

            if(j==1)
            {
                cout<<num<<"\t";
            }
            else{
                cout<<value<<"\t";
            }
        }
        cout<<endl;
        num++;
    }

    return 0;
}
