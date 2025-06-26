//#include <iostream>
//#include <fstream>
//#include <cctype>
//
//using namespace std;
//
//const int BUFFER_SIZE = 40;
//const int LEXEME_BUFFER_SIZE = 40;
//
//void loadBuffer(ifstream &file, char* buffer, int &bytesRead) {
//    file.read(buffer, BUFFER_SIZE);
//    bytesRead = file.gcount();
//}
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
//    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
//    int bytesRead1 = 0, bytesRead2 = 0;
//
//    char lexeme[LEXEME_BUFFER_SIZE];
//    int lexemeIndex = 0;
//
//    bool useBuffer1 = true;
//    int i = 0;
//
//    loadBuffer(file, buffer1, bytesRead1);
//
//    while (bytesRead1 > 0 || bytesRead2 > 0) {
//        char* currentBuffer = useBuffer1 ? buffer1 : buffer2;
//        int currentBytesRead = useBuffer1 ? bytesRead1 : bytesRead2;
//
//        for (; i < currentBytesRead; ++i) {
//            char currentChar = currentBuffer[i];
//
//            if (isalnum(currentChar)) {
//                if (lexemeIndex < LEXEME_BUFFER_SIZE - 1) {
//                    lexeme[lexemeIndex++] = currentChar;
//                }
//            } else {
//                if (lexemeIndex > 0) {
//                    lexeme[lexemeIndex] = '\0';
//                    cout << "Lexeme: " << lexeme << endl;
//                    lexemeIndex = 0;
//                }
//            }
//        }
//
//        useBuffer1 = !useBuffer1;
//        i = 0;
//
//        if (useBuffer1) {
//            loadBuffer(file, buffer1, bytesRead1);
//        } else {
//            loadBuffer(file, buffer2, bytesRead2);
//        }
//    }
//
//    if (lexemeIndex > 0) {
//        lexeme[lexemeIndex] = '\0';
//        cout << "Lexeme: " << lexeme << endl;
//    }
//
//    file.close();
//    return 0;
//}


///////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

const int BUFFER_SIZE = 80;
const int LEXEME_BUFFER_SIZE = 40;

int main() {
    const char* filePath = "BufferFile.txt";
    ifstream file(filePath, ios::in | ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    char buffer[BUFFER_SIZE];
    char lexeme[LEXEME_BUFFER_SIZE];
    int lexemeIndex = 0;

    while (!file.eof()) {
        file.read(buffer, BUFFER_SIZE);
        streamsize bytesRead = file.gcount();

        cout << "\nRead " << bytesRead << " bytes." << endl;

        for (streamsize i = 0; i < bytesRead; ++i) {
            char currentChar = buffer[i];

            if (isalnum(currentChar)) {
                if (lexemeIndex < LEXEME_BUFFER_SIZE - 1) {
                    lexeme[lexemeIndex++] = currentChar;
                }
            } else {
                if (lexemeIndex > 0) {
                    lexeme[lexemeIndex] = '\0';
                    cout << "\tLexeme: " << lexeme << endl;
                    lexemeIndex = 0;
                }
            }
        }
    }

    // If there's a remaining lexeme when the file reading finishes, print it
    if (lexemeIndex > 0) {
        lexeme[lexemeIndex] = '\0';  // Null-terminate the lexeme
        cout << "Lexeme: " << lexeme << endl;
    }

    file.close();
    return 0;
}
