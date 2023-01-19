#pragma once

#ifndef GLOBALS
#define GLOBALS

#include <string>
#include <stack>
#include <unordered_map>

extern std::string keywords[];
extern std::string parsingTable[18][29];
extern std::stack <std::string> _stack;
extern std::string tokenType[];
extern std::string tokenArray[48][2];
extern int dfa;
extern size_t i;
extern std::string token;
extern size_t a;
extern size_t b;

void parserPrinter();
void tokenPrinter();

#endif