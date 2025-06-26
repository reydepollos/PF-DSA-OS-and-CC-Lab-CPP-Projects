#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <fstream>

using namespace std;

const int MAX_WORDS = 1000;

int call(string words[], int wordCount);
void display(string Name, int score);
void print_game_name();
void saveHistory(const string &Name, int score);
void readHistory();
void loadDictionary(string words[], int& count, const string& filename);
void appendWordToDictionary(const string& word, const string& filename);
void displayWords(const string words[], int count);
int loadWordsFromDictionary(string words[], const string& filename);
string getRandomWord(const string words[], int count);

int main() {
    system("Color 0B");
    string filename = "dictionary.txt";
    string words[MAX_WORDS];
    int wordCount = loadWordsFromDictionary(words, filename);

    if (wordCount == 0) {
        cerr << "No words loaded. Exiting program.\n";
        return 1;
    }

    cout << "Words loaded successfully. Total words: " << wordCount << "\n";
    cout << "Random word from dictionary: " << getRandomWord(words, wordCount) << "\n";

    cout <<wordCount<<" Words in the dictionary:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << endl;
    }

    char choice;
    do {
        system("cls");
        print_game_name();

        cout << "1. Play the Word Guessing Game\n";
        cout << "2. View Dictionary Words\n";
        cout << "3. Add a New Word to the Dictionary\n";
        cout << "4. View Game History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string name;
                cout << "\nEnter your name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name);

                int score = 0;
                char continueGame;
                do {
                    system("cls");
                    display(name, score);
                    score += call(words, wordCount);
                    cout << "\nPress [n] to terminate the game or any other key to continue: ";
                    cin >> continueGame;
                } while (continueGame != 'n');

                cout << name << ", your final score is: " << score << endl;

                saveHistory(name, score);
                break;
            }

            case '2': {
                cout << "\nWords in the dictionary:\n";
                displayWords(words, wordCount);
                system("pause");
                break;
            }

            case '3': {
                if (wordCount < MAX_WORDS) {
                    string newWord;
                    cout << "\nEnter the new word to add: ";
                    cin >> newWord;

                    appendWordToDictionary(newWord, filename);
                    words[wordCount++] = newWord;

                    cout << "New word added successfully!\n";
                } else {
                    cout << "Error: Dictionary is full. Cannot add more words.\n";
                }
                system("pause");
                break;
            }

            case '4': {
                cout << "\nGame History:\n";
                readHistory();
                system("pause");
                break;
            }

            case '5': {
                cout << "Exiting the program. Goodbye!\n";
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                system("pause");
                break;
            }
        }
    } while (choice != '5');

    return 0;
}

int call(string words[], int wordCount) {
    system("Color B0");
    string output;

    char arr[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char c;
            int r = rand() % 26;
            c = 'a' + r;
            arr[i][j] = c;
        }
    }

    int index = rand() % wordCount;
    output = words[index];

    if (output.length() % 2 == 0) {
        int row = rand() % 10;
        int col = rand() % 3;
        for (int i = 0; output[i] != '\0'; i++, col++) {
            arr[row][col] = output[i];
        }
    } else {
        int row = rand() % 3;
        int col = rand() % 10;
        for (int i = 0; output[i] != '\0'; i++, row++) {
            arr[row][col] = output[i];
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cout << " " << arr[i][j];
            Sleep(1);
        }
        cout << endl;
    }

    string guess;
    cout << "\n1. Guess the word\n2. See hint and then guess\n";

label1:
    cout << "Enter your choice: ";
    char hint;
    cin >> hint;
    cout << endl;

    if (hint == '2') {
        cout << "Hint: The word length is " << output.size() << endl;
    } else if (hint != '1') {
        cout << "Invalid input. Try again.\n";
        goto label1;
    }

    cout << "Enter your guess: ";
    cin >> guess;
    cout << endl;

    if (guess == output) {
        cout << "Congratulations! You guessed the correct word.\n";
        return 1;
    } else {
        cout << "Sorry! Incorrect guess. Try again next time.\n"<<"The Word is *** "<<output<<" ***"<<endl;
        return 0;
    }
}

void display(string Name, int score)
{
    print_game_name();
    cout << Name << ", your current score is: " << score << endl;
    cout << "Try to guess the word hidden in the puzzle.\n";
    cout << "You can use a hint if needed.\n\n";
}

void print_game_name()
{
    cout << "==================================================================================  \n";
    cout << "||                                                                              ||  \n";
    cout << "||   WW    WW   OOOOO   RRRRRR   DDDDD    BBBBB   LL      IIII  TTTTTT ZZZZZZ   ||  \n";
    cout << "||   WW    WW  OO   OO  RR   RR  DD  DD   BB  BB  LL       II     TT      ZZ    ||  \n";
    cout << "||   WW WW WW  OO   OO  RRRRRR   DD  DD   BBBBB   LL       II     TT     ZZ     ||  \n";
    cout << "||   WWW WWWW  OO   OO  RR  RR   DD  DD   BB  BB  LL       II     TT    ZZ      ||  \n";
    cout << "||   WW   WWW   OOOOO   RR   RR  DDDDD    BBBBB   LLLLLL  IIII    TT   ZZZZZZ   ||  \n";
    cout << "||                                                                              ||  \n";
    cout << "==================================================================================  \n\n";
}



void saveHistory(const string &Name, int score)
{
    ofstream file("history.csv", ios::app);
    if (file.is_open()) {
        file << Name << "," << score << endl;
        file.close();
    } else {
        cerr << "Error: Unable to save history.\n";
    }
}

void readHistory()
{
    ifstream file("history.csv");
    if (file.is_open()) {
        string line;
        cout << "Name\t| Score\n";
        cout << "-----------------\n";
        while (getline(file, line)) {
            size_t commaPos = line.find(',');
            string name = line.substr(0, commaPos);
            string score = line.substr(commaPos + 1);
            cout << name << "\t| " << score << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to read history.\n";
    }
}

void loadDictionary(string words[], int& count, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << ". Make sure the file exists.\n";
        return;
    }
    string word;
    count = 0;
    while (getline(file, word)) {
        if (!word.empty() && count < MAX_WORDS) {
            words[count++] = word;
        }
    }
    file.close();
}

void appendWordToDictionary(const string& word, const string& filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << " for appending.\n";
        return;
    }
    file << word << endl;
    file.close();
}

void displayWords(const string words[], int count) {
    cout<<endl<<"Dictionary Words = [ ";
    for (int i = 0; i < count-1; i++) {
            if(i%7==0)
            {
                cout<<endl;
            }
        cout << words[i] << " , ";
    }
    cout<<words[count-1]<<"\n]"<<endl<<endl;
}

int loadWordsFromDictionary(string words[], const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << ". Make sure the file exists.\n";
        return 0;
    }
    int count = 0;
    string word;
    while (getline(file, word)) {
        if (!word.empty() && count < MAX_WORDS) {
            words[count++] = word;
        }
    }
    file.close();
    return count;
}

string getRandomWord(const string words[], int count) {
    if (count == 0) {
        return "";
    }
    int randomIndex = rand() % count;
    return words[randomIndex];
}
