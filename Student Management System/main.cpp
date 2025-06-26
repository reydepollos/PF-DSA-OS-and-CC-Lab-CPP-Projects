#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

// Student structure
struct Student {
    int id;
    string name;
    int age;
    string course;
    float gpa;
    string email;
    string phone;
    Student* next;
};

// Global variables
Student* head = nullptr;
const string FILENAME = "students_linked_list.txt";

// Function prototypes
void loadStudents();
void saveStudents();
void displayMenu();
void addStudent();
void viewAllStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void displayStudent(Student* s);
void clearScreen();
void pauseScreen();
void freeMemory();

int main() {
    loadStudents();

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);

    saveStudents();
    freeMemory();
    return 0;
}

void loadStudents() {
    ifstream file(FILENAME);
    if(!file) {
        cout << "No existing data file found. Starting with empty database.\n";
        return;
    }

    Student* last = nullptr;
    while(true) {
        Student* newStudent = new Student;
        if(!(file >> newStudent->id)) {
            delete newStudent;
            break;
        }
        file.ignore();
        getline(file, newStudent->name);
        file >> newStudent->age;
        file.ignore();
        getline(file, newStudent->course);
        file >> newStudent->gpa;
        file.ignore();
        getline(file, newStudent->email);
        getline(file, newStudent->phone);
        newStudent->next = nullptr;

        if(head == nullptr) {
            head = newStudent;
        } else {
            last->next = newStudent;
        }
        last = newStudent;
    }

    file.close();
}

void saveStudents() {
    ofstream file(FILENAME);
    if(!file) {
        cout << "Error saving data to file!\n";
        return;
    }

    Student* current = head;
    while(current != nullptr) {
        file << current->id << "\n";
        file << current->name << "\n";
        file << current->age << "\n";
        file << current->course << "\n";
        file << current->gpa << "\n";
        file << current->email << "\n";
        file << current->phone << "\n";
        current = current->next;
    }

    file.close();
    cout << "Student records saved successfully.\n";
}

void displayMenu() {
    clearScreen();
    cout << "==================================\n";
    cout << "   STUDENT MANAGEMENT SYSTEM\n";
    cout << "       (Linked List Version)\n";
    cout << "==================================\n";
    cout << "1. Add New Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student Record\n";
    cout << "5. Delete Student Record\n";
    cout << "6. Exit\n";
    cout << "==================================\n";
}

void addStudent() {
    clearScreen();
    cout << "=== ADD NEW STUDENT ===\n";

    Student* newStudent = new Student;

    cout << "Enter Student ID: ";
    cin >> newStudent->id;
    cin.ignore();

    // Check if ID already exists
    Student* current = head;
    while(current != nullptr) {
        if(current->id == newStudent->id) {
            cout << "Student with this ID already exists!\n";
            delete newStudent;
            pauseScreen();
            return;
        }
        current = current->next;
    }

    cout << "Enter Student Name: ";
    getline(cin, newStudent->name);

    cout << "Enter Age: ";
    cin >> newStudent->age;
    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, newStudent->course);

    cout << "Enter GPA: ";
    cin >> newStudent->gpa;
    cin.ignore();

    cout << "Enter Email: ";
    getline(cin, newStudent->email);

    cout << "Enter Phone: ";
    getline(cin, newStudent->phone);

    newStudent->next = nullptr;

    // Add to linked list
    if(head == nullptr) {
        head = newStudent;
    } else {
        current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newStudent;
    }

    cout << "\nStudent added successfully!\n";
    pauseScreen();
}

void viewAllStudents() {
    clearScreen();
    cout << "=== ALL STUDENT RECORDS ===\n";

    if(head == nullptr) {
        cout << "No student records found.\n";
        pauseScreen();
        return;
    }

    cout << left << setw(8) << "ID" << setw(25) << "NAME" << setw(6) << "AGE"
         << setw(20) << "COURSE" << setw(6) << "GPA" << setw(25) << "EMAIL"
         << setw(15) << "PHONE" << endl;
    cout << string(100, '-') << endl;

    Student* current = head;
    while(current != nullptr) {
        cout << left << setw(8) << current->id
             << setw(25) << (current->name.length() > 20 ? current->name.substr(0, 20) + "..." : current->name)
             << setw(6) << current->age
             << setw(20) << (current->course.length() > 15 ? current->course.substr(0, 15) + "..." : current->course)
             << setw(6) << fixed << setprecision(2) << current->gpa
             << setw(25) << (current->email.length() > 20 ? current->email.substr(0, 20) + "..." : current->email)
             << setw(15) << current->phone << endl;
        current = current->next;
    }

    pauseScreen();
}

void searchStudent() {
    clearScreen();
    cout << "=== SEARCH STUDENT ===\n";

    if(head == nullptr) {
        cout << "No student records to search.\n";
        pauseScreen();
        return;
    }

    int choice;
    cout << "Search by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Course\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    bool found = false;

    switch(choice) {
        case 1: {
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;

            Student* current = head;
            while(current != nullptr) {
                if(current->id == id) {
                    displayStudent(current);
                    found = true;
                    break;
                }
                current = current->next;
            }
            break;
        }
        case 2: {
            string name;
            cout << "Enter Student Name to search: ";
            getline(cin, name);

            Student* current = head;
            while(current != nullptr) {
                if(current->name.find(name) != string::npos) {
                    displayStudent(current);
                    found = true;
                }
                current = current->next;
            }
            break;
        }
        case 3: {
            string course;
            cout << "Enter Course to search: ";
            getline(cin, course);

            Student* current = head;
            while(current != nullptr) {
                if(current->course.find(course) != string::npos) {
                    displayStudent(current);
                    found = true;
                }
                current = current->next;
            }
            break;
        }
        default:
            cout << "Invalid choice.\n";
    }

    if(!found) {
        cout << "No matching records found.\n";
    }

    pauseScreen();
}

void updateStudent() {
    clearScreen();
    cout << "=== UPDATE STUDENT RECORD ===\n";

    if(head == nullptr) {
        cout << "No student records to update.\n";
        pauseScreen();
        return;
    }

    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    Student* current = head;
    while(current != nullptr && current->id != id) {
        current = current->next;
    }

    if(current == nullptr) {
        cout << "Student with ID " << id << " not found.\n";
        pauseScreen();
        return;
    }

    displayStudent(current);

    cout << "\nEnter new details (leave blank to keep current value):\n";
    cin.ignore();

    string input;

    cout << "Name [" << current->name << "]: ";
    getline(cin, input);
    if(!input.empty()) current->name = input;

    cout << "Age [" << current->age << "]: ";
    getline(cin, input);
    if(!input.empty()) current->age = stoi(input);

    cout << "Course [" << current->course << "]: ";
    getline(cin, input);
    if(!input.empty()) current->course = input;

    cout << "GPA [" << current->gpa << "]: ";
    getline(cin, input);
    if(!input.empty()) current->gpa = stof(input);

    cout << "Email [" << current->email << "]: ";
    getline(cin, input);
    if(!input.empty()) current->email = input;

    cout << "Phone [" << current->phone << "]: ";
    getline(cin, input);
    if(!input.empty()) current->phone = input;

    cout << "\nStudent record updated successfully!\n";
    pauseScreen();
}

void deleteStudent() {
    clearScreen();
    cout << "=== DELETE STUDENT RECORD ===\n";

    if(head == nullptr) {
        cout << "No student records to delete.\n";
        pauseScreen();
        return;
    }

    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    Student* current = head;
    Student* prev = nullptr;

    while(current != nullptr && current->id != id) {
        prev = current;
        current = current->next;
    }

    if(current == nullptr) {
        cout << "Student with ID " << id << " not found.\n";
        pauseScreen();
        return;
    }

    displayStudent(current);

    char confirm;
    cout << "\nAre you sure you want to delete this record? (y/n): ";
    cin >> confirm;

    if(confirm == 'y' || confirm == 'Y') {
        if(prev == nullptr) {
            // Deleting head
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        cout << "Student record deleted successfully!\n";
    } else {
        cout << "Deletion cancelled.\n";
    }

    pauseScreen();
}

void displayStudent(Student* s) {
    cout << "\n=== STUDENT DETAILS ===\n";
    cout << left << setw(15) << "ID:" << s->id << endl;
    cout << setw(15) << "Name:" << s->name << endl;
    cout << setw(15) << "Age:" << s->age << endl;
    cout << setw(15) << "Course:" << s->course << endl;
    cout << setw(15) << "GPA:" << fixed << setprecision(2) << s->gpa << endl;
    cout << setw(15) << "Email:" << s->email << endl;
    cout << setw(15) << "Phone:" << s->phone << endl;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void freeMemory() {
    Student* current = head;
    while(current != nullptr) {
        Student* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
