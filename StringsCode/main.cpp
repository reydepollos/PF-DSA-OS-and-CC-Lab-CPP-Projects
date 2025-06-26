#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function Prototypes
void displayMenu();
void stringLength(string& str);
void stringEmpty(string& str);
void appendString(string& str);
void pushBackString(string& str);
void insertString(string& str);
void eraseString(string& str);
void replaceString(string& str);
void substring(string& str);
void findSubstring(string& str);
void compareStrings(string& str);
void cString(string& str);
void atFunction(string& str);
void findFirstOf(string& str);
void findFirstNotOf(string& str);
void resizeString(string& str);
void clearString(string& str);
void swapStrings(string& str);

int main() {
    string str;
    int choice;
    do {
        // Display the menu
        displayMenu();
        cout << "Enter your choice (1-16): ";
        cin >> choice;

        // Take action based on user choice
        switch(choice) {
            case 1: stringLength(str); break;
            case 2: stringEmpty(str); break;
            case 3: appendString(str); break;
            case 4: pushBackString(str); break;
            case 5: insertString(str); break;
            case 6: eraseString(str); break;
            case 7: replaceString(str); break;
            case 8: substring(str); break;
            case 9: findSubstring(str); break;
            case 10: compareStrings(str); break;
            case 11: cString(str); break;
            case 12: atFunction(str); break;
            case 13: findFirstOf(str); break;
            case 14: findFirstNotOf(str); break;
            case 15: resizeString(str); break;
            case 16: clearString(str); break;
            default: cout << "Invalid choice, please try again." << endl;
        }

        cout << "Do you want to continue? (1 = Yes, 0 = No): ";
        cin >> choice;
    } while(choice != 0);

    return 0;
}

// Function to display menu
void displayMenu() {
    cout << "\n--- String Operations Menu ---\n";
    cout << "1. Get Length of String\n";
    cout << "2. Check if String is Empty\n";
    cout << "3. Append to String\n";
    cout << "4. Push Back Character to String\n";
    cout << "5. Insert into String\n";
    cout << "6. Erase part of String\n";
    cout << "7. Replace part of String\n";
    cout << "8. Extract Substring\n";
    cout << "9. Find Substring\n";
    cout << "10. Compare Two Strings\n";
    cout << "11. Convert to C-String\n";
    cout << "12. Access Character with 'at'\n";
    cout << "13. Find First Occurrence of Character\n";
    cout << "14. Find First Non-Matching Character\n";
    cout << "15. Resize String\n";
    cout << "16. Clear String\n";
    cout << "----------------------------\n";
}

// Function to get length of string
void stringLength(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    cout << "Length of the string: " << str.length() << endl;
}

// Function to check if string is empty
void stringEmpty(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    if (str.empty()) {
        cout << "The string is empty!" << endl;
    } else {
        cout << "The string is not empty." << endl;
    }
}

// Function to append text to string
void appendString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    string appendText;
    cout << "Enter text to append: ";
    getline(cin, appendText);
    str.append(appendText);
    cout << "Updated string: " << str << endl;
}

// Function to push a character to the end of the string
void pushBackString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    char ch;
    cout << "Enter a character to push back: ";
    cin >> ch;
    str.push_back(ch);
    cout << "Updated string: " << str << endl;
}

// Function to insert text into the string at a specified position
void insertString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    string insertText;
    int pos;
    cout << "Enter text to insert: ";
    getline(cin, insertText);
    cout << "Enter position to insert at: ";
    cin >> pos;
    str.insert(pos, insertText);
    cout << "Updated string: " << str << endl;
}

// Function to erase part of the string
void eraseString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    int pos, len;
    cout << "Enter position to start erasing: ";
    cin >> pos;
    cout << "Enter number of characters to erase: ";
    cin >> len;
    str.erase(pos, len);
    cout << "Updated string: " << str << endl;
}

// Function to replace part of the string
void replaceString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    string replaceText;
    int pos, len;
    cout << "Enter position to replace at: ";
    cin >> pos;
    cout << "Enter number of characters to replace: ";
    cin >> len;
    cout << "Enter new text to replace: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, replaceText);
    str.replace(pos, len, replaceText);
    cout << "Updated string: " << str << endl;
}

// Function to extract substring
void substring(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    int pos, len;
    cout << "Enter position to start substring: ";
    cin >> pos;
    cout << "Enter length of substring: ";
    cin >> len;
    cout << "Substring: " << str.substr(pos, len) << endl;
}

// Function to find a substring
void findSubstring(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    string sub;
    cout << "Enter substring to find: ";
    getline(cin, sub);
    size_t pos = str.find(sub);
    if (pos != string::npos) {
        cout << "Substring found at position: " << pos << endl;
    } else {
        cout << "Substring not found." << endl;
    }
}

// Function to compare two strings
void compareStrings(string& str) {
    cout << "Enter the first string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    string str2;
    cout << "Enter the second string: ";
    getline(cin, str2);
    int result = str.compare(str2);
    if (result == 0) {
        cout << "Strings are equal." << endl;
    } else if (result < 0) {
        cout << "First string is lexicographically smaller." << endl;
    } else {
        cout << "First string is lexicographically greater." << endl;
    }
}

// Function to convert string to C-string
void cString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    const char* cstr = str.c_str();
    cout << "C-string: " << cstr << endl;
}

// Function to access character with 'at'
void atFunction(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    int index;
    cout << "Enter index to access character: ";
    cin >> index;
    if (index >= 0 && index < str.length()) {
        cout << "Character at index " << index << " is: " << str.at(index) << endl;
    } else {
        cout << "Index out of range!" << endl;
    }
}

// Function to find first occurrence of a character
void findFirstOf(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    char ch;
    cout << "Enter character to find: ";
    cin >> ch;
    size_t pos = str.find_first_of(ch);
    if (pos != string::npos) {
        cout << "First occurrence of '" << ch << "' is at index: " << pos << endl;
    } else {
        cout << "Character not found." << endl;
    }
}

// Function to find first non-matching character
void findFirstNotOf(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    string exclude;
    cout << "Enter characters to exclude: ";
    cin >> exclude;
    size_t pos = str.find_first_not_of(exclude);
    if (pos != string::npos) {
        cout << "First character not in excluded set is at index: " << pos << endl;
    } else {
        cout << "No character found that doesn't match the exclusion set." << endl;
    }
}

// Function to resize string
void resizeString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    int newSize;
    cout << "Enter new size for the string: ";
    cin >> newSize;
    str.resize(newSize);
    cout << "Resized string: " << str << endl;
}

// Function to clear string
void clearString(string& str) {
    cout << "Enter a string: ";
    cin.ignore();  // To handle the newline character from previous input
    getline(cin, str);
    str.clear();
    cout << "String after clear: " << str << endl;
}
