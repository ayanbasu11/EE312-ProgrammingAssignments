// Interpreter A <Project8.h>
// EE 312 Project 8 submission by
// <Ayan Basu>
// <EID: ab73287>
// Slip days used: <0>
// Fall 2021

#ifndef PROJECT8
#define PROJECT8

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ExpressionTree.h"
#include "Parse.h"

bool isCommand(std::string token);

bool isNumber(std::string token);

bool isOperator(std::string token);

void print(std::vector<std::string> const &input);

int computeExp();

void runText();

void runOutput(std::map<std::string, int> &hashTable);

void runVar(std::map<std::string, int> &hashTable);

void runSet(std::map<std::string, int> &hashTable);

void run();

#endif