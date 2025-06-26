#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file;
    string name, profession;
    int age, numUsers, choice;

    file.open("data.txt", ios::out);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    do {
        cout << "Enter the number of users: ";
        cin >> numUsers;
        cin.ignore();

        for (int i = 0; i < numUsers; i++) {
            cout << "Enter details for user " << i + 1 << ":\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "Profession: ";
            getline(cin, profession);
            cout << "Age: ";
            cin >> age;
            cin.ignore();

            file << "NAME: " << name << endl;
            file << "Profession: " << profession << endl;
            file << "Age: " << age << endl << endl;
        }

        cout << "Enter 1 to continue or 0 to exit: ";
        cin >> choice;
        cin.ignore();

    } while (choice == 1);

    file.close();

    ifstream inputFile("data.txt");
    if (!inputFile) {
        cout << "Error opening file for reading." << endl;
        return 2;
    }

    string line;
    cout << "\nReading from file:\n";
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();

    return 0;
}




/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("data.txt");

    if (!outFile) {
        cerr << "Error: File could not be opened!" << endl;
        return 1;
    }

    string name, regNumber;

    cout << "Enter your Name: ";
    getline(cin, name);

    cout << "Enter your Registration Number: ";
    getline(cin, regNumber);

    outFile << "Name: " << name << endl;
    outFile << "Registration Number: " << regNumber << endl;

    outFile.close();
    cout << "Details saved to 'data.txt' successfully!" << endl;

    ifstream inFile("data.txt");
    if (!inFile) {
        cerr << "Error: Could not open the file for reading!" << endl;
        return 1;
    }

    string line;
    cout << "\nFile content of (data.txt):\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}
*/
