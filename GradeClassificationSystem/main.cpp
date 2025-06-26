#include <iostream>

using namespace std;

int main()
{
    int marks=0,temp=90;
    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"Enter your Marks (0-100) = ";
        cin>>marks;
        while(marks<0 || marks>100)
        {
            cout<<"Again ... Enter your Marks (0-100) = ";
            cin>>marks;
        }
        if(marks<=50)
        {
            cout<<"Grade = F"<<endl;
        }
        else
        {
            temp=90;
            for(char alpha='A';alpha<='E';alpha++)
            {
                if(marks>=temp)
                {
                    cout<<"Grade = "<<alpha<<endl;
                    break;
                }
                else
                {
                    temp = temp - 10;
                }
            }
        }
        cout<<"Enter (y/Y) for continue or Any other key for Exit = ";
        cin>>ch;
    }
    return 0;
}


/*
Objective:
Write a program that classifies a student's grade based on their input score using conditional statements and looping structures.
Requirements:
•	Ask the user to input a score (0-100).
•	Classify the score as follows:
o	A (90-100)
o	B (80-89)
o	C (70-79)
o	D (60-69)
o	F (below 60)
•	The program should continue asking for scores and displaying the corresponding grade until the user chooses to stop.
Tasks:
1.	Write the program in your preferred language.
2.	Design a flowchart that represents the grade classification process.
3.	Write the algorithm for this problem.
*/
