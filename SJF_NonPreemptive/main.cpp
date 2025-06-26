#include <iostream>

using namespace std;

void sorting(int arr[],int size);
void displayArray(int arr[],int size);
int compare(int number, int arr[],bool visited[],int size);
void sortingfromIndextoIndex(int index,int arr[],int size);

int main()
{
    int numberOfProcess,indexValue,index;
    cout<<"Enter the number of Processes = ";
    cin>>numberOfProcess;

    int BurstTime[numberOfProcess],sortedBurstTime[numberOfProcess],arrivalTime[numberOfProcess],sortedArrivalTime[numberOfProcess];
    int waitTime[numberOfProcess],turnaroundTime[numberOfProcess];
    bool visited[numberOfProcess];
    for(int i=0;i<numberOfProcess;i++)
    {
        cout<<"\nEnter the Burst Time of Process-"<<i+1<<" = ";
        cin>>BurstTime[i];
        cout<<"Enter the Arrival Time of Process-"<<i+1<<" = ";
        cin>>arrivalTime[i];
        sortedArrivalTime[i]= arrivalTime[i];
        sortedBurstTime[i]=0;
        visited[i] = false;
    }
    cout<<endl<<"Before Sorting Arrival Time ";
    displayArray(arrivalTime,numberOfProcess);
    cout<<endl<<"Before Sorting Arrival Time ";
    displayArray(BurstTime,numberOfProcess);
    sorting(sortedArrivalTime,numberOfProcess);

    for(int i=0;i<numberOfProcess;i++)
    {
        indexValue = sortedArrivalTime[i];
        index = compare(indexValue,arrivalTime,visited,numberOfProcess);
        sortedBurstTime[i] = BurstTime[index];
    }
    cout<<"\n\nAfter Sorting Arrival Time ";
    displayArray(sortedArrivalTime,numberOfProcess);
    cout<<"After Sorting Burst Time ";
    displayArray(sortedBurstTime,numberOfProcess);

    waitTime[0]=0;
    for(int i=1;i<numberOfProcess;i++)
    {
        waitTime[i]=sortedBurstTime[i-1]+waitTime[i-1];
    }
    cout<<"Wait Time ";
    displayArray(waitTime,numberOfProcess);


    return 0;
}

void sorting(int arr[],int size)
{
    int temp=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void sortingfromIndextoIndex(int index,int arr[],int size)
{
    int temp=0;
    for(int i=index;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int compare(int number, int arr[],bool visited[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(number == arr[i] && visited[i]==false)
        {
            visited[i]=true;
            return i;
        }
    }
    return 1;
}

void displayArray(int arr[],int size)
{
    cout<<"Array = { ";
    for(int i=0;i<size-1;i++)
    {
        cout<<arr[i]<<" , ";
    }
    cout<<arr[size-1]<<" } "<<endl;
}
