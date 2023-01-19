#include "Syntax.h"
#include "Globals.h"

#include<string>
#include <iostream>
#include <stack>
#include <vector>

extern stack <string> _stack;
unordered_map<char, string> grammar;

using namespace std;

// POPULATING THE STACK:
void Syntax::stackInitializer() {

    //_stack.push("$");

    for (size_t q = 0; q < 48; q++) {
        int r = 0;
        _stack.push(tokenArray[q][r]);
    }
    string x = _stack.top();

    //cout << "THE TOP OF STACK: " << x << endl;
    //cout << "STACK LOCATION: " << &_stack << endl;
}

// THE LL1 PARSIING ALGORITHM:
void Syntax::LL1() {

    char lookAhead;
    stack<char> tempStack = {};
    //cout << "S.TOP(): :: : : : :" << _stack.top();

    string tempString = _stack.top();
    bool ifMatch = 0;

    

    if (!_stack.empty()) {

        

        for (size_t q = 0; q < 50; q++) {
            tempStack.push('$');

            for (size_t r = 0; r < tempString.length(); r++) {

                if (r != ' ')
                    tempStack.push(tempString[r]);
            }

            //the parsing table has 18 rows and 29 columns
            tempStack.pop();
        }
    }

    /*for (size_t q = 0; q < tempStack.size(); q++) {
        //printStack(tempStack);
        cout << endl;
        //cout << "TEMP STACK : : :: : ";
        char s = tempStack.top();
        cout << s;
        tempStack.pop();
    }*/

}

void Syntax::LL1Again(stack <string> s) {

}

// THE METHOD TO DISPLAY CFG, FIRST() AND FOLLOW():
void Syntax::firstFollowDisplayer() {

    cout << "The CFG (Context-Free Grammar) For The Provided Code Is: " << endl;
    cout << "Starting Symbol: S" << endl;

    grammar = {
        {'S', "D | P "},
        {'P', "cout << Q | cin >> V | C S"},
        {'Q', "String"},
        {'D', "Y I"},
        {'Y', "int | float"},
        {'I', "V G"},
        {'G', "= X | Epsilon"},
        {'C', "if (X) {S} E"},
        {'E', "else if (X) {S} E | else {S} | Epsilon"},
        {'X', "T O T"},
        {'T', "N V"},
        {'O', "A F"},
        {'A', "+ | - | * | / | % | ="},
        {'F', "> | < | == | !="},
        {'N', "number"},
        {'V', "variable R | _ R"},
        {'R', "V | number R | Epsilon"}
    };

    unordered_map<char, string> ::iterator it;
    for (it = grammar.begin(); it != grammar.end(); it++) {
        cout << it->first << " ---> " << it->second << endl;
    }

    cout << endl;
    cout << "The First() and Follow() For The Above CFG Are: " << endl;

    unordered_map<char, string> first = {
        {'S', "float, int, cout, cin, if"},
        {'P', "cout, cin"},
        {'Q', "String"},
        {'D', "int, float"},
        {'Y', "int, float"},
        {'I', "variable"},
        {'G', "=, Epsilon"},
        {'C', "if"},
        {'E', "else if, else, Epsilon"},
        {'X', "number, variable"},
        {'T', "number, variable"},
        {'O', "+, -, *, /, %, =, <, ==, !="},
        {'A', "+, -, *, /, %, ="},
        {'F', "<, ==, !="},
        {'N', "number"},
        {'V', "variable"},
        {'R', "variable, _, number, Epsilon"},
    };

    cout << endl;
    cout << "First(): " << endl;
    unordered_map<char, string> ::iterator it1;
    for (it1 = first.begin(); it1 != first.end(); it1++) {
        cout << it1->first << " = " << it1->second << endl;
    }

    unordered_map<char, string> follow = {
        {'S', "$, {"},
        {'P', "$, {"},
        {'Q', ";    "},
        {'D', "$, {"},
        {'Y', "variable, _"},
        {'I', ";"},
        {'G', "}, $"},
        {'C', "float, int, cout, cin, if"},
        {'E', "float, int, cout, cin"},
        {'X', "$, ), {"},
        {'T', "+, -, *, /, %, =, <, ==, !=, $, ), {"},
        {'O', "number, variable, _"},
        {'A', "number, variable, _"},
        {'F', "number, variable, _"},
        {'N', "+, -, *, /, %, =, <, ==, !=, $, ), {"},
        {'V', "+, -, *, /, %, =, <, ==, !=, $, ), {"},
        {'R', "+, -, *, /, %, =, <, ==, !=, $, ), {"},
    };

    cout << endl << "Follow(): " << endl;
    unordered_map<char, string> ::iterator it2;
    for (it2 = follow.begin(); it2 != follow.end(); it2++) {
        cout << it2->first << " = " << it2->second << endl;
    }

}

// NOT USEFUL, JUST FOR CHECKING WHETHER THE STACK IS GETTING POPULATED OR NOT.
void Syntax::printStack(stack<string> s) {
    if (!s.empty()) {

        string x = s.top();
        s.pop();
        printStack(s);
        cout << x << "\n";
        s.push(x);

    }
}
