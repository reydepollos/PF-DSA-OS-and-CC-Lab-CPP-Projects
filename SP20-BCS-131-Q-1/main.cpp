#include <iostream>

using namespace std;

int main()
{
    int rows;
    cout<<"Enter the Number of Rows = ";
    cin>>rows;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<j+i<<" ";
        }
        cout<<endl;
    }


}
