#include <iostream>

using namespace std;

int arr[] = {9,4,1,2,7,11,8,3,6};
int arrSize = sizeof(arr)/sizeof(arr[0]);

void display()
{
    cout<<"Array = { ";
    for(int i=0; i<arrSize-1; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<arr[arrSize-1]<<"} "<<endl;
}

int bubbleSorting()
{
    int temp = 0;
    cout<<endl;
    display();
    for(int i=0; i<arrSize-1; i++)
    {
        for(int j=0; j<arrSize-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        cout<<"Pass "<<i+1<<" ";
        display();
    }
    cout<<"Bubble Sorted ";
    display();
}

int selectionSort()
{
    int minValueIndex=0, temp=0;
    cout<<endl;
    display();
    for(int i=0; i<arrSize-1; i++)
    {
        minValueIndex = i;
        for(int j=i+1; j<arrSize; j++)
        {
            if(arr[j]<arr[minValueIndex])
            {
                minValueIndex = j;
            }
        }
        if(minValueIndex!=i)
        {
            temp = arr[i];
            arr[i] = arr[minValueIndex];
            arr[minValueIndex]=temp;
        }
        cout<<"Pass "<<i+1<<" ";
        display();
    }
    cout<<"Selection Sorted ";
    display();

}

int selectionSorting()
{
    int temp=0;
    cout<<endl;
    display();
    for(int i=0; i<arrSize-1; i++)
    {
        for(int j=i+1; j<arrSize; j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        cout<<"Pass "<<i<<" ";
        display();
    }
    cout<<"Selection Sorted ";
    display();
}


int main()
{
    cout << "Array Size = "<<arrSize << endl;
    bubbleSorting();
    //selectionSorting();
    //selectionSort();
    return 0;
}
