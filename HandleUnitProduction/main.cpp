#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<string> Rule;
typedef map<string, vector<Rule>> Grammar;

Grammar grammar;

// Function to print the grammar
void printGrammar(const Grammar& g) {
    for (const auto& [nonTerminal, rules] : g) {
        cout << nonTerminal << " -> ";
        for (size_t i = 0; i < rules.size(); ++i) {
            for (const string& symbol : rules[i]) {
                cout << symbol;
            }
            if (i < rules.size() - 1) cout << " | ";
        }
        cout << endl;
    }
}

// Function to eliminate epsilon productions
void eliminateEpsilon(Grammar& g) {
    set<string> nullable;

    // Find nullable non-terminals
    bool changed = true;
    while (changed) {
        changed = false;
        for (const auto& [nonTerminal, rules] : g) {
            for (const auto& rule : rules) {
                if (rule.empty() || all_of(rule.begin(), rule.end(), [&](const string& s) { return nullable.count(s); })) {
                    if (nullable.insert(nonTerminal).second) {
                        changed = true;
                    }
                }
            }
        }
    }

    // Replace nullable non-terminals
    Grammar newGrammar;
    for (const auto& [nonTerminal, rules] : g) {
        vector<Rule> newRules;
        for (const auto& rule : rules) {
            int n = rule.size();
            vector<int> positions;
            for (int i = 0; i < n; ++i) {
                if (nullable.count(rule[i])) {
                    positions.push_back(i);
                }
            }
            int combinations = 1 << positions.size();
            for (int mask = 0; mask < combinations; ++mask) {
                Rule newRule;
                for (int i = 0; i < n; ++i) {
                    if (find(positions.begin(), positions.end(), i) == positions.end() || (mask & (1 << (find(positions.begin(), positions.end(), i) - positions.begin())))) {
                        newRule.push_back(rule[i]);
                    }
                }
                if (!newRule.empty() || nonTerminal == "S") { // Ensure the start symbol remains
                    newRules.push_back(newRule);
                }
            }
        }
        newGrammar[nonTerminal] = newRules;
    }
    g = newGrammar;
}

// Function to eliminate unit productions
void eliminateUnitProductions(Grammar& g) {
    for (const auto& [nonTerminal, rules] : g) {
        vector<Rule> newRules;
        for (const auto& rule : rules) {
            if (rule.size() == 1 && g.count(rule[0])) { // If it's a unit production
                newRules.insert(newRules.end(), g[rule[0]].begin(), g[rule[0]].end());
            } else {
                newRules.push_back(rule);
            }
        }
        g[nonTerminal] = newRules;
    }
}

// Function to eliminate useless symbols
void eliminateUselessSymbols(Grammar& g) {
    set<string> generating;
    bool changed = true;

    while (changed) {
        changed = false;
        for (const auto& [nonTerminal, rules] : g) {
            if (generating.count(nonTerminal)) continue;
            for (const auto& rule : rules) {
                if (all_of(rule.begin(), rule.end(), [&](const string& s) { return !g.count(s) || generating.count(s); })) {
                    generating.insert(nonTerminal);
                    changed = true;
                    break;
                }
            }
        }
    }

    // Remove non-generating non-terminals
    for (auto it = g.begin(); it != g.end();) {
        if (!generating.count(it->first)) {
            it = g.erase(it);
        } else {
            ++it;
        }
    }

    // Remove non-reachable symbols
    set<string> reachable = { "S" };
    changed = true;

    while (changed) {
        changed = false;
        for (const auto& nonTerminal : reachable) {
            for (const auto& rule : g[nonTerminal]) {
                for (const string& symbol : rule) {
                    if (g.count(symbol) && reachable.insert(symbol).second) {
                        changed = true;
                    }
                }
            }
        }
    }

    for (auto it = g.begin(); it != g.end();) {
        if (!reachable.count(it->first)) {
            it = g.erase(it);
        } else {
            ++it;
        }
    }
}

void convertToBinary(Grammar& g) {
    int count = 1;

    for (auto& [nonTerminal, rules] : g) {
        vector<Rule> newRules;
        for (const auto& rule : rules) {
            if (rule.size() <= 2) {
                newRules.push_back(rule);
            } else {
                string prev = rule[0];
                for (size_t i = 1; i < rule.size(); ++i) {
                    string newNonTerminal = "X" + to_string(count++);
                    if (i == rule.size() - 1) {
                        newRules.push_back({ prev, rule[i] });
                    } else {
                        newRules.push_back({ prev, newNonTerminal });
                        prev = newNonTerminal;
                    }
                }
            }
        }
        rules = newRules;
    }
}

int main() {
    // Example Grammar
    grammar = {
        {"S", {{"A","d", "B","e","S"}, {"S","C","B", "A"},{"B","A","c"}}},
        {"A", {{"a"},{"Bg"}, {}}},
        {"B", {{"b"}}},
        {"C", {{"c"}}}
    };

    cout << "Original Grammar:\n";
    printGrammar(grammar);

    eliminateEpsilon(grammar);
    cout << "\nAfter Eliminating Epsilon Productions:\n";
    printGrammar(grammar);

    eliminateUnitProductions(grammar);
    cout << "\nAfter Eliminating Unit Productions:\n";
    printGrammar(grammar);

    eliminateUselessSymbols(grammar);
    cout << "\nAfter Eliminating Useless Symbols:\n";
    printGrammar(grammar);

    convertToBinary(grammar);
    cout << "\nFinal CNF Grammar:\n";
    printGrammar(grammar);

    return 0;
}
