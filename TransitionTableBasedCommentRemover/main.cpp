#include <iostream>
#include <fstream>

using namespace std;

enum State {
    CODE,
    SINGLE_LINE_COMMENT,
    MULTI_LINE_COMMENT,
    MULTI_LINE_ASTERISK
};


State transition(State currentState, char currentChar, char nextChar) {
    switch (currentState) {
        case CODE:
            if (currentChar == '/' && nextChar == '/') {
                return SINGLE_LINE_COMMENT;
            }
            if (currentChar == '/' && nextChar == '*') {
                return MULTI_LINE_COMMENT;
            }
            return CODE;

        case SINGLE_LINE_COMMENT:
            if (currentChar == '\n') {
                return CODE;
            }
            return SINGLE_LINE_COMMENT;

        case MULTI_LINE_COMMENT:
            if (currentChar == '*' && nextChar == '/') {
                return CODE;
            }
            if (currentChar == '*') {
                return MULTI_LINE_ASTERISK;
            }
            return MULTI_LINE_COMMENT;

        case MULTI_LINE_ASTERISK:
            if (currentChar == '/') {
                return CODE;
            }
            if (currentChar == '*') {
                return MULTI_LINE_ASTERISK;
            }
            return MULTI_LINE_COMMENT;
    }
    return CODE;
}


void printFileContents(const char* filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filePath << endl;
        return;
    }
    cout << "\n\n====================================";
    cout << "\nContents of " << filePath << ":\n";
    cout << "====================================\n";

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << "====================================\n";
    file.close();
}

int main() {
    const char* inputFilePath = "CodeWithComments.txt";
    const char* outputFilePath = "CodeWithoutComments.cpp";

    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Could not open input or output file!" << endl;
        return 1;
    }

    char currentChar;
    char nextChar;
    State state = CODE;

    while (inputFile.get(currentChar)) {

        nextChar = inputFile.peek();


        State nextState = transition(state, currentChar, nextChar);


        switch (state) {
            case CODE:
                if (nextState == CODE) {
                    outputFile.put(currentChar);
                }
                break;

            case SINGLE_LINE_COMMENT:
                if (nextState == CODE) {
                    outputFile.put(currentChar);
                }
                break;

            case MULTI_LINE_COMMENT:
            case MULTI_LINE_ASTERISK:

                break;
        }


        state = nextState;
    }

    inputFile.close();
    outputFile.close();

    cout << "\nComments removed successfully. Clean code written to " << outputFilePath << endl;
    printFileContents(inputFilePath);
    printFileContents(outputFilePath);

    return 0;
}
