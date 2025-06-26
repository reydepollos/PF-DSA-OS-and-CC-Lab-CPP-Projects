#include <iostream>

using namespace std;

int main()
{
    int number = 1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(number>9)
            {
                number = 1;
            }
            cout<<number<<" ";
            number = number +2;
        }
        cout<<endl;
    }
    return 0;
}
