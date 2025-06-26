/*
Write a program that accepts an integer from the user and uses a for loop to calculate the factorial of that number.
Then, implement a switch statement to evaluate and print whether the factorial result is greater than, less than,
or equal to a predefined threshold value (e.g., 1000). In your solution, ensure to include proper use of variables,
constants, operators, and the correct flow control structures (like break and continue where applicable).
Additionally, explain the differences between local and global variables used in your program, and discuss the role
 of input/output functions in your solution.
*/

#include <iostream>

using namespace std;

// GLOBAL VARIABLE >> These variable can be used anywhere of this Program.
const int threshold_value = 500;

int main()
{
// LOCAL VARIABLES >> These Variables can be used only in function in which they declared.
    int number,result,choice=0;
    char call = 'y';
    while(call=='y' || call=='Y')
    {
    result = 1;
    cout<<endl<<"Enter the Number = ";
    cin>>number;
    while(number<1)
    {
        cout<<"Enter the Number greater then 0 = ";
        cin>>number;
    }

    for(int i=1;i<=number;i++)
    {
        result = result * i;
    }
call_again:
    cout<<"Enter (1) Display Result (2) Compare with Threshold Value (3) Exit = "<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            cout<<"Factorial of "<<number<<" is = "<<result<<endl;
            break;
        }
    case 2:
        {
            if(result<threshold_value)
            {
                cout<<"Result ("<<result <<") is less then Threshold Value ("<<threshold_value<<")."<<endl;
            }
            else if(result>threshold_value)
            {
                cout<<"Result ("<<result <<") is less then Threshold Value ("<<threshold_value<<")."<<endl;
            }
            else
            {
                cout<<"Result ("<<result <<") is Equal to Threshold Value ("<<threshold_value<<")."<<endl;
            }
            break;
        }
    case 3:
        {
            cout<<"============== PROGRAM TERMINATED =============="<<endl;
            return 0;
        }
    default:
        {
            cout<<"Invalid Selection ... Again ";
            goto call_again;
        }
    }
        cout<<"Enter (y/Y) for Continue the Program (Any other key to Exit) = ";
        cin>>call;
    }
    return 0;
}
