//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <string>
//
//using namespace std;
//
//const int BUFFER_SIZE = 50;
//
//int main() {
//    const char* filePath = "BufferFile.txt";
//    ifstream file(filePath, ios::in | ios::binary);
//
//    if (!file.is_open()) {
//        cerr << "Error: Could not open the file!" << endl;
//        return 1;
//    }
//
//    char buffer[BUFFER_SIZE];
//    string lexeme = "";
//
//    while (!file.eof()) {
//        file.read(buffer, BUFFER_SIZE);
//        streamsize bytesRead = file.gcount();
//
//        cout << "\nRead " << bytesRead << " bytes." << endl;
//
//        for (streamsize i = 0; i < bytesRead; ++i) {
//            char currentChar = buffer[i];
//
//            if (isalnum(currentChar)) {
//                lexeme += currentChar;
//            }
//            else {
//
//                if (!lexeme.empty()) {
//                    cout << "\tLexeme: " << lexeme << endl;
//                    lexeme = "";
//                }
//            }
//        }
//    }
//
//    if (!lexeme.empty()) {
//        cout << "Lexeme: " << lexeme << endl;
//    }
//
//    file.close();
//    return 0;
//}


//////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>   // For isalnum() function

using namespace std;

const int INITIAL_BUFFER_SIZE = 40;  // Initial buffer size, but it will grow dynamically

int main() {
    const char* filePath = "BufferFile.txt";
    ifstream file(filePath, ios::in | ios::binary);  // Open file in binary mode

    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    vector<char> buffer(INITIAL_BUFFER_SIZE);  // Dynamic buffer to store chunks of data
    string lexeme;  // String for dynamic lexeme handling

    // Read the file in chunks
    while (!file.eof()) {
        file.read(buffer.data(), buffer.size());  // Read into the buffer
        streamsize bytesRead = file.gcount();  // Get number of bytes read

        cout << "Read " << bytesRead << " bytes." << endl;

        // Process the buffer to extract lexemes
        for (streamsize i = 0; i < bytesRead; ++i) {
            char currentChar = buffer[i];

            // If the current character is alphanumeric, add it to the lexeme
            if (isalnum(currentChar)) {
                lexeme += currentChar;  // Append character to the lexeme
            } else {
                // If a non-alphanumeric character is encountered, print the current lexeme
                if (!lexeme.empty()) {
                    cout << "Lexeme: " << lexeme << endl;
                    lexeme.clear();  // Clear lexeme for the next word
                }
            }
        }

        // Dynamically grow the buffer based on need (optional)
        if (bytesRead == buffer.size()) {
            buffer.resize(buffer.size() * 2);  // Double the buffer size if it's full
        }
    }

    // Print any remaining lexeme that wasn't followed by a delimiter
    if (!lexeme.empty()) {
        cout << "Lexeme: " << lexeme << endl;
    }

    file.close();
    return 0;
}





//////////////////////////////////////////////////

//#include <iostream>
//#include <fstream>
//#include <cctype>
//
//using namespace std;
//
//const int BUFFER_SIZE = 80;
//const int LEXEME_BUFFER_SIZE = 40;
//
//int main() {
//    const char* filePath = "BufferFile.txt";
//    ifstream file(filePath, ios::in | ios::binary);
//
//    if (!file.is_open()) {
//        cerr << "Error: Could not open the file!" << endl;
//        return 1;
//    }
//
//    char buffer[BUFFER_SIZE];
//    char lexeme[LEXEME_BUFFER_SIZE];
//    int lexemeIndex = 0;
//
//    while (!file.eof()) {
//        file.read(buffer, BUFFER_SIZE);
//        streamsize bytesRead = file.gcount();
//
//        cout << "\nRead " << bytesRead << " bytes." << endl;
//
//        for (streamsize i = 0; i < bytesRead; ++i) {
//            char currentChar = buffer[i];
//
//            if (isalnum(currentChar)) {
//                if (lexemeIndex < LEXEME_BUFFER_SIZE - 1) {
//                    lexeme[lexemeIndex++] = currentChar;
//                }
//            } else {
//                if (lexemeIndex > 0) {
//                    lexeme[lexemeIndex] = '\0';
//                    cout << "\tLexeme: " << lexeme << endl;
//                    lexemeIndex = 0;
//                }
//            }
//        }
//    }
//
//    // If there's a remaining lexeme when the file reading finishes, print it
//    if (lexemeIndex > 0) {
//        lexeme[lexemeIndex] = '\0';  // Null-terminate the lexeme
//        cout << "Lexeme: " << lexeme << endl;
//    }
//
//    file.close();
//    return 0;
//}



//////////////////////////////////////////////////

//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//const int BUFFER_SIZE = 40;
//
//int main() {
//    const char* filePath = "BufferFile.txt";
//    ifstream file(filePath, ios::in | ios::binary);
//
//    if (!file.is_open()) {
//        cerr << "Error: Could not open the file!" << endl;
//        return 1;
//    }
//    char buffer[BUFFER_SIZE];
//    while (!file.eof()) {
//        file.read(buffer, BUFFER_SIZE);
//        streamsize bytesRead = file.gcount();
//        cout << "Read " << bytesRead << " bytes." << endl;
//    }
//
//    file.close();
//    return 0;
//}


///////////////////////////////////////////////////////////////////////


//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <string>
//
//using namespace std;
//
//const int BUFFER_SIZE = 4;
//
//int main() {
//    char buffer[BUFFER_SIZE];
//    int lexemeCounter = 0;
//
//    ifstream file("BufferFile.txt", ios::in);
//    //ifstream file("code.txt",ios::in);
//
//    if (!file.is_open()) {
//        cerr << "Error opening file" << endl;
//        return 1;
//    }
//
//    string lexeme = "";
//
//    while (!file.eof()) {
//        file.read(buffer, BUFFER_SIZE);
//        streamsize bytesRead = file.gcount();
//
//        for (streamsize i = 0; i < bytesRead; ++i) {
//            char currentChar = buffer[i];
//
//            if (isalnum(currentChar)) {
//                lexeme += currentChar;
//            }
//            else {
//                if (!lexeme.empty())
//                {
//                    lexemeCounter++;
//                    cout << "Lexeme-"<<lexemeCounter<<" : " << lexeme << endl;
//                    lexeme = "";
//                }
//            }
//        }
//    }
//    if (!lexeme.empty()) {
//        cout << "Lexeme:"<< lexeme << endl;
//    }
//
//    file.close();
//    return 0;
//}
