#include <iostream>
#include<array>
using namespace std;

int main()
{
    int arr[] = {3,1,5,4,6,7,8,9,2,1,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<size<<endl;
    for(auto x: arr)
        cout<<x<<"\t";
    return 0;
}
