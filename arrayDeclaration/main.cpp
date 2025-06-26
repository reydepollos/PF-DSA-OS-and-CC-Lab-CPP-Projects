#include <iostream>

using namespace std;

int main()
{
    int arr[] = {20,12,13,9,10,15,18};
    int temp=0;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    cout<<"Size of Array = "<<arrSize<<endl<<endl;
    cout<<"Before Sorting = ";
    for(int i=0;i<arrSize;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Sorted Array = ";
    for(int i=0;i<arrSize-1;i++){
        for(int j=0;j<arrSize-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<arrSize;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
