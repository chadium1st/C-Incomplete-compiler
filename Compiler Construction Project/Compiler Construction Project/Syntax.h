#pragma once
#include "Globals.h"
#include <stack>
#include <string>

using namespace std;

class Syntax {
public:

    // POPULATING THE STACK:
    void stackInitializer();

    // THE LL1 PARSIING ALGORITHM:
    void LL1();

    void LL1Again(stack<string> s);

    // THE METHOD TO DISPLAY CFG, FIRST() AND FOLLOW():
    void firstFollowDisplayer();

    // NOT USEFUL, JUST FOR CHECKING WHETHER THE STACK IS GETTING POPULATED OR NOT.
    void printStack(stack<string> s);
};


