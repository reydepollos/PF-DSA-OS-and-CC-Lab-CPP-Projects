#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string studentName;
    int studentRollNumber;
    int subjectMarks[5];
    float averageMarks;
    bool isPassed;
};

void calculateAverageAndPassStatus(Student& student) {
    int totalMarks = 0;
    for (int i = 0; i < 5; ++i) {
        totalMarks += student.subjectMarks[i];
    }
    student.averageMarks = totalMarks / 5.0f;
    student.isPassed = (student.averageMarks >= 50);
}

int main() {
    int numberOfStudents;

    do {
        cout << "Enter the number of students (between 2 and 20): ";
        cin >> numberOfStudents;
        if (numberOfStudents < 2 || numberOfStudents > 20) {
            cout << "Please enter a valid number of students between 2 and 20." << endl;
        }
    } while (numberOfStudents < 2 || numberOfStudents > 20);

    Student students[20];

    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "\nEnter data for student " << i + 1 << ":" << endl;
        cout << "Enter student's name: ";
        cin >> ws;
        getline(cin, students[i].studentName);

        cout << "Enter roll number: ";
        cin >> students[i].studentRollNumber;

        cout << "Enter marks in 5 subjects: ";
        for (int j = 0; j < 5; ++j) {
            cin >> students[i].subjectMarks[j];
        }

        calculateAverageAndPassStatus(students[i]);
    }

    string passedStudents[20];
    int passingStudentCount = 0;

    for (int i = 0; i < numberOfStudents; ++i) {
        if (students[i].isPassed) {
            passedStudents[passingStudentCount++] = students[i].studentName;
        }
    }

    sort(passedStudents, passedStudents + passingStudentCount);

    cout << "\nStudents who passed (sorted alphabetically):" << endl;
    for (int i = 0; i < passingStudentCount; ++i) {
        cout << passedStudents[i] << endl;
    }

    return 0;
}
