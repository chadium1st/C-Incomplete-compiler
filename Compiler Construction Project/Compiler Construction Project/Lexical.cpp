#include "Lexical.h"
#include "Globals.h"

#include <iostream>
#include <string>

using namespace std;

void Lexical::STATE00(char c) {
    if (c == '/') {
        dfa = 1;
        token = token + c;
    }
    else if (c == ' ') {
        dfa = 0;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        dfa = 5;
        token = token + c;
    }
    else if (c == '|') {
        dfa = 6;
        token = token + c;
    }
    else if (c == '&') {
        dfa = 7;
        token = token + c;
    }
    else if (c >= '0' && c <= '9') {
        dfa = 10;
        token = token + c;
    }
    else if (c == '"') {
        dfa = 12;
        token = token + c;
    }
    else if (c == ';') {
        dfa = 13;
        token = token + c;
    }
    else if (c == '\'') {
        dfa = 14;
        token = token + c;
    }
    else if (c == '?') {
        dfa = 15;
        token = token + c;
    }
    else if (c == '(') {
        dfa = 16;
        token = token + c;
    }
    else if (c == ')') {
        dfa = 17;
        token = token + c;
    }
    else if (c == '^' || c == '~') {
        dfa = 18;
        token = token + c;
    }
    else if (c == '-') {
        dfa = 20;
        token = token + c;
    }
    else if (c == '+') {
        dfa = 22;
        token = token + c;
    }
    else if (c == '<') {
        dfa = 24;
        token = token + c;
    }
    else if (c == '%' || c == '*' || c == '/' || c == '=' || c == '!') {
        dfa = 25;
        token = token + c;
    }
    else if (c == '>') {
        dfa = 26;
        token = token + c;
    }
}

void Lexical::STATE01(char c) {
    if (c == '/') {
        dfa = 2;
        token = token + c;
    }
    else if (c == '*') {
        dfa = 3;
        token = token + c;
    }
    else {
        dfa = 0;
        token = token + c;
    }
    // cout << "STATE01 DFA : " << dfa << endl;
}

void Lexical::STATE02(char c) {
    if (!(c == '\n')) {
        dfa = 2;
        token = token + c;
    }
    if (c == '\n') {
        cout << tokenType[7];
        token = token + c;
        cout << token;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE02 DFA : " << dfa << endl;
}

void Lexical::STATE03(char c) {
    if (c != '*') {
        dfa = 3;
        token = token + c;
    }
    else if (c == '*') {
        dfa = 4;
        token = token + c;
    }
    // cout << "STATE03 DFA : " << dfa << endl;
}

void Lexical::STATE04(char c) {
    if (c == '/') {
        cout << tokenType[0];
        token = token + c;
        cout << token << endl;
        // tokenArray[a][b] = tokenType[0];
        // tokenArray[a][b + 1] = token;
        // a++;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (!(c == '/')) {
        dfa = 3;
        token = token + c;
    }
    // cout << "STATE04 DFA : " << dfa << endl;
}

void Lexical::STATE05(char c) {
    bool ifKeyword = 0;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        dfa = 5;
        token = token + c;
    }
    else if (c == ' ') {
        if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {

            token = token;
            ifKeyword = 1;
        }
        else {
            ifKeyword = 0;
            //token = token + c;
        }
        if (ifKeyword) {
            cout << tokenType[1];
            cout << token << endl;
            tokenArray[a][b] = tokenType[1];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
        else if (!ifKeyword) {
            cout << tokenType[2];
            cout << token << endl;
            tokenArray[a][b] = tokenType[2];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }
    else if (c == '=') {
        if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
            ifKeyword = 1;
            token = token + c;
        }
        else {
            ifKeyword = 0;
            //token = token + c;
        }
        if (ifKeyword) {
            cout << tokenType[1];
            cout << token << endl;
            tokenArray[a][b] = tokenType[1];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
        else if (!ifKeyword) {
            cout << tokenType[2];
            cout << token << endl;
            tokenArray[a][b] = tokenType[2];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }
    else if (c == ';') {
        if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
            ifKeyword = 1;
            token = token + c;
        }
        else {
            ifKeyword = 0;
            //token = token + c;
        }
        if (ifKeyword) {
            cout << tokenType[1];
            cout << token << endl;
            tokenArray[a][b] = tokenType[1];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
        else if (!ifKeyword) {
            cout << tokenType[2];
            cout << token << endl;
            tokenArray[a][b] = tokenType[2];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }
    else if (c == '(') {
        if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
            ifKeyword = 1;
            token = token + c;
        }
        else {
            ifKeyword = 0;
            //token = token + c;
        }
        if (ifKeyword) {
            cout << tokenType[1];
            cout << token << endl;
            tokenArray[a][b] = tokenType[1];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
        else if (!ifKeyword) {
            cout << tokenType[2];
            cout << token << endl;
            tokenArray[a][b] = tokenType[2];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }
    else if (c == ')') {
        if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
            ifKeyword = 1;
            token = token + c;
        }
        else {
            ifKeyword = 0;
            //token = token + c;
        }
        if (ifKeyword) {
            cout << tokenType[1];
            cout << token << endl;
            tokenArray[a][b] = tokenType[1];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
        else if (!ifKeyword) {
            cout << tokenType[2];
            cout << token << endl;
            tokenArray[a][b] = tokenType[2];
            tokenArray[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }
    else
        dfa = 0;
    // cout << "STATE05 DFA : " << dfa << endl;
}

void Lexical::STATE06(char c) {
    if (c == '|') {
        cout << tokenType[2];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[2];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c != '|') {
        cout << "Unidentified Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == ' ') {
        cout << "Unidentified Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE06 DFA : " << dfa << endl;
}

void Lexical::STATE07(char c) {
    if (c == '&') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c != '&') {
        cout << "Unidentified Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == ' ') {
        cout << "Unidentified Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE07 DFA : " << dfa << endl;
}

void Lexical::STATE10(char c) {
    if (c >= '0' && c <= '9') {
        dfa = 10;
        token = token + c;
    }
    else if (c == '.') {
        dfa = 11;
        token = token + c;
    }
    else if (c == ' ') {
        cout << tokenType[4];
        cout << token << endl;
        tokenArray[a][b] = tokenType[4];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[4];
        cout << token << endl;
        tokenArray[a][b] = tokenType[4];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE10 DFA : " << dfa << endl;
}

void Lexical::STATE11(char c) {
    if (c >= '0' && c <= '9') {
        dfa = 11;
        token = token + c;
    }
    else if (c == ' ') {
        cout << tokenType[4];
        cout << token << endl;
        tokenArray[a][b] = tokenType[4];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == ';') {
        cout << tokenType[4];
        cout << token << endl;
        tokenArray[a][b] = tokenType[4];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[4];
        cout << token << endl;
        tokenArray[a][b] = tokenType[4];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE11 DFA : " << dfa << endl;
}

void Lexical::STATE12(char c) {
    if (c != '"') {
        dfa = 12;
        token = token + c;
    }
    else if (c == '"') {
        cout << tokenType[6];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[6];
        tokenArray[a][b + 1] = token;
        a++;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE12 DFA : " << dfa << endl;
}

void Lexical::STATE13(char c) {
    cout << tokenType[5];
    cout << token << endl;
    tokenArray[a][b] = tokenType[5];
    tokenArray[a][b + 1] = token;
    a++;
    token = "\0";
    dfa = 0;
    return;
}

void Lexical::STATE14(char c) {
    if (c != '\'') {
        dfa = 14;
        token = token + c;
    }
    else if (c == '\'') {
        cout << tokenType[8];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[8];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE14 DFA : " << dfa << endl;
}

void Lexical::STATE15(char c) {
    if (c == ':') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << "Unknown Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE15 DFA : " << dfa << endl;
}

void Lexical::STATE16(char c) {
    if (c == ';') {
        cout << "Unknown Token: ";
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[9];
        cout << token << endl;
        tokenArray[a][b] = tokenType[9];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
}

void Lexical::STATE17(char c) {
    if (c == ';') {
        cout << "Unknown Token: ";
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[9];
        cout << token << endl;
        tokenArray[a][b] = tokenType[9];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
}

void Lexical::STATE18(char c) {
    if (c == ' ') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == ';') {
        cout << "Unknown Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE15 DFA : " << dfa << endl;
}

void Lexical::STATE20(char c) {
    if (c == ';') {
        cout << "Unknown Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '-') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '=') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    // cout << "STATE20 DFA : " << dfa << endl;
}

void Lexical::STATE22(char c) {
    if (c == ';') {
        cout << "Unknown Token: ";
        token = token + c;
        cout << token << endl;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '+') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '=') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
}

void Lexical::STATE24(char c) {
    if (c == ' ') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '<') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == ';') {
        cout << "Unknown Token: ";
        token = token + c;
        cout << token << endl;
        token = "\0";
        dfa = 0;
        return;
    }
}

void Lexical::STATE25(char c) {
    if (c == ' ') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '=') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
    else {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        i--;
        token = "\0";
        dfa = 0;
        return;
    }
}

void Lexical::STATE26(char c) {
    if (c == ' ') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == '>') {
        cout << tokenType[3];
        token = token + c;
        cout << token << endl;
        tokenArray[a][b] = tokenType[3];
        tokenArray[a][b + 1] = token;
        a++;
        token = "\0";
        dfa = 0;
        return;
    }
    else if (c == ';') {
        cout << "Unknown Token: ";
        token = token + c;
        cout << token << endl;
        token = "\0";
        dfa = 0;
        return;
    }
}

void Lexical::parserMethod(string s) {
    size_t len_s = s.length();
    for (i; i < len_s; i++) {
        if (dfa == 0) /* */ STATE00(s[i]);
        else if (dfa == 1) STATE01(s[i]);
        else if (dfa == 2) STATE02(s[i]);
        else if (dfa == 3) STATE03(s[i]);
        else if (dfa == 4) STATE04(s[i]);
        else if (dfa == 5) STATE05(s[i]);
        else if (dfa == 6) STATE06(s[i]);
        else if (dfa == 7) STATE07(s[i]);
        else if (dfa == 10) STATE10(s[i]);
        else if (dfa == 11) STATE11(s[i]);
        else if (dfa == 12) STATE12(s[i]);
        else if (dfa == 13) STATE13(s[i]);
        else if (dfa == 14) STATE14(s[i]);
        else if (dfa == 15) STATE15(s[i]);
        else if (dfa == 16) STATE16(s[i]);
        else if (dfa == 17) STATE16(s[i]);
        else if (dfa == 18) STATE18(s[i]);
        else if (dfa == 20) STATE20(s[i]);
        else if (dfa == 22) STATE22(s[i]);
        else if (dfa == 24) STATE24(s[i]);
        else if (dfa == 25) STATE25(s[i]);
        else if (dfa == 26) STATE26(s[i]);
    }
}