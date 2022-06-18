// Interpreter A <Project8.cpp>
// EE 312 Project 8 submission by
// <Ayan Basu>
// <EID: ab73287>
// Slip days used: <0>
// Fall 2021

#include "Project8.h"

bool isCommand(std::string token) {
    return (token == "//" || token == "text" || token == "output"
    || token == "var" || token == "set");
}

bool isNumber(std::string token) {
    for (int i = 0; token[i] != '\0'; i++) {
        if (token[i] < '0' || token[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isOperator(std::string token) {
    return (token == "+" || token == "-" || token == "*" || token == "/" || token == "%"
    || token == "&&" || token == "||" || token == "<" || token == ">" || token == "=="
    || token == "!=" || token == "<=" || token == ">=" || token == "!" || token == "~");
}

void print(std::vector<std::string> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int computeExp(std::map<std::string, int> &hashTable) {
    std::vector<std::string> expression;
    read_next_token();
    std::string next(next_token());
    while (next_token_type != END && !isCommand(next)) {
        if (!(isNumber(next) || isOperator(next))) {
            int val = hashTable[next];
            next = std::to_string(val);
        }
        expression.emplace_back(next);
        std::string check(peek_next_token());
        if (next_token_type == END || isCommand(check)) {
            break;
        }
        read_next_token();
        next = next_token();
    }
    ET currentExp(expression);
    // currentExp.printTree();
    return currentExp.compute();
}

void runText() {
    read_next_token();
    std::string text = next_token();
    std::cout << text;
}

void runOutput(std::map<std::string, int> &hashTable) {
    int val = computeExp(hashTable);
    std::cout << val;
}

void runVar(std::map<std::string, int> &hashTable) {
    read_next_token();
    std::string var(next_token());
    if (hashTable.count(var) == 1) {
        std::cout << "variable " << var << " incorrectly re-initialized" << std::endl;
    }
    int val = computeExp(hashTable);
    hashTable[var] = val;
}

void runSet(std::map<std::string, int> &hashTable) {
    read_next_token();
    std::string var(next_token());
    if (hashTable.count(var) == 0) {
        std::cout << "variable " << var << " not declared" << std::endl;
    }
    int val = computeExp(hashTable);
    hashTable[var] = val;
}

void run() {
    std::map<std::string, int> symbols; // defines symbol table
    read_next_token();
    while (next_token_type != END) {
        std::string command = next_token();
        if (command[0] == '/' && command[1] == '/') skip_line();
        else if (command == "text") runText();
        else if (command == "output") runOutput(symbols);
        else if (command == "var") runVar(symbols);
        else if (command == "set") runSet(symbols);
        read_next_token();
    }
}

