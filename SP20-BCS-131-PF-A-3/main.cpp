#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addUserDetailsToCSV(const string& filename) {
    ofstream file;
    file.open(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    string name, fatherName, rollNo, dob, email;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Father Name: ";
    getline(cin, fatherName);
    cout << "Enter Roll No: ";
    getline(cin, rollNo);
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(cin, dob);
    cout << "Enter Email: ";
    getline(cin, email);

    file << name << "," << fatherName << "," << rollNo << "," << dob << "," << email << "\n";
    file.close();
    cout << "User details added successfully to " << filename << "\n";
}

void displayCSVData(const string& filename) {
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    string line;
    cout << "Data in " << filename << ":\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void clearCSVData(const string& filename) {
    ofstream file;
    file.open(filename, ios::trunc);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }
    file.close();
    cout << "All data cleared from " << filename << "\n";
}

int main() {
    const string filename = "data.csv";
    int choice;

    do {
        cout << "\n--- CSV File Operations ---\n";
        cout << "1. Add User Details\n";
        cout << "2. Display CSV Data\n";
        cout << "3. Clear All Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addUserDetailsToCSV(filename);
                break;
            case 2:
                displayCSVData(filename);
                break;
            case 3:
                clearCSVData(filename);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
