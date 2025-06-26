#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void displayGrammar(const map<char, vector<string>>& grammar) {
    cout << "\nGrammar without null productions:\n";
    for (const auto& rule : grammar) {
        cout << rule.first << " -> ";
        for (size_t i = 0; i < rule.second.size(); ++i) {
            cout << rule.second[i];
            if (i < rule.second.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }
}

int main() {
    map<char, vector<string>> grammar;  // stores rules and their productions
    char rule;
    string production;
    char cont;

    cout << "Enter grammar rules (enter '@' for null productions):\n";
    do {
        cout << "\nEnter rule (e.g., A): ";
        cin >> rule;
        cout << "Enter productions for " << rule << " (separated by '|', e.g., ab|bc|@): ";
        string input;
        cin >> input;

        // Split productions by '|'
        size_t pos = 0;
        while ((pos = input.find('|')) != string::npos) {
            production = input.substr(0, pos);
            if (production != "@")  // Exclude null production
                grammar[rule].push_back(production);
            input.erase(0, pos + 1);
        }
        if (input != "@")  // Last production, exclude null if present
            grammar[rule].push_back(input);

        cout << "Do you want to add another rule? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    // Display grammar without null productions
    displayGrammar(grammar);

    return 0;
}
