#include <string>
#include <iostream>
#include <unordered_map>

#include "Globals.h"

using namespace std;

int dfa = 0;
size_t i = 0;
string token = "";
string keywords[] = { "int", "float", "cout", "cin", "if", "else", "else if" };
string tokenType[] = {

"Multi-line Comment: ", "Keyword: ", "Identifier: ", "Operator: ", "Constant: ",

"Special Character: ", "String: ", "Single-line Comment: ", "Character: ", "Special Character: "

};
string tokenArray[48][2];
string parsingTable[18][29] =
{

    {

        "", ";", "cout", "cin", "\"", "int", "float", "if", "(", ")", "{", "}", "else if", "else", "epsilon", "+", "-", "*", "/", "%", "=", ">", "<", "==", "!=", "number", "variable", "_", "$"

    },

    {

        "S", " ", "2", "2", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "P", " ", "3", "4", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "Q", " ", " ", " ", "6",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "D", " ", " ", " ", " ",  "7", "7", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "Y", " ", " ", " ", " ",  "8", "9", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "I", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "10", "10", " "

    },

    {

        "G", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", "12", " ", " ", " ", " ", " ", " ", " ", " ", "11", " ", " ", " ", " ", " ", " ", " ", "12"

    },

    {

        "C", " ", " ", " ", " ",  " ", " ", "13", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "E", " ", "16", "16", " ",  "16", "16", " ", " ", " ", " ", " ", "14", " 15", " ", " ", " ", " ", " ", " ", "11", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "X", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "17", "17", "17 ", " "

    },

    {

        "T", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "18", "19", "19", " "

    },

    {

        "O", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "20", "20", "20", "20", "20", "20", "21", "21", "21", "21", " ", " ", " ", " "

    },

    {

        "A", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "22", "23", "24", "25", "26", "27", " ", " ", " ", " ", " ", " ", " ", " "

    },

    {

        "F", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "28", "29", "30", "31", " ", " ", " ", " "

    },

    {

        "N", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "32", " ", " ", " "

    },

    {

        "V", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "28", "29", "30", "31", " ", " ", " ", " "

    },

    {

        "R", "37", " ", " ", " ",  " ", " ", " ", " ", "37", " ", "37", " ", " ", " ", "37", "37", "37", "37", "37", "37", "37", "37", "37", "37", "36", "35", "35", "37"

    }

};

size_t a = 0, b = 1;

void parserPrinter() {

    cout << "Parsing Table: " << endl;

    for (int a = 0; a < 29; a++)
        cout << parsingTable[0][a] << "|";

    cout << endl;

    for (int a = 1; a < 18; a++) {

        for (int b = 0; b < 29; b++) {

            cout << parsingTable[a][b] << "|";

        }
        cout << endl;
    }
}

void tokenPrinter() {

    for (int q = 0; q < 48; q++) {
        for (int r = 0; r < 2; r++) {
            cout << tokenArray[q][r] << "\n";
        }
    }
}