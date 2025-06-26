#include <iostream>

using namespace std;

int main()
{
    int number,tableUpto;
    cout<<"Enter the Number = ";
    cin>>number;
    for(int i=1;i<=10;i++)
    {
        cout<<number<<" * "<<i<<" = "<<number*i<<endl;
    }
    return 0;
}
