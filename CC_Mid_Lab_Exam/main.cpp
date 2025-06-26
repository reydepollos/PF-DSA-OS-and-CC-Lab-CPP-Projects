/*
For your midterm exam, you are required to develop a C++ program that reads input from a file containing C++ code
and removes all comments using a transition table-based approach to lexical analysis. Once all comments are removed,
the program should write the remaining code to another C++ file.
*/

#include <iostream>
#include <fstream>

using namespace std;

enum State {
    CODE,            // Normal code
    SINGLE_LINE_COMMENT,  // Inside a single-line comment
    MULTI_LINE_COMMENT,   // Inside a multi-line comment
    MULTI_LINE_ASTERISK   // Possible end of multi-line comment
};

int main() {
    const char* inputFilePath = "CodeWithComments.txt";  // Input file with comments
    const char* outputFilePath = "CodeWithoutComments.cpp";  // Output file without comments

    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    char currentChar;
    char nextChar;
    State state = CODE;  // Start in CODE state

    // Read the file character by character
    while (inputFile.get(currentChar)) {
        switch (state) {
            case CODE:
                if (currentChar == '/') {
                    if (inputFile.peek() == '/') {
                        state = SINGLE_LINE_COMMENT;
                        inputFile.get();  // Consume the second '/'
                    } else if (inputFile.peek() == '*') {
                        state = MULTI_LINE_COMMENT;
                        inputFile.get();  // Consume the '*'
                    } else {
                        outputFile.put(currentChar);  // Normal character, write to output
                    }
                } else {
                    outputFile.put(currentChar);  // Normal character, write to output
                }
                break;

            case SINGLE_LINE_COMMENT:
                // Ignore characters until we reach the end of the line
                if (currentChar == '\n') {
                    outputFile.put(currentChar);  // Write the new line character
                    state = CODE;  // Back to normal code
                }
                break;

            case MULTI_LINE_COMMENT:
                if (currentChar == '*') {
                    state = MULTI_LINE_ASTERISK;  // Possible end of multi-line comment
                }
                break;

            case MULTI_LINE_ASTERISK:
                if (currentChar == '/') {
                    state = CODE;  // End of multi-line comment
                } else if (currentChar == '*') {
                    state = MULTI_LINE_ASTERISK;  // Stay in MULTI_LINE_ASTERISK
                } else {
                    state = MULTI_LINE_COMMENT;  // Still inside the comment
                }
                break;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Comments removed successfully. Output written to " << outputFilePath << endl;

    return 0;
}
