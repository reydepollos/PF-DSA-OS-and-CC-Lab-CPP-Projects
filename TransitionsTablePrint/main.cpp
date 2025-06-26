#include <iostream>
#include <fstream>
#include <iomanip>  // Include for formatting output

using namespace std;

// Define states for the transition table
enum State {
    CODE,                  // Normal code
    SINGLE_LINE_COMMENT,    // Inside a single-line comment
    MULTI_LINE_COMMENT,     // Inside a multi-line comment
    MULTI_LINE_ASTERISK     // Asterisk inside a multi-line comment, possible end
};

// Function to display the name of the state for readability
string stateToString(State state) {
    switch (state) {
        case CODE:
            return "CODE";
        case SINGLE_LINE_COMMENT:
            return "SINGLE_LINE_COMMENT";
        case MULTI_LINE_COMMENT:
            return "MULTI_LINE_COMMENT";
        case MULTI_LINE_ASTERISK:
            return "MULTI_LINE_ASTERISK";
        default:
            return "UNKNOWN_STATE";
    }
}

// Transition function to handle state changes
State transition(State currentState, char currentChar, char nextChar) {
    switch (currentState) {
        case CODE:
            if (currentChar == '/' && nextChar == '/') {
                return SINGLE_LINE_COMMENT;  // Transition to single-line comment
            }
            if (currentChar == '/' && nextChar == '*') {
                return MULTI_LINE_COMMENT;   // Transition to multi-line comment
            }
            return CODE;  // Remain in CODE

        case SINGLE_LINE_COMMENT:
            if (currentChar == '\n') {
                return CODE;  // End of single-line comment
            }
            return SINGLE_LINE_COMMENT;  // Stay in single-line comment

        case MULTI_LINE_COMMENT:
            if (currentChar == '*' && nextChar == '/') {
                return CODE;  // End of multi-line comment
            }
            if (currentChar == '*') {
                return MULTI_LINE_ASTERISK;  // Possible end of multi-line comment
            }
            return MULTI_LINE_COMMENT;  // Stay in multi-line comment

        case MULTI_LINE_ASTERISK:
            if (currentChar == '/') {
                return CODE;  // End of multi-line comment
            }
            if (currentChar == '*') {
                return MULTI_LINE_ASTERISK;  // Stay in multi-line asterisk state
            }
            return MULTI_LINE_COMMENT;  // Go back to multi-line comment
    }
    return CODE;  // Default to CODE state
}

int main() {
    const char* inputFilePath = "CodeWithComments.txt";    // Input file with comments
    const char* outputFilePath = "CodeWithoutComments.cpp"; // Output file without comments

    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error: Could not open input or output file!" << endl;
        return 1;
    }

    char currentChar;
    char nextChar;
    State state = CODE;  // Start in CODE state

    // Print table headers with column alignment
    cout << setw(20) << left << "Current State"
         << setw(20) << left << "Character Read"
         << setw(20) << left << "Next State" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Process each character in the file
    while (inputFile.get(currentChar)) {
        nextChar = inputFile.peek();  // Peek the next character to determine transitions

        // Use the transition table to decide the next state
        State nextState = transition(state, currentChar, nextChar);

        // Handle actions based on the state
        switch (state) {
            case CODE:
                if (nextState == CODE) {
                    outputFile.put(currentChar);  // Write code to output file
                }
                break;

            case SINGLE_LINE_COMMENT:
                if (nextState == CODE) {
                    outputFile.put(currentChar);  // Newline character, back to code
                }
                break;

            case MULTI_LINE_COMMENT:
            case MULTI_LINE_ASTERISK:
                // Ignore characters inside multi-line comments
                break;
        }

        // Print the current state, character, and next state in well-formatted columns
        cout << setw(25) << left << stateToString(state)
             << setw(20) << left << "'" + string(1, currentChar) + "'"
             << setw(25) << left << stateToString(nextState) << endl;

        // Move to the next state
        state = nextState;
    }

    inputFile.close();
    outputFile.close();

    cout << "\nComments removed successfully. Clean code written to " << outputFilePath << endl;

    return 0;
}
